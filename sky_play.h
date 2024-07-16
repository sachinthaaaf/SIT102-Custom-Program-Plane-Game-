// Sachintha Fernando 
// BSCP|CS|62|113

#include "splashkit.h"
#include <vector> 

using namespace std;

#define PLANE_SPEED 5;
#define BOX_MOVING 3;
#define BG_SPEED 3;

enum plane_kind
{
    PLANE,
};

enum box_kind
{
    BOX,
};

struct plane_data
{
    plane_kind kind;
    double x;
    double y;
    bool prev_colid;
};

struct coin_data
{
    animation coin_animation;
    double x;
    double y;
};

struct box_data
{
    box_kind kind;
    double x;
    double y;
};

struct sky_game_data
{
    int count;
    plane_data plane;
    //box_data the_box;
    vector <coin_data>  coins;
    vector <box_data> boxs;
};


// plane Data
plane_data new_plane ();      // New plane
void draw_plane(const plane_data &plane_to_draw); //Drawing the plane
void handle_input (plane_data & plane);           //plane handling

// Collisions 
bool plane_hit_coin(const plane_data &plane, const coin_data &coin);
bool plane_hit_box(const plane_data &plane, const box_data &box);

// box Data
bitmap box_bitmap(box_kind kind);
box_data new_box ();                            // New box 
void draw_box(const box_data &box_to_draw);     // Drawing the box
box_kind random_box_kind ();                    // Generating the random boxs
void update_box(box_data &box);                 // Updating the boxs
void reset_boxs(sky_game_data &game);

//Coin data 
coin_data new_coin (double x, double y);
coin_data new_coin (); 
void draw_coin (const coin_data & coin);
void update_coin (coin_data & coin);
bool box_hit_coin(const vector<box_data> &boxs, const coin_data &coin);
void add_random_coin (sky_game_data & game); 


// New game
sky_game_data new_game ();

//Drawing the game 
void draw_game (const sky_game_data & game); 

//Updating the game
void update_game (sky_game_data & game);
