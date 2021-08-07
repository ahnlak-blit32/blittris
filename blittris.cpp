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
#include "assets.hpp"
#include "game.hpp"


/* Functions. */

using namespace blit;

Game *g_game = NULL;

/*
 * void init( void ) - called once when the game is launched.
 */
void init( void ) 
{
    /* Make sure we're in hi-res, 320x240 mode. */
    set_screen_mode( ScreenMode::hires );

    /* Load up the sprite sheet. */
    screen.sprites = SpriteSheet::load( g_asset_sprites );

    /* And initialise our font handling - the API doesn't support colour, */
    /* so this all has to be done via a spritesheet and our own code.     */


    /* For now, dive straight into the game. */
    g_game = new Game();

    /* All done. */
    return;
}


/*
 * void update( uint32_t ) - called every frame to update the world.
 *
 * uint32_t - the time in milliseconds since the epoch
 */

void update( uint32_t p_timestamp )
{
    /* For now, dive straight into the game. */
    if ( NULL != g_game )
    {
        g_game->update( p_timestamp );
    }

    /* All done. */
    return;
}


/* 
 * void render( uint32_t ) - called every frame to draw the world to the screen.
 * 
 * uint32_t - the time in milliseconds since the epoch
 */

void render( uint32_t p_timestamp )
{
    /* For now, dive straight into the game. */
    if ( NULL != g_game )
    {
        g_game->render( p_timestamp );
    }
    
    /* All done. */
    return;
}


/* End of file blittris.cpp */