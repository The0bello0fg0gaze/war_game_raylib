#include <iostream>
#include <vector>
#include "windows.h"
#include "raylib.h"
#include "gui.h"
int main(){ //INT MAIN -------------------------------------------------------------->>
    InitWindow(1200, 800, "PvP_GAME");
    
    Camera2D camera = {0};
    camera.target = (Vector2){0};
    camera.offset = (Vector2){0};
    camera.rotation = 0.0f; 
    camera.zoom = 1.0f;
    
    MAP MAP(16,16,"Map.txt");
    MAP.SetTextMap();
    MAP.InitMap();
    
    vector<Texture2D> Sprite;
    Sprite.push_back(LoadTexture("img/SmlGrass.png"));  //0    samll grass
    Sprite.push_back(LoadTexture("img/BigGrass.png"));  //1    big grass
    Sprite.push_back(LoadTexture("img/Bush.png"));      //2    bush
    Sprite.push_back(LoadTexture("img/Rock.png"));      //3    rock
    Sprite.push_back(LoadTexture("img/Tree.png"));      //4    tree
    Sprite.push_back(LoadTexture("img/Soilder.png"));   //5    soilder
    Sprite.push_back(LoadTexture("img/Soilder2.png"));  //6    soilder 2
    Sprite.push_back(LoadTexture("img/Tank.png"));      //7    tank 
    Sprite.push_back(LoadTexture("img/Tank2.png"));     //8    tank 2
    Sprite.push_back(LoadTexture("img/Tile.png"));      //9    Tile
    Sprite.push_back(LoadTexture("img/Heart.png"));     //10   heart
    SetTargetFPS(60);
    
    while (!WindowShouldClose()){
        start(1200, 800, camera, MAP.map, Sprite);
    }
    
    for(int i=0; i<(int)Sprite.size(); i++){
        UnloadTexture(Sprite[i]);
    }
    CloseWindow();
    return 0;
}