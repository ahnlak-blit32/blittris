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


/* Constants. */

#define TETRONIMO_4_STD   0x0001
#define TETRONIMO_4_EXT   0x0002
#define TETRONIMO_3_STD   0x0004
#define TETRONIMO_5_STD   0x0008


/* Classes. */

class Tetronimo
{

private:

public:
                  Tetronimo( uint_fast16_t );
                 ~Tetronimo( void );

};


#endif /* _TETRONIMO_HPP_ */

/* End of file tetronimo.hpp */