#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Hello Raylib");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(100, 100, 200, 120, RED);
        DrawText("Raylib + C!", 150, 250, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}
