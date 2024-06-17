#include "MainComponent.h"
#include <random>

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
    grid.prepare();
    
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

void MainComponent::process()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();

        handleInput();
        draw();

        EndDrawing();
    }
}

void MainComponent::draw()
{
    drawBackground();
    currentBlock.draw();
}

void MainComponent::drawBackground()
{
    ClearBackground (Colours::DarkBlue);
    grid.draw();
}

void MainComponent::handleInput()
{
    int keyPressed = GetKeyPressed();
    
    switch (keyPressed)
    {
        case KEY_LEFT:
            moveBlockLeft();
            break;
            
        case KEY_RIGHT:
            moveBlockRight();
            break;
            
        case KEY_DOWN:
            moveBlockDown();
            break;
    }
}

void MainComponent::moveBlockLeft()
{
    currentBlock.move (0, -1);
    
    if (isBlockOutside())
        currentBlock.move (0, 1);
}

void MainComponent::moveBlockRight()
{
    currentBlock.move (0, 1);
    
    if (isBlockOutside())
        currentBlock.move (0, -1);
}

void MainComponent::moveBlockDown()
{
    currentBlock.move (1, 0);
    
    if (isBlockOutside())
        currentBlock.move (-1, 0);
}

Block MainComponent::getRandomBlock()
{
    if (blocks.empty())
        blocks = getAllBlocks();
    
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase (blocks.begin() + randomIndex);
    
    return block;
}

std::vector<Block> MainComponent::getAllBlocks()
{
    return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

bool MainComponent::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    
    for (Position item : tiles)
    {
        if (grid.isCellOutside (item.getRow(), item.getColumn()))
            return true;
    }
    
    return false;
}
