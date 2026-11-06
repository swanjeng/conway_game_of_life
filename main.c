#include "raylib.h"
#include <stdio.h>
#include <time.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 50
#define ARRAY_ROWS (SCREEN_HEIGHT / CELL_SIZE)
#define ARRAY_COLS (SCREEN_WIDTH / CELL_SIZE)
#define TITLE "Conway's Game of Life - Raylib"

int cells[ARRAY_ROWS][ARRAY_COLS] = {};
int cells1[ARRAY_ROWS][ARRAY_COLS] = {};

void drawGrid() {
    for (int i = 0; i < SCREEN_WIDTH; i += CELL_SIZE) {
        DrawLine(i, 0, i, SCREEN_HEIGHT, BLACK);
    }
    for (int j = 0; j < SCREEN_HEIGHT; j += CELL_SIZE) {
        DrawLine(0, j, SCREEN_WIDTH, j, BLACK);
    }
}

void initCells() {
    for (int i = 0; i < ARRAY_ROWS; i++) {
        for (int j = 0; j < ARRAY_COLS; j++) {
            if (GetRandomValue(1, 3) == 1) cells[i][j] = 1;
        }
    }
}

int countNeighbor(int i, int j) {
    int cnt = 0;
    if (i > 0 && j > 0) cnt += cells[i - 1][j - 1];
    if (i > 0) cnt += cells[i - 1][j];
    if (j > 0) cnt += cells[i][j - 1];
    if (i < ARRAY_ROWS - 1 && j < ARRAY_COLS - 1) cnt += cells[i + 1][j + 1];
    if (i < ARRAY_ROWS - 1) cnt += cells[i + 1][j];
    if (j < ARRAY_COLS - 1) cnt += cells[i][j + 1];
    if (i > 0 && j < ARRAY_COLS - 1) cnt += cells[i - 1][j + 1];
    if (i < ARRAY_ROWS - 1 && j > 0) cnt += cells[i + 1][j - 1];
    return cnt;
}

void updateCells() {
    for (int i = 0; i < ARRAY_ROWS; i++) {
        for (int j = 0; j < ARRAY_COLS; j++) {
            int neighbors = countNeighbor(i, j);
            if ((cells[i][j] && (neighbors == 2 || neighbors == 3)) || (!cells[i][j] && neighbors == 3)) cells1[i][j] = 1;
            else cells1[i][j] = 0;
        }
    }
    for (int i = 0; i < ARRAY_ROWS; i++) {
        for (int j = 0; j < ARRAY_COLS; j++) {
            cells[i][j] = cells1[i][j];
        }
    }
}

void drawCells() {
    for (int i = 0; i < ARRAY_ROWS; i++) {
        for (int j = 0; j < ARRAY_COLS; j++) {
            DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, (cells[i][j] ? BLACK : WHITE));
        }
    }
}

int main() {
    if (SCREEN_WIDTH % CELL_SIZE || SCREEN_HEIGHT % CELL_SIZE) {
        printf("ERROR: Window width and height should be divisible by cell size");
        return 0;
    }
    int frameCounter = 0;
    SetRandomSeed(time(NULL));
    initCells();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        frameCounter++;
        if (frameCounter == 12) {
            updateCells();
            frameCounter = 0;
        }
        BeginDrawing();
        ClearBackground(WHITE);
        drawCells();
        drawGrid();
        EndDrawing();

    }
    CloseWindow();
}