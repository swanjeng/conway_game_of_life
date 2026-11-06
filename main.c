#include "raylib.h"
#include <stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 50
#define TITLE "Conway's Game of Life - Raylib"

void drawGrid() {
    for (int i = 0 ; i < SCREEN_WIDTH ; i += CELL_SIZE) {
        DrawLine(i, 0, i, SCREEN_HEIGHT, BLACK);
    }
    for (int j = 0 ; j < SCREEN_HEIGHT ; j += CELL_SIZE) {
        DrawLine(0, j, SCREEN_WIDTH, j, BLACK);
    }
}

int main() {
    if (SCREEN_WIDTH % CELL_SIZE || SCREEN_HEIGHT % CELL_SIZE) {
        printf("ERROR: Window width and height should be divisible by cell size");
        return 0;
    }
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        drawGrid();
        EndDrawing();
    }
    CloseWindow();
}