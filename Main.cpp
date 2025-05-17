#include <iostream>
#include <fstream>
#include "raylib.h"
#include <vector>
using namespace std;
int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 900;
    
    InitWindow(screenWidth, screenHeight, "War-Game");
    
    // Initialization
    //--------------------------------------------------------------------------------------
    Image Grass1 = LoadImage("img/BigGrass.png");
    Texture2D grass1 = LoadTextureFromImage(Grass1);
    
    Image Grass2 = LoadImage("img/SmlGrass.png");
    Texture2D grass2 = LoadTextureFromImage(Grass2);
    
    vector<string> map;
    ifstream Map("map.txt");
    string temp;
    
    // Making the Back Ground
    vector<vector<int>> background;
    for(int i=0; i < 14; i++ ){
        vector<int> temp;
            for(int j=0; j < 16; j++){
                    temp.push_back((i+j)%2);
            }
        background.push_back(temp);
        }
    while(std::getline(Map,temp)){
        map.push_back(temp);
    }
    Map.close();
    
    UnloadImage(Grass1);
    UnloadImage(Grass2);


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            for(int i=0; i < 14; i++ ){
                for(int j=0; j < 16; j++){
                    if(background[i][j] == 0){
                        DrawTexture(grass1, (j*50)+100, (i*50)+100, WHITE);
                    }else if(background[i][j] == 1){
                        DrawTexture(grass2, (j*50)+100, (i*50)+100, WHITE);
                    }
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
