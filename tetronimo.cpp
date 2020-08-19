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
 * Tetronimo::Tetronimo( uint16_t ) - creates a random new piece, based on the
 * provided bitfield. Some bits *have* to be provided, or we'll just generate
 * a silly little one-by-one thing.
 */

Tetronimo::Tetronimo( uint_fast16_t p_set )
{
  /* All done. */
  return;
}


/* 
 * Tetronimo::~Tetronimo( void ) - cleans up any allocation.
 */

Tetronimo::~Tetronimo( void )
{
  /* All done. */
  return;
}


/* End of file tetronimo.cpp */