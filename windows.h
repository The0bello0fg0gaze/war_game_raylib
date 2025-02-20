#include <iostream>
#include "raylib.h"
#include "gui.h"

#ifndef Windows
#define Windows
float screenWidth;
float screenHeight;
Camera2D camera;

void select_window(){
    ClearBackground(RAYWHITE);
    BeginDrawing();
    BeginMode2D(camera);
    
    
    EndMode2D();
    EndDrawing();
}

void main_menu(){
    ClearBackground(RAYWHITE);
    BeginDrawing();
    BeginMode2D(camera);
    Rectangle Play={100,100,200,200};
    
    Button(screenWidth, screenHeight, Play, &select_window);
    
    EndMode2D();
    EndDrawing();
}

void start(float ScreenWidth, float ScreenHeight, Camera2D Camera){
    screenWidth = ScreenWidth;
    screenHeight= ScreenHeight;
    camera      = Camera;
    main_menu();
}

#endif