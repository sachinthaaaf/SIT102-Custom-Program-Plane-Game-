// Sachintha Fernando 
// BSCP|CS|62|113

#include "splashkit.h"
#include "sky_play.h"

// Getting the bitmap associated with a given box kind 
bitmap box_bitmap (box_kind kind)
{
    switch (kind)
    {
        case BOX:
            return bitmap_named ("box");
        default:
            return nullptr;  // Return nullptr or handle the case appropriately
    }
}

// Drawing the given box on the screen
void draw_box(const box_data& box_to_draw)
{
    bitmap to_draw;
    to_draw = box_bitmap(box_to_draw.kind);
    draw_bitmap(to_draw, box_to_draw.x, box_to_draw.y);
}

// Drawing the given box on the screen
box_data new_box ()
{
    box_data result;

    result.kind = BOX;

    result.x = rnd (screen_width() ) + 700;
    result.y = rnd (screen_height() ) - 50;

    return result;
}

// Updating the position of the given box
void update_box( box_data &box)
{   
    if (box.x < -300) box = new_box ();
    else box.x -= BOX_MOVING;
}

// Removing the box at the specified index from the vector of boxes
void remove_box(vector<box_data> &boxs, int idx)
{
    boxs[idx] = boxs[boxs.size() - 1];
    boxs.pop_back();
}

// Adding new randomly positioned box to the game
void add_random_box(sky_game_data &game)
{
    game.boxs.push_back( new_box());
}