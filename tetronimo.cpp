/*
 * tetronimo.cpp - part of BlitTris, a Tetris-like game for the 32blit
 *
 * This program is released under the MIT License. See LICENSE for more details.
 *
 * Tetronimoes define a falling piece; in general there would only be one of
 * these active at a time. They can be classic (4-block, standard shape) or
 * extended in many weird and wonderful ways.
 */

/* System headers. */

/* Local headers. */

#include "blittris.hpp"
#include "tetronimo.hpp"


/* Functions. */

/*
 * Tetronimo( uint8_t ) - creates a random new piece, based on the
 * provided bitfield. Some bits *have* to be provided, or we'll just generate
 * a silly little one-by-one thing.
 */

Tetronimo::Tetronimo( uint_fast8_t p_set )
{
  /* All done. */
  return;
}


/* 
 * ~Tetronimo( void ) - cleans up any allocation.
 */

Tetronimo::~Tetronimo( void )
{
  /* All done. */
  return;
}


/*
 * void rotate( bool ) - rotates the blocks 90 degrees in the required direction;
 * this updates both the block array and the pre-rendered composite.
 */

void Tetronimo::rotate( bool p_clockwise )
{
  /* All done. */
  return;
}


/* 
 * uint_fast8_t value( void ) - returns the points value of the current piece
 */

uint_fast8_t Tetronimo::value( void )
{
  uint_fast8_t l_value = 0;

  /* The value depends on the type. */
  switch( this->m_type )
  {
    case TETRONIMO_4_SQUARE:
      l_value = 4;
      break;
    TETRONIMO_4_LONG:
      l_value = 2;
      break;
    TETRONIMO_4_ELL:
      l_value = 3;
      break;
    TETRONIMO_4_ELL_INV:
      l_value = 3;
      break;
    TETRONIMO_4_TEE:
      l_value = 1;
      break;
    TETRONIMO_4_ESS:
      l_value = 5;
      break;
    TETRONIMO_4_ESS_INV:
      l_value = 5;
      break;
    default:
      l_value = -1;
      break;
  }

  /* Return the calculated value. */
  return l_value;
}


/*
 * render( Point ) - draws the tetronimo at the location specified.
 * This location marks the rotational centre of the piece, and is in screen
 * co-ordinates.
 */

void Tetronimo::render( blit::Point p_location, float p_angle )
{
  /* All done. */
  return;
}



/* End of file tetronimo.cpp */