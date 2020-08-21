/*
 * tetronimo.hpp - part of BlitTris, a Tetris-like game for the 32blit
 *
 * This program is released under the MIT License. See LICENSE for more details.
 *
 * Tetronimoes define a falling piece; in general there would only be one of
 * these active at a time. They can be classic (4-block, standard shape) or
 * extended in many weird and wonderful ways.
 */

#ifndef   _TETRONIMO_HPP_
#define   _TETRONIMO_HPP_

#include <stdint.h>
#include "32blit.hpp"


/* Constants. */

#define TETRONIMO_3_STD   0x01
#define TETRONIMO_4_STD   0x02
#define TETRONIMO_5_STD   0x04

typedef enum 
{
  TETRONIMO_4_SQUARE,
  TETRONIMO_4_LONG,
  TETRONIMO_4_ELL,
  TETRONIMO_4_ELL_INV,
  TETRONIMO_4_TEE,
  TETRONIMO_4_ESS,
  TETRONIMO_4_ESS_INV
} tetronimo_t;


/* Classes. */

class Tetronimo
{

private:
  uint_fast8_t    m_type;
  uint_fast8_t    m_blocks[5][5];
  blit::Point     m_centre;

  void            rotate( bool );

public:
                  Tetronimo( uint_fast8_t );
                 ~Tetronimo( void );
   void           render( blit::Point, float = 0.0f );
   uint_fast8_t   value( void );

};


#endif /* _TETRONIMO_HPP_ */

/* End of file tetronimo.hpp */