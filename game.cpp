/*
 * game.cpp - part of BlitTris, a Tetris-like game for the 32blit
 *
 * This program is released under the MIT License. See LICENSE for more details.
 *
 * The Game class handles the running of the game itself; gameplay can safely
 * be suspended (in menus and suchlike) just be not called update().
 */

/* System headers. */

#include <string.h>

/* Local headers. */

#include "32blit.hpp"
#include "blittris.hpp"
#include "assets.hpp"
#include "game.hpp"


/* Functions. */

using namespace blit;


/*
 * Game::Game( void ) - creates a new Game object, setting suitable defaults.
 */

Game::Game( void )
{
  /* The board, by default, is 20x10. Different modes may result in wider. */
  this->m_board_width = 10;
  this->m_board_height = 20;
  this->reset_board();

  /* Set up static pens. */
  this->m_pen_background = Pen( 67, 36, 78 ); /* #43244a */
  return;

}

/*
 * Game::~Game( void ) - clean up any storage we've allocated. 
 */

Game::~Game( void )
{
  /* Free up the board memory, if it's been allocated. */
  if ( NULL != this->m_board )
  {
    free( this->m_board );
    this->m_board = NULL;
  }

  /* All done. */
  return;
}


/*
 * Game::reset_board( void ) - resets the board, based on the current board 
 * dimensions. We also (re)allocate the board array, and recalculate the origin.
 */

void Game::reset_board( void )
{
  /* Make sure the board array has enough allocation. */
  this->m_board = (uint_fast8_t *)realloc( this->m_board, sizeof( uint_fast8_t ) * this->m_board_width * this->m_board_height );

  /* And populate it with, well, nothing. */
  memset( this->m_board, SPRITE_BLOCK_MAX+1, this->m_board_width * this->m_board_height );

  /* We'll always vertically centre the board, at least. */
  this->m_board_origin.y = ( 240 - ( this->m_board_height * 8 ) ) / 2;

  /* Things look nicer with the board spaced in from the left by a little more. */
  this->m_board_origin.x = this->m_board_origin.y + 16;

  return;
}


/*
 * Game::board_index( row, column ) - fetches the content of the board;
 * saves me repeating the tedious calculations to work out the index!
 */

uint8_t Game::board_index( uint_fast8_t p_row, uint_fast8_t p_column )
{
  return ( p_row * this->m_board_width) + p_column;
}


/*
 * Game::get_board( row, column ) - fetches the content in a cell of the board.
 */

uint8_t Game::get_board( uint_fast8_t p_row, uint_fast8_t p_column )
{
  return this->m_board[this->board_index( p_row, p_column )];
}


/*
 * Game::set_board( row, column, value ) - sets the content of a board sell.
 */

void Game::set_board( uint_fast8_t p_row, uint_fast8_t p_column, uint_fast8_t p_value )
{
  this->m_board[this->board_index( p_row, p_column )] = p_value;
  return;
}


/*
 * void Game::update( uint32_t ) - called every frame to update the world.
 *
 * uint32_t - the time in milliseconds since the epoch
 */

void Game::update( uint32_t p_timestamp )
{
  /* Testing - fill the bottom row with some blocks. */
  this->set_board( this->m_board_height-1, 0, SPRITE_BLOCK_BASE );
  this->set_board( this->m_board_height-1, this->m_board_width-1, SPRITE_BLOCK_MAX );
  return;
}


/*
 * void Game::render( uint32_t ) - called every frame to render the world.
 *
 * uint32_t - the time in milliseconds since the epoch
 */

void Game::render( uint32_t p_timestamp )
{
  uint8_t l_row, l_col;
  uint8_t l_block;

  /* Clear the screen down to a nice background colour */
  screen.pen = this->m_pen_background;
  screen.clear();

  /* Add in the board frame. */
  for ( l_row = 0; l_row < this->m_board_height; l_row++ )
  {
    /* Draw the sides just outside the board. */
    screen.sprite( SPRITE_BOX_LEFT, 
                   this->m_board_origin + Point( -8, ( l_row * 8 ) ) );
    screen.sprite( SPRITE_BOX_RIGHT, 
                   this->m_board_origin + Point( ( this->m_board_width * 8 ), ( l_row * 8 ) ) );
  }

  /* Draw the bottom row. */
  for ( l_col = 0; l_col < this->m_board_width; l_col++ )
  {
    screen.sprite( SPRITE_BOX_BOTTOM,
                   this->m_board_origin + Point( ( l_col * 8 ), ( this->m_board_height * 8 ) ) );
  }

  /* And lastly the corners. */
  screen.sprite( SPRITE_BOX_BOTTOM_LEFT,
                   this->m_board_origin + Point( -8, ( this->m_board_height * 8 ) ) );
  screen.sprite( SPRITE_BOX_BOTTOM_RIGHT,
                   this->m_board_origin + Point( ( this->m_board_width * 8 ), ( this->m_board_height * 8 ) ) );


  /* Next, we draw the contents of the board, which excludes the current piece. */
  for ( l_row = 0; l_row < this->m_board_height; l_row++ )
  {
    for ( l_col = 0; l_col < this->m_board_width; l_col++ )
    {
      /* Fetch the block in this location. */
      l_block = this->get_board( l_row, l_col );

      /* And if it's valid, draw it. */
      if ( ( SPRITE_BLOCK_BASE <= l_block ) && ( SPRITE_BLOCK_MAX >= l_block ) )
      {
        screen.sprite( l_block, this->m_board_origin + Point( 8 * l_col, 8 * l_row ) );
      }
    }
  }


  /* All done. */
  return;
}


/* End of file game.cpp */
