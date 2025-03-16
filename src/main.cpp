#include <fmt/format.h>
#include <iostream>
#include <raylib.h>
#include <rcamera.h>

#include <utils/Resources.hpp>
#include <types/objects/resources/Image.hpp>

#define MAX_COLUMNS 20

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Amazonian Game Dev Build");
    ToggleBorderlessWindowed();

    std::cout << AmazonianUtils::getResourcePath();

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    float heights[MAX_COLUMNS] = { 0 };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = (Color){ static_cast<unsigned char>(GetRandomValue(20, 255)), static_cast<unsigned char>(GetRandomValue(10, 55)), 30, 255 };
    }

    DisableCursor();
    SetTargetFPS(144);

    Amazonian::Image* image = Amazonian::Image::init(fmt::format("{}/penis.png", AmazonianUtils::getResourcePath()), Vector2{100.f, 100.f}, Vector2{50.f, 50.f}, WHITE);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

                // Draw some cubes around
                for (int i = 0; i < MAX_COLUMNS; i++)
                {
                    DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
                    DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
                }
            EndMode3D();
            
            DrawFPS(10, 10);
            image->draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}