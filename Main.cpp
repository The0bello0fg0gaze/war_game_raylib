#include <iostream>
#include <fstream>
#include "raylib.h"
#include <vector>
using namespace std;
void DrawSheet(int i, int j , int multi, int add, vector<vector<int>> background, vector<string> foreground, vector<Texture2D> sheet);
void Description(vector<string> foreground,Vector2 selected);
void ClearForeground(vector<string> &foreground, vector<vector<int>> &animationlayer);
void PlaceMovementIconsForeground(int x, int y, int size, const char current, vector<string> &foreground, vector<vector<int>> &animationlayer);
void RandomeTerrain(int x, int y, int percentage, const char val, int max, vector<string> &foreground);
int IsPlayerRed(const char val);
int IsPlayerBlue(const char val);
bool IsHeart(const char val);
bool IsObject(const char val);
bool IsTank(const char val);
bool IsInfantary(const char val);
int WinCondition(vector<string> foreground);  

bool IsTank(const char val){
    if(
        (val == '6')||
        (val == '7')
    ){return true;}
    else{return false;}
}

bool IsInfantary(const char val){
    if(
        (val == '4')||
        (val == '5')||
        (val == 'b')||
        (val == 'r')
    ){return true;}
    else{return false;}
}   

int WinCondition(vector<string> foreground){
    int countr = 0;
    int countb = 0;
    for(int i=0; i<14; i++){
        for(int j=0; j<16; j++){
            if(foreground.at(i).at(j) == 'r'){
                countr ++;
            }else if(foreground.at(i).at(j) == 'b'){
                countb ++;
            }
        }
    }
    if(countr >= 3){return 1;}
    else if(countb >= 3 ){return 0;}
    return -1;
}

int IsPlayerRed(const char val){
    if(
        (val == '4')||
        (val == '6')||
        (val == 'r')
    ){return 1;}
    else{return 0;}
}
int IsPlayerBlue(const char val){
    if(
        (val == '5')||
        (val == '7')||
        (val == 'b')
    ){return 1;}
    else{return 0;}
}   
bool IsObject(const char val){
    if(
        (val == '1')||
        (val == '2')||
        (val == '3')
    ){return true;}
    else{return false;}
}

void RandomeTerrain(int x, int y, int percentage, const char val, int max, vector<string> &foreground){
    int count = 0;
    for(int i=x; i<y; i++){
        for(int j=0; j<16; j++){
            int chance = GetRandomValue(0, 100);
            if((chance <= percentage)&&(count <= max)&&(foreground.at(i).at(j) == '0')){
                foreground.at(i).at(j) = val;
                count ++;
            }
        }
    }
}

void PlaceMovementIconsForeground(int x, int y, int size, const char current, vector<string> &foreground, vector<vector<int>> &animationlayer){
    x = x-size;
    y = y-size;
    for(int i=0; i <= size*2; i++ ){
            for(int j=0; j <= size*2; j++){
                if(((x+i)>=0)&&((y+j)>=0)&&((x+i)<14)&&((y+j)<16)){
                    const char temp = foreground.at(x+i).at(y+j);
                    
                    if(((x+i)>=0)&&((y+j)>=0)&&((x+i)<14)&&((y+j)<16)&&(temp == '0')){
                        foreground.at(x+i).at(y+j) = '8';
                        
                    }else if(((((x+i)>=0)&&((y+j)>=0)&&((x+i)<14)&&((y+j)<16)&&(!IsObject(temp)))&&(IsPlayerRed(temp) != IsPlayerRed(current)))&&(temp != '9')){ //only paint enemy red
                        animationlayer.at(x+i).at(y+j) = 1;
                        
                    }else if(temp == '9'){ //paint heart blue
                        animationlayer.at(x+i).at(y+j) = 2;
                    }
                }
            }
    }
}    
void ClearForeground(vector<string> &foreground, vector<vector<int>> &animationlayer){
    for(int i=0; i < 14; i++ ){
            for(int j=0; j < 16; j++){
                if(foreground.at(i).at(j) == '8'){
                    foreground.at(i).at(j) = '0';
                }
                if(animationlayer.at(i).at(j) == 1){
                    animationlayer.at(i).at(j) = 0;
                }else if(animationlayer.at(i).at(j) == 2){
                    animationlayer.at(i).at(j) = 0;
                }
            }
    }
}    

