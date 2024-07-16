// Sachintha Fernando 
// BSCP|CS|62|113

#include "splashkit.h"
#include "sky_play.h"

using namespace std;
 
// Getting the bitmap associated with a given plane kind
bitmap plane_bitmap (plane_kind kind)
{
    switch (kind)
    {
        case PLANE:
            return bitmap_named ("plane");
        default:
            return nullptr;  // Return nullptr or handle the case appropriately
    }
}

// Drawing the plane on the screen
void draw_plane (const plane_data & plane_to_draw)
{
    bitmap to_draw;
    to_draw = plane_bitmap (plane_to_draw.kind);
    draw_bitmap (to_draw, plane_to_draw.x, plane_to_draw.y);

}

// Handles user input to move the plane
void handle_input (plane_data & plane)
{
    if ( key_down (RIGHT_KEY) )  plane.x += PLANE_SPEED; 
    if ( key_down (LEFT_KEY) ) plane.x -= PLANE_SPEED;
    if ( key_down (UP_KEY) ) plane.y -= PLANE_SPEED;
    if ( key_down (DOWN_KEY) )  plane.y += PLANE_SPEED;
 
}

// Creating a new plane with default position and kind
plane_data new_plane ()
{
    plane_data result;

    result.kind = PLANE;
    result.x = 100;
    result.y = 100;

    return result;
}
 
// Checking if the plane collides with a coin
bool plane_hit_coin (const plane_data & plane, const coin_data & coin)
{
    bitmap coin_bmp = bitmap_named ("gold_coin");
    int coin_cell = animation_current_cell (coin.coin_animation);

    bitmap plane_bmp = plane_bitmap (plane.kind);

    return bitmap_collision (
        coin_bmp, coin_cell, coin.x, coin.y,
        plane_bmp, 0, plane.x, plane.y);
}

// Checking if the plane collides with a coin
bool plane_hit_box (const plane_data& player, const box_data& box)
{
    bitmap plane_bmp = plane_bitmap (player.kind);
    bitmap box_bmp = box_bitmap (box.kind);

    return bitmap_collision (
        plane_bmp, player.x, player.y,
        box_bmp, box.x, box.y);
}