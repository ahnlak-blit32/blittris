/*
 * game.hpp - part of BlitTris, a Tetris-like game for the 32blit
 *
 * This program is released under the MIT License. See LICENSE for more details.
 *
 * The Game class handles the running of the game itself; gameplay can safely
 * be suspended (in menus and suchlike) just be not called update().
 */

#ifndef   _GAME_HPP_
#define   _GAME_HPP_

#include "32blit.hpp"


/* Constants. */


/* Classes. */

class Game
{

private:
  uint_fast8_t    m_board_width;
  uint_fast8_t    m_board_height;
  uint_fast8_t   *m_board = NULL;
  blit::Point     m_board_origin;
  blit::Pen       m_pen_background;

  void            reset_board( void );
  uint8_t         board_index( uint_fast8_t, uint_fast8_t );
  void            set_board( uint_fast8_t, uint_fast8_t, uint_fast8_t );

public:
                  Game( void );
                 ~Game( void );
  uint8_t         get_board( uint_fast8_t, uint_fast8_t );
  void            update( uint32_t );
  void            render( uint32_t );

};


#endif /* _GAME_HPP_ */


/* End of file game.hpp */
