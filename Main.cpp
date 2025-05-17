#include <iostream>
#include <fstream>
#include "raylib.h"
#include <vector>
using namespace std;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    vector<string> map;
    ifstream Map("map.txt");
    string temp;
    const int screenWidth = 1000;
    const int screenHeight = 900;
    
    while(std::getline(Map,temp)){
        map.push_back(temp);
    }
    Map.close();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

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
            for(int i=0; i < map.size(); i++ ){
                for(int j=0; j < int(map[i].length()); j++){
                    if(char(map[i][j])==char(*("*"))){
                        DrawRectangle((j*50)+100, (i*50)+100, 50, 50, BLACK);
                    }else if((char(map[i][j])== char(*(".")))){
                        DrawRectangle((j*50)+100, (i*50)+100, 50, 50, RED);
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
