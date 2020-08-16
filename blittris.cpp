/*
 * blittris.cpp - part of BlitTris, a Tetris-like game for the 32blit
 *
 * This program is released under the MIT License. See LICENSE for more details.
 *
 * This file contians the main entry functions to the 32blit framework;
 * one-time initialisation, and render/update functions called every frame.
 */

/* System headers. */

/* Local headers. */

#include "32blit.hpp"
#include "blittris.hpp"


/* Functions. */

using namespace blit;

/*
 * void init( void ) - called once when the game is launched.
 */
void init( void ) 
{
    /* Make sure we're in hi-res, 320x240 mode. */
    set_screen_mode( ScreenMode::hires );

    /* Yes, I know technically a return is not required, but it feels tidier. */
    return;
}


/*
 * void update( uint32_t ) - called every frame to update the world.
 *
 * uint32_t - the time in milliseconds since the epoch
 */

void update( uint32_t p_timestamp )
{
    /* Yes, I know technically a return is not required, but it feels tidier. */
    return;
}


/* 
 * void render( uint32_t ) - called every frame to draw the world to the screen.
 * 
 * uint32_t - the time in milliseconds since the epoch
 */

void render( uint32_t time )
{
    // clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
    screen.clear();

    // draw some text at the top of the screen
    screen.alpha = 255;
    screen.mask = nullptr;
    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(0, 0, 320, 14));
    screen.pen = Pen(0, 0, 0);
    screen.text("Hello BlitTris!", minimal_font, Point(5, 4));

    /* Yes, I know technically a return is not required, but it feels tidier. */
    return;
}


/* End of file blittris.cpp */