void DrawSheet(int i, int j , int multi, int add, vector<vector<int>> background, vector<string> foreground, vector<Texture2D> sheet){
    if(background.at(i).at(j) == 0){ // Background is being printed on screen
        DrawTexture(sheet[0], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(background.at(i).at(j) == 1){
        DrawTexture(sheet[1], (j*multi)+add, (i*multi)+add, WHITE);
    }
    
    if(foreground.at(i).at(j) == '1'){ // Foreground is being printed on screen
        DrawTexture(sheet[2], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '2'){
        DrawTexture(sheet[3], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '3'){ 
        DrawTexture(sheet[4], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '4'){
        DrawTexture(sheet[5], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '5'){
        DrawTexture(sheet[6], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '6'){
        DrawTexture(sheet[7], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '7'){
        DrawTexture(sheet[8], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == '8'){
        DrawCircle((j*multi)+add+25, (i*multi)+add+25, 5, WHITE);
    }else if(foreground.at(i).at(j) == '9'){
        DrawTexture(sheet[9], (j*multi)+add, (i*multi)+add-15, WHITE);
    }else if(foreground.at(i).at(j) == 'b'){
        DrawTexture(sheet[10], (j*multi)+add, (i*multi)+add, WHITE);
    }else if(foreground.at(i).at(j) == 'r'){
        DrawTexture(sheet[11], (j*multi)+add, (i*multi)+add, WHITE);
    }
}
void Description(vector<string> foreground,Vector2 selected){ //prints the description of the tile selected
    if(foreground.at(selected.x).at(selected.y) == '0'){
        DrawText("Grass - Nice to walk on", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '1'){
        DrawText("Bush - Believe me you can't see through it", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '2'){
        DrawText("Rock - Verrry strong rock", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '3'){
        DrawText("Tree - A verry THICK tree", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '4'){
        DrawText("Soilder Red - An unfortunate blue soule", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '5'){
        DrawText("Soilder Blue - An unfortunate red soule", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '6'){
        DrawText("Tank Red - He likes it in there", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '7'){
        DrawText("Tank Blue - He dosen't like it in there", 75, 25, 20, WHITE);
    }else if(foreground.at(selected.x).at(selected.y) == '9'){
        DrawText("Capture all the hearts to win the game", 75, 25, 20, WHITE);
    }
}
int main(void)
{   
    bool mouse = true;
    int ActionPoint = 8;
    int turn = 0;   
    int infantarydammageinfantary = 30;
    int infantarydammagetank = 10;
    int tankdammagetank = 40;
    int tankdammageinfantary = 60;
    int terrain = 20;
    Vector2 selectedprev = {0,0};
    Vector2 selected = {0,0};
    const int screenWidth = 1000;
    const int screenHeight = 900;
    vector<vector<int>> animationlayer;
    vector<vector<int>> background;
    vector<string> foreground;
    vector<Texture2D> sheet;
    Rectangle next = {775,825,200,50};
    
    InitWindow(screenWidth, screenHeight, "War-Game");
    
    // Initialization
    //--------------------------------------------------------------------------------------
    Image Grass1 = LoadImage("img/BigGrass.png");    //0
    Texture2D grass1 = LoadTextureFromImage(Grass1);
    sheet.push_back(grass1);
    
    Image Grass2 = LoadImage("img/SmlGrass.png");   //1
    Texture2D grass2 = LoadTextureFromImage(Grass2);
    sheet.push_back(grass2);
    
    Image Bush = LoadImage("img/Bush.png");         //2
    Texture2D bush = LoadTextureFromImage(Bush);
    sheet.push_back(bush);
    
    Image Rock = LoadImage("img/Rock.png");        //3
    Texture2D rock = LoadTextureFromImage(Rock);
    sheet.push_back(rock);
    
    Image Tree = LoadImage("img/Tree.png");        //4
    Texture2D tree = LoadTextureFromImage(Tree);
    sheet.push_back(tree);
    
    Image Soilder1 = LoadImage("img/Soilder.png"); //5
    Texture2D soilder1 = LoadTextureFromImage(Soilder1);
    sheet.push_back(soilder1);
    
    Image Soilder2 = LoadImage("img/Soilder2.png");//6
    Texture2D soilder2 = LoadTextureFromImage(Soilder2);
    sheet.push_back(soilder2);
    
    Image Tank1 = LoadImage("img/Tank.png");       //7
    Texture2D tank1 = LoadTextureFromImage(Tank1);
    sheet.push_back(tank1);
    
    Image Tank2 = LoadImage("img/Tank2.png");     //8
    Texture2D tank2 = LoadTextureFromImage(Tank2);
    sheet.push_back(tank2);
    
    Image Heart = LoadImage("img/Heart.png");     //9
    Texture2D heart = LoadTextureFromImage(Heart);
    sheet.push_back(heart);
    
    Image Soilder2Heart = LoadImage("img/Soilder2heart.png");     //10
    Texture2D blueheart = LoadTextureFromImage(Soilder2Heart);
    sheet.push_back(blueheart);
    
    Image SoilderHeart = LoadImage("img/Soilderheart.png");     //11
    Texture2D redheart = LoadTextureFromImage(SoilderHeart);
    sheet.push_back(redheart);
    
    ifstream Map("foreground.txt");
    string temp;
    //Making animation layer
    for(int i=0; i < 14; i++ ){
        vector<int> temp; 
            for(int j=0; j < 16; j++){
                    temp.push_back(0);
            }
        animationlayer.push_back(temp);
    }
    // Making the Background Map
    for(int i=0; i < 14; i++ ){
        vector<int> temp;
            for(int j=0; j < 16; j++){
                    temp.push_back((i+j)%2);
            }
        background.push_back(temp);
        }
        
    //Making Foreground Map    
    while(std::getline(Map,temp)){
        foreground.push_back(temp);
    }
    Map.close();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    //Randome Map Tile Genrator
    
    RandomeTerrain(2, 12, terrain, '1', 100 ,foreground); //Bush Spawn Rate
    RandomeTerrain(2, 12, terrain, '2', 100 ,foreground); //Bush Spawn Rate
    RandomeTerrain(2, 12, terrain, '3', 100 ,foreground); //Bush Spawn Rate


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if((IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
            Vector2 temp = GetMousePosition();
            if(((temp.x-100)>0)&&((temp.y-100)>0)){
                int sth = temp.x;
                temp.x = (int(temp.y-100)/50);
                temp.y = (int(sth-100)/50);
                if((temp.x<14)&&(temp.x>=0)&&(temp.y<16)&&(temp.y>=0)){
                    selectedprev = selected;
                    selected =temp;
                    //cout << selected.x<< "-" << selected.y<< endl;
                }
            }
            
        int IsInRange = animationlayer.at(selected.x).at(selected.y);
        const char current = foreground.at(selected.x).at(selected.y);
        const char previous = foreground.at(selectedprev.x).at(selectedprev.y);
        
        if((ActionPoint > 0)&&((turn%2 != IsPlayerBlue(current))||(mouse))){ 
        //Movement of the Tiles 
        //--------------------------------------------------------------------------------- 
            if(IsInfantary(current)){ //infantary grid pattern
                ClearForeground(foreground, animationlayer);
                PlaceMovementIconsForeground(selected.x ,selected.y ,2 ,current ,foreground, animationlayer);
                
            }else if(IsTank(current)){ //tank grid pattern

                ClearForeground(foreground, animationlayer);
                PlaceMovementIconsForeground(selected.x ,selected.y ,4 ,current ,foreground, animationlayer);
                
            }else if(((current == '8')||(IsInRange == 2))&&(!IsObject(current))){ // move the selected peice to new location

                ClearForeground(foreground, animationlayer);
                if((current == '9')&&(previous == '5')){ // blue capture heart
                    ActionPoint --;
                    foreground.at(selected.x).at(selected.y) = 'b';
                    foreground.at(selectedprev.x).at(selectedprev.y) = '0';
                    
                }else if((current == '9')&&(previous == '4')){ // read capture heart
                    ActionPoint --;
                    foreground.at(selected.x).at(selected.y) = 'r';
                    foreground.at(selectedprev.x).at(selectedprev.y) = '0';
                    
                }else if((current == '8')){ //Normal Movements
                    
                    ActionPoint --;
                    foreground.at(selected.x).at(selected.y) = foreground.at(selectedprev.x).at(selectedprev.y);
                    foreground.at(selectedprev.x).at(selectedprev.y) = '0';
                }
            }else if((IsObject(current))||(current == '0')||(current == '9')){ // clear screen when click on ground

                ClearForeground(foreground, animationlayer);
                
            }
        //--------Hit Detector
            if((IsPlayerRed(current) != IsPlayerRed(previous))&&(IsInRange == 1)&&(IsInfantary(current)&&(IsInfantary(previous)))){ // inf hits  inf
                ClearForeground(foreground, animationlayer);
                ActionPoint --;
                int hit = GetRandomValue(0, 100);
                if(hit <= infantarydammageinfantary){
                    if((current == 'r')||(current == 'b')){
                        foreground.at(selected.x).at(selected.y) = '9';
                    }else{
                        foreground.at(selected.x).at(selected.y) = '0';
                    }
                }
            }else if((IsPlayerRed(current) != IsPlayerRed(previous))&&(IsInRange == 1)&&(IsTank(current)&&(IsTank(previous)))){ // inf hits  inf
                ClearForeground(foreground, animationlayer);
                ActionPoint --;
                int hit = GetRandomValue(0, 100);
                if(hit <= tankdammagetank){
                    foreground.at(selected.x).at(selected.y) = '0';
                }
            }else if((IsPlayerRed(current) != IsPlayerRed(previous))&&(IsInRange == 1)&&(IsTank(current)&&(IsInfantary(previous)))){ // inf hits  inf
                ClearForeground(foreground, animationlayer);
                ActionPoint --;
                int hit = GetRandomValue(0, 100);
                if(hit <= infantarydammagetank){
                    foreground.at(selected.x).at(selected.y) = '0';
                }
            }else if((IsPlayerRed(current) != IsPlayerRed(previous))&&(IsInRange == 1)&&(IsInfantary(current)&&(IsTank(previous)))){ // inf hits  inf
                ClearForeground(foreground, animationlayer);
                ActionPoint --;
                int hit = GetRandomValue(0, 100);
                if(hit <= tankdammageinfantary){
                    if((current == 'r')||(current == 'b')){
                        foreground.at(selected.x).at(selected.y) = '9';
                    }else{
                        foreground.at(selected.x).at(selected.y) = '0';
                    }
                }
            }
        }
        cout << mouse << endl;
        if(turn%2 != (IsPlayerBlue(current)&&!IsObject(current))){ mouse = true;}
        else{ mouse = false;}
        }
        //----------------------------------------------------------------------------------
        if (CheckCollisionPointRec(GetMousePosition(), next))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                turn ++;
                ActionPoint = 8;
                ClearForeground(foreground, animationlayer);
            }
            
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            //Selected tile is being shown on the screen.
            DrawSheet(selected.x, selected.y, 0, 10, background, foreground, sheet);
            Description(foreground, selected);
            
            DrawRectangleRounded(next, 0.5, 25, WHITE); 
            DrawText("PASS", next.x+60, next.y+10, 30, BLACK);
            DrawText(TextFormat("Turn Number :- %i", turn), next.x-450, next.y+10, 30, WHITE);
            DrawText(TextFormat("Action Points Left :- %i", ActionPoint), next.x-250, 50, 30, WHITE);
            
            if(turn%2 == 1){
                DrawText("RED", next.x-700, next.y+10, 30, RED);
            }else{
                DrawText("BLUE", next.x-700, next.y+10, 30, BLUE);
            }
            
            //Draw the Background and Foreground
            for(int i=0; i < 14; i++ ){
                for(int j=0; j < 16; j++){
                    DrawSheet(i, j, 50, 100, background, foreground, sheet);
                    
                    if(animationlayer.at(i).at(j) == 1){
                        DrawCircle((j*50)+100+25, (i*50)+100+25, 5, RED);
                    }if(animationlayer.at(i).at(j) == 2){
                        DrawCircle((j*50)+100+25, (i*50)+100+25, 5, BLUE);
                    }
                }

            }
            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Unloading the Texture2D
    UnloadImage(Grass1); //background 0
    UnloadImage(Grass2); //background 1
    
    UnloadImage(Bush); //foreground 1
    UnloadImage(Rock); //foreground 2
    UnloadImage(Tree); //foreground 3
    UnloadImage(Soilder1); //foreground 4
    UnloadImage(Soilder2); //foreground 5
    UnloadImage(Tank1); //foreground 6
    UnloadImage(Tank2); //foreground 7
    UnloadImage(Heart); //foreground 9
    UnloadImage(Soilder2Heart); //foreground 14
    UnloadImage(SoilderHeart); //foreground 15
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
