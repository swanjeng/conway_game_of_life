#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "Conway's Game of Life - Raylib"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
}