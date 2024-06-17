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
    
    if (eventTriggered(0.2))
        moveBlockDown();
    
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
            
        case KEY_UP:
            rotateBlock();
            break;
    }
}

void MainComponent::moveBlockLeft()
{
    currentBlock.move (0, -1);
    
    if (isBlockOutside() || !blockFits())
        currentBlock.move (0, 1);
}

void MainComponent::moveBlockRight()
{
    currentBlock.move (0, 1);
    
    if (isBlockOutside() || !blockFits())
        currentBlock.move (0, -1);
}

void MainComponent::moveBlockDown()
{
    currentBlock.move (1, 0);
    
    if (isBlockOutside() || !blockFits())
    {
        currentBlock.move (-1, 0);
        lockBlock();
    }
}

void MainComponent::rotateBlock()
{
    currentBlock.rotate();
    
    if (isBlockOutside() || !blockFits())
        currentBlock.undoRotation();
}

void MainComponent::lockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    
    for (Position item : tiles)
        grid.getGrid()[item.getRow()][item.getColumn()] = currentBlock.getId();
    
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
}

bool MainComponent::blockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    
    for (Position item : tiles)
    {
        if (!grid.isCellEmpty(item.getRow(), item.getColumn()))
            return false;
    }
    
    return true;
}

Block MainComponent::getRandomBlock()
{
    if (blocks.empty())
        blocks = getAllBlocks();
    
    std::random_device os_seed;
    const uint_least32_t seed = os_seed();
    
    std::mt19937 generator (seed);
    std::uniform_int_distribution< uint_least32_t > distribute (0, (int) (blocks.size() - 1));
    
    int randomIndex = distribute (generator);
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
