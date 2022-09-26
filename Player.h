#include <gb/gb.h>

#include "player_static.h"

joypads_t joypads;

//Sprite Coordinates
UINT16 PosX, PosY, PosX2;
INT16 SpdX, SpdY;
UINT8 Jump;

UINT8 Grv = 15;


BOOLEAN onGrnd;


void drawPlayer(){
    //init color palettes
    BGP_REG = OBP0_REG = OBP1_REG = 0xE4;

    //load tile data into Vram
    set_sprite_data(0, 4, Slimey);

    //set sprite tiles
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    

    //set player position and jump speed
    PosX = PosY = 144 << 4;
    PosX2 = PosX + 144 + 8 << 4;
    Jump = SpdX = SpdY = 0;

    move_sprite(0, 84, 144);
    move_sprite(1, 84 + 8, 144);

   
}

void movePlayer(){
    //poll joypads
    joypad_ex(&joypads);

    //check inputs
    if(joypads.joy0 & J_LEFT){
        SpdX -= 3;
        if(SpdX < -32){
            SpdX = -32;
        }
    }else if(joypads.joy0 & J_RIGHT){
        SpdX += 3;
        if(SpdX > 32){
            SpdX = 32;
        }
    }

    if(joypads.joy0 & J_A){
        Jump = 3;
    }

    //Jump
    if(Jump){
        SpdY -= 8;
        if(SpdY < -32){
            SpdY = -32;
        }

        Jump--;
    }

    

    //accelerate
    PosX += SpdX, PosY += SpdY, PosX2 += SpdX;

    move_sprite(0, PosX >> 4, PosY >> 4);
    move_sprite(1, PosX2 >> 4, PosY >> 4);

    // decelerate 
    if (SpdY >= 0) {
        if (SpdY) SpdY--; 
    } else SpdY ++;

    if (SpdX >= 0) {
        if (SpdX) SpdX--; 
    } else SpdX ++;
}



void applyGravity(){

    //accelerate downwards each frame
    SpdY = SpdY + Grv;
    PosY = PosY + SpdY;


}

void checkCollision(){
    if(PosY > 140){
        PosY = 140; 

    }
}

void Activatejoypad(){
    joypad_init(1, &joypads);
}