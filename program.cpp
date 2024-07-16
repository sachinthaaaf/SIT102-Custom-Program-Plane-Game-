// Sachintha Fernando 
// BSCP|CS|62|113

#include "splashkit.h"
#include "sky_play.h"



using namespace std;

/**
 * Load the resources associated with the Planet Play game
 */
void load_resources ()
{
    load_resource_bundle ("game_bundle", "plane_play.txt");

}

int main()
{
    // Opening the window
    open_window ("Plane Play by Sachintha", 900, 675);

    // Loading the Resources
    load_resources ();

    bitmap sky = load_bitmap("BG", "BG.png");
    double bgX = 0;

    sky_game_data game;
    game = new_game ();
 
  
    while ( not quit_requested() )
    {
        process_events();
        handle_input (game.plane);

        update_game (game); 

        // Update the position of the background
        bgX -= BG_SPEED;

        // Reset the position if the background moves off the screen
        if (bgX <= -bitmap_width(sky))
        {
            bgX = 0;
        }

        // Clear the screen
        clear_screen(COLOR_WHITE);

        // Draw the background at the updated position
        draw_bitmap(sky, bgX, 0);
        draw_bitmap(sky, bgX + bitmap_width(sky), 0);  // Draw a second copy for seamless scrolling

        draw_game (game);
 
        refresh_screen ();
    } 

    return 0;
}