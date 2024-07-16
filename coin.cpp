// Sachintha Fernando 
// BSCP|CS|62|113

#include "sky_play.h"
#include "splashkit.h"

// Creating a new coin with the specified position
coin_data new_coin (double x, double y)
{
    coin_data result; 

    result.x = x;
    result.y = y;
    result.coin_animation = create_animation ("coins", "spin");

    return result; 
}

// Creating a new coin with random position 
coin_data new_coin ()
{
    bitmap coin_bmp = bitmap_named ("gold_coin");
    return new_coin (rnd (screen_width () - bitmap_width (coin_bmp)), rnd (screen_height () - bitmap_height (coin_bmp)));
}

// Adding a random coin to the game
void add_random_coin (sky_game_data & game)
{
    game.coins.push_back (new_coin ()); 
}

// Drawing a coin on the screen
void draw_coin (const coin_data & coin)
{
    draw_bitmap ("gold_coin", coin.x , coin.y, option_with_animation (coin.coin_animation) ); 
}

// Updating the animation of a coin
void update_coin (coin_data & coin)
{
    update_animation (coin.coin_animation);
}

// Checking if a box collides with a coin
bool box_hit_coin (const vector<box_data> &boxs, const coin_data &coin)
{
    bitmap coin_bmp = bitmap_named ("gold_coin");
    int coin_cell = animation_current_cell (coin.coin_animation);
    
    for (int i=0; i < boxs.size(); i++)
    {
        bitmap box_bmp = box_bitmap (boxs[i].kind);

        if (bitmap_collision (coin_bmp, coin_cell, coin.x, coin.y,
        box_bmp, 0, boxs[i].x, boxs[i].y))
        {
            return true;
        }
    }
    return false;
}