#include "MainComponent.h"

MainComponent::MainComponent()
{
    InitWindow (Sizes::WIDTH, Sizes::HEIGHT, "Tetris Game!");
    SetTargetFPS (60);

    prepare();
    process();
}

MainComponent::~MainComponent()
{
    CloseWindow();
}

void MainComponent::prepare()
{
}

void MainComponent::process()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        draw();

        EndDrawing();
    }
}

void MainComponent::draw()
{
    drawBackground();
}

void MainComponent::drawBackground()
{
    ClearBackground (Colours::DarkBlue);
}
