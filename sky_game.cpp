// Sachintha Fernando 
// BSCP|CS|62|113

#include "splashkit.h"
#include "sky_play.h"

// Create a new game with initial data and return it
sky_game_data new_game ()
{
    sky_game_data result;

    result.plane = new_plane ();

    reset_boxs (result);
    
    add_random_coin (result);

    result.count = 0;

    return result; 
}

// Drawing the game elements on to the screen
void draw_game (const sky_game_data & game)
{
    for (int i = 0; i < game.coins.size(); i++)
    {
        draw_coin (game.coins[i]); 
    }
    
    for (int i = 0; i < game.boxs.size(); i++)
    {
        draw_box (game.boxs[i]); 
    }

    draw_plane (game.plane);

    draw_text ("Score: " + to_string (game.count), COLOR_BLACK, 20, 10);

    refresh_screen (30);
}

// Removing coins from the game's vector of coins
void remove_coin (vector<coin_data> & coins, int idx)
{
    free_animation (coins[idx].coin_animation);

    coins[idx] = coins [coins.size() - 1 ];
    coins.pop_back ();
}

// Updating the positions and states of all the coins in the game
void update_coins (sky_game_data &game)
{
    vector<int> to_remove; 
    for (int i=0; i < game.coins.size (); i++)
    {
        update_coin (game.coins[i]); 
        if (box_hit_coin(game.boxs, game.coins[i]))
        {
            to_remove.push_back(i);
        }
        else if (plane_hit_coin (game.plane, game.coins[i]))
        {
            to_remove.push_back(i);
            game.count++;
        }
    }

    for (int i = to_remove.size () - 1; i >= 0; i--)
    {
        remove_coin (game.coins, to_remove[i]);
    }
}

// Updating the positions and states of all the boxes in the game
void update_boxs (sky_game_data &game)
{
    bool off_screen;
    bool currently_colidng;

    for (int i=0; i < game.boxs.size (); i++)
    {
        if (plane_hit_box (game.plane, game.boxs[i]))
        {
            if (game.count > 0)  game.count--;
            currently_colidng = true;
        }
    }

    if (currently_colidng and not game.plane.prev_colid)
    {
        play_sound_effect("crash");
        game.plane.prev_colid = true;
    }

    else if (not currently_colidng) 
        game.plane.prev_colid = false;

    for (int i=0; i < game.boxs.size(); i++)
    {
        update_box (game.boxs[i]);
    }

    off_screen = true;

    for (int i=0; i < game.boxs.size (); i++)
    {
        if (game.boxs[i].x >= -300) off_screen = false;
    }

    if (off_screen) reset_boxs (game);

}

// Reseting the boxes in the game to new random positions
void reset_boxs (sky_game_data &game)
{
    vector<box_data> result;
    int count;
    count = rnd (1, 3);
    for (int i=0; i < count; i++)
    {
        result.push_back (new_box ());
    }
    
    game.boxs = result;
}

// Update the overall game state
void update_game (sky_game_data & game)
{
    handle_input (game.plane);
    update_boxs (game);
    update_coins (game);
     
    if (rnd () < 0.03)
        add_random_coin (game);
}

