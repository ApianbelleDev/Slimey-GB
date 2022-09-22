#include <gb/gb.h>

#include "player_static.h"

UINT8 player[2];

void drawPlayer(){

    player[0] = 84;
    player[1] = 144;
    //Load the slimey sprite into VRAM
    set_sprite_data(0, 4, TileLabel);

    //Draw the first half slimey
    set_sprite_tile(0, 0);
    move_sprite(0, player[0], player[1]);

    //Draw the second half slimey
    set_sprite_tile(1, 3);
    move_sprite(1, player[0] + 8, player[1]);
}

void movePlayer(){
     if(joypad() & J_LEFT){
        player[0]--;
    }

    if(joypad() & J_RIGHT){
         player[0]++;
    }

    move_sprite(0, player[0], player[1]);
    move_sprite(1, player[0] + 8, player[1]);

   
}

void wrapScreen(){
     if(player[0] > 160){
        player[0] = 1;
    }
    
    if(player[0] < 1){
        player[0] = 160;
    }
}