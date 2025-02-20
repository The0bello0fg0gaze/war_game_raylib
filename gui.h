#include "raylib.h"

#ifndef Graphic_User_Interface
#define Graphic_User_Interface

void Button(float width,float height,Rectangle Rect,void (*function)()){
    DrawRectangleRec(Rect, (Color){255,255,255,255});
    if ((CheckCollisionPointRec(GetMousePosition(), Rect)) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        function();
    }
}

#endif