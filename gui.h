#include "raylib.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef Graphic_User_Interface
#define Graphic_User_Interface
using namespace std;
//template to make a button in cpp
void Button(string text,Color color, Rectangle Rect, void (*function)(), int x=5, int y=5, float size=20.0f){
    size = Rect.height/2;
    const char* Ctext = text.c_str();
    DrawRectangleRec(Rect, color);
    DrawText(Ctext, (Rect.x)+x, (Rect.y)+y, size, BLACK);
    if ((CheckCollisionPointRec(GetMousePosition(), Rect)) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        DrawRectangleRec(Rect, (Color){100,100,100,255});
        function();
    }
}

vector<vector<Texture2D>> GenMapSprite(vector<vector<int>> map, vector<Texture2D> sprite){
    vector<vector<Texture2D>> result(map.size(),vector<Texture2D>(map[0].size()));
    for(int y=0; y<(int)map.size(); y++){//getting the y axis of the map
        for(int x=0; x<(int)map[0].size(); x++){//getting the x axis of the map
            int mapvar = map.at(y).at(x); 
            result.at(y).at(x) = sprite.at(mapvar);
        }
    }
    return result;
}

class MAP{// class to make the map file or to edit a text file in c
    const char* File;
    public:
    int height;
    int width;
    vector<vector<int>> map;
    
    MAP(int h, int w,string file){
        height = h;
        width = w;
        File = file.c_str();
    }
    
    
    void SetTextMap(){
        srand(time(0));
        string smap;
        for(int x=0; x<width; x++ ){
            for(int y=0; y<height; y++){
                smap += to_string(rand() % 2);
                smap += " ";
            }
            smap += "\n";
        }
        const char* Smap = smap.c_str();
        ofstream MAP(File);
        MAP << Smap;
        MAP.close();
        
    }
    
    void InitMap(){
        vector<vector<int>> result;
        string line;
        ifstream MAP(File);
        while (getline (MAP, line)) {
            vector<int> row;
            int word;
            stringstream ss(line);
            while( ss>>word){
                row.push_back(word);
            }
            result.push_back(row);
            
        }
        map = result;
        MAP.close();
    }
};

class Storage{//inventory system for the game
    private:
    vector<int*> Inventory;//each element is a pointer
    public:
    Storage(vector <int*> inventory){
        Inventory.insert( Inventory.end(), inventory.begin(), inventory.end() );
    }
    
    void put(int* item, int place){
        Inventory.at(place) = item;
    }
    
    int* get(int place){
        return Inventory.at(place);
    }
    
    int len(){
        return Inventory.size();
    }
};

#endif