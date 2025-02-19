#include <stdio.h>
#include <raylib.h>
int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Pomodoro");

    SetExitKey(KEY_NULL);

    bool exitWindowRequested = false;
    bool exitWindow = false;
    bool pomodoroStart = false;
    SetTargetFPS(60);
    Rectangle buttonYes = {100,150,200,100};
    Rectangle buttonNo = {500, 150, 200, 100};
    Rectangle buttonStart = {screenWidth/2 -  screenWidth/5 + 50,screenHeight/2 - 100, 200, 100};



 //   int btnState = 0;
//    bool btnAction = false;
    Vector2 mousePoint = {0.0f, 0.0f};
    int minutes = 1;
    int seconds = 60;
    int count = minutes * seconds;
    while (!exitWindow){
        mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, buttonStart)) {
            minutes = 20;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && count != 0) pomodoroStart = true;
        }
        while (pomodoroStart) {
            count -= 1;
        }
        // Detects if window closed button has been pressed
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;
        // Functionality inside our Drawing exitWindowRequested
        if (exitWindowRequested) {
            if (CheckCollisionPointRec(mousePoint,buttonYes)){
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) exitWindow = true;
            }
            if (CheckCollisionPointRec(mousePoint,buttonNo)){
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) exitWindowRequested = false;
            }
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }


        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (exitWindowRequested){
                DrawRectangle(0,100, screenWidth, 200, GRAY);
                DrawText("Are you sure you want to exit Pomodoro? [Y/N]", 40, 100, 30, BLACK);
                DrawRectangleRec(buttonYes, RED);
                DrawRectangleLinesEx(buttonYes, 5, BLACK);
                DrawText("YES", buttonYes.x * 2 - 30, 180, 30, BLACK);

                DrawRectangleRec(buttonNo, GREEN);
                DrawRectangleLinesEx(buttonNo, 5, BLACK);
                DrawText("NO", buttonNo.x + buttonNo.width/2 - 20, 180, 30, BLACK);

            } else if (pomodoroStart){
               DrawText(TextFormat("Remaining Time: %d", count), 10, 30 ,20, BLACK);

            } else {
               DrawRectangleRec(buttonStart, GRAY);
               DrawRectangleLinesEx(buttonStart, 5, BLACK);
             }
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
