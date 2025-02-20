#include <iostream>
#include <vector>
#include "windows.h"
#include "raylib.h"
int main(){ //INT MAIN -------------------------------------------------------------->>
    InitWindow(1200, 800, "PvP_GAME");
    
    Camera2D camera = { 0 };
    camera.target = (Vector2){0};
    camera.offset = (Vector2){600.0f,400.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    while (!WindowShouldClose()){
        start(1200, 800, camera);
    }
    CloseWindow();
    return 0;
}