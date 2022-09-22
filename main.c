#include <stdio.h>
#include <gb/gb.h>

#include "Player.h"

void init();
void checkInput();
void updateSwitches();

UINT8 player[2];

void main(){

    init();

    while(1){
        checkInput();
        updateSwitches();
        wait_vbl_done(); //Wait until VBLANK to avoid graphic corruption
    }

   
}

void init(){
    DISPLAY_ON;
    drawPlayer();
}

void updateSwitches(){
    HIDE_WIN;
    SHOW_SPRITES;
    SPRITES_8x16;
}

void checkInput(){
    movePlayer();
    wrapScreen();
}