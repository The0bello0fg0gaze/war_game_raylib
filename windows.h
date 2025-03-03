#include <iostream>
#include <vector>
#include "raylib.h"
#include "gui.h"

#ifndef Windows
#define Windows

void start(float ScreenWidth, float ScreenHeight, Camera2D Camera);
void custom_window();
void Exit_window();
void play_window();
void main_menu();
void mouse_brush(int i, int MouseBrush);

vector<vector<Texture2D>> MapSprite;
vector<vector<int>> Map;
vector<Texture2D> Sprite;
float screenWidth;
float screenHeight;
int screen=1;
Camera2D camera;

void mouse_brush(){
    
}

void Exit_window(){
    CloseWindow();
}

void play_window(){
    screen = 3;
    ClearBackground(RAYWHITE);
    BeginDrawing();
    Rectangle Exit={10,10,100,50};//exit window
    Button("EXIT",(Color){200,200,200,255}, Exit, &Exit_window, 20, 12);
    Rectangle Back={125,10,100,50};//main window
    Button("BACK",(Color){200,200,200,255}, Back, &main_menu, 20, 12);
    BeginMode2D(camera);
    int mapx = Map[0].size();
    int mapy = Map.size();
    for(int y=0; y<mapx; y++){//getting the y axis of the map
        for(int x=0; x<mapy; x++){//getting the x axis of the map
            DrawTexture(MapSprite[y][x], (x*38)+((screenWidth/2)-(mapx/2)*37), (y*38)+((screenHeight/2)-(mapy/2)*37), WHITE);//print the tile from the MapSprite
        }
    }
    EndMode2D();
    EndDrawing();
}

void custom_window(){
    screen = 2;
    int MouseBrush = 0;
    ClearBackground(RAYWHITE);
    BeginDrawing();
    Rectangle Exit={10,10,100,50};//exit window
    Button("EXIT",(Color){200,200,200,255}, Exit, &Exit_window, 20, 12);
    Rectangle Back={125,10,100,50};//main window
    Button("BACK",(Color){200,200,200,255}, Back, &main_menu, 20, 12);
    DrawText((const char *)&MouseBrush, 250, 10, 60, BLACK);
    BeginMode2D(camera);
    int mapx = Map[0].size();
    int mapy = Map.size();
    // drawing the map on the screen.
    for(int y=0; y<mapx; y++){//getting the y axis of the map
        for(int x=0; x<mapy; x++){//getting the x axis of the map
            DrawTexture(MapSprite[y][x], (x*38)+((screenWidth/3)-(mapx/2)*37), (y*38)+((screenHeight/2)-(mapy/2)*37), WHITE);//print the tile from the MapSprite
        }
    }
    //drawing the texture buttons on the screen
    DrawRectangleRec((Rectangle){screenWidth-60,0,60,screenHeight}, (Color){200,200,200,255});
    int SpriteSize = Sprite.size();
    for(int i=0; i<(SpriteSize-2); i++){
        DrawTexture(Sprite[i],screenWidth-50,(float)((screenHeight/20)+(i*60)),WHITE);
        Button("", (Color) {0,0,0,0}, (Rectangle) {screenWidth-50,(float)((screenHeight/20)+(i*60)),40,40}, &mouse_brush);
        
    }
    EndMode2D();
    EndDrawing(); 
}

void main_menu(){
    screen = 1;
    ClearBackground(RAYWHITE);
    BeginDrawing();
    //play button
    Rectangle Play={510,300,120,50};
    Button("PLAY",(Color){200,200,200,255}, Play, &play_window,27,12);
    //custom unit select window..
    Rectangle custom={510,400,120,50};
    Button("SEX",(Color){200,200,200,255}, custom, &custom_window,7,12);
    //exit button
    Rectangle Exit={510,500,120,50};
    Button("EXIT",(Color){200,200,200,255}, Exit, &Exit_window,27,12);
    EndDrawing();
}

void start(float ScreenWidth, float ScreenHeight, Camera2D Camera, vector<vector<int>> map, vector<Texture2D> sprite){//main start point init all the values  will run in a loop
    screenWidth  = ScreenWidth;
    screenHeight = ScreenHeight;
    camera       = Camera;
    Map          = map;
    Sprite       = sprite;
    MapSprite    = GenMapSprite(Map, Sprite);
    //select  screen to hop to
    if(screen == 1){main_menu();}
    else if(screen == 2){custom_window();}
    else if(screen == 3){play_window();}
    else{std::cout<<"screen was given wrong:-"<<screen<<std::endl;CloseWindow();}
}

#endif