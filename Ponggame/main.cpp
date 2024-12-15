#include <iostream>
#include <raylib.h>


int main () {
    const int screen_width = 1280;
    const int screen_height = 800;
    const char* titile = "Pong Game made by TXN";
    InitWindow(screen_width, screen_height, titile);
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}