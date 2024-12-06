#include "MainComponent.h"

MainComponent::MainComponent()
{
    InitWindow (Sizes::WIDTH, Sizes::HEIGHT, "Tetris Game!");
    SetTargetFPS (60);

    InitAudioDevice();

    prepare();
    process();
}

MainComponent::~MainComponent()
{
    CloseWindow();

    UnloadMusicStream (music);
    UnloadSound (rotateSound);
    UnloadSound (clearSound);
    CloseAudioDevice();
}

void MainComponent::prepare()
{
    grid.prepare();

    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();

    font = LoadFontEx ("../../Font/monogram.ttf", 64, 0, 0);

    music = LoadMusicStream ("../../Sounds/music.mp3");
    PlayMusicStream (music);

    rotateSound = LoadSound ("../../Sounds/rotate.mp3");
    clearSound = LoadSound ("../../Sounds/clear.mp3");
}

void MainComponent::process()
{
    while (!WindowShouldClose())
    {
        UpdateMusicStream (music);

        BeginDrawing();

        handleInput();
        draw();

        EndDrawing();
    }
}

void MainComponent::draw()
{
    drawBackground();

    if (eventTriggered (0.2))
        moveBlockDown();

    currentBlock.draw (11, 11);

    switch (nextBlock.getId())
    {
        case 3:
            nextBlock.draw (255, 290);
            break;

        case 4:
            nextBlock.draw (255, 280);
            break;

        default:
            nextBlock.draw (270, 270);
            break;
    }
}

void MainComponent::drawBackground()
{
    ClearBackground (Colours::DarkBlue);
    grid.draw();

    DrawTextEx (font, "Score", { 365, 15 }, 38, 2, WHITE);
    DrawRectangleRounded ({ 320, 55, 170, 60 }, 0.3, 6, Colours::LightBlue);

    DrawTextEx (font, "Next", { 370, 175 }, 38, 2, WHITE);
    DrawRectangleRounded ({ 320, 215, 170, 180 }, 0.3, 6, Colours::LightBlue);

    if (gameOver)
        DrawTextEx (font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);

    auto scoreText = std::to_string (score);
    Vector2 textSize = MeasureTextEx (font, scoreText.c_str(), 38, 2);

    float scoreX = 320 + (170 - textSize.x) / 2;
    DrawTextEx (font, scoreText.c_str(), { scoreX, 65 }, 38, 2, WHITE);
}

void MainComponent::handleInput()
{
    int keyPressed = GetKeyPressed();

    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        reset();
    }

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
            updateScore (0, 1);
            break;

        case KEY_UP:
            rotateBlock();
            break;
    }
}

void MainComponent::moveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.move (0, -1);

        if (isBlockOutside() || !blockFits())
            currentBlock.move (0, 1);
    }
}

void MainComponent::moveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.move (0, 1);

        if (isBlockOutside() || !blockFits())
            currentBlock.move (0, -1);
    }
}

void MainComponent::moveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.move (1, 0);

        if (isBlockOutside() || !blockFits())
        {
            currentBlock.move (-1, 0);
            lockBlock();
        }
    }
}

void MainComponent::reset()
{
    grid.prepare();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void MainComponent::rotateBlock()
{
    if (!gameOver)
    {
        currentBlock.rotate();

        if (isBlockOutside() || !blockFits())
            currentBlock.undoRotation();
        else
            PlaySound (rotateSound);
    }
}

void MainComponent::lockBlock()
{
    auto tiles = currentBlock.getCellPositions();

    for (Position item : tiles)
        grid.getGrid()[item.getRow()][item.getColumn()] = currentBlock.getId();

    currentBlock = nextBlock;

    if (!blockFits())
        gameOver = true;

    nextBlock = getRandomBlock();
    int rowsCleared = grid.clearFullRows();

    if (rowsCleared > 0)
    {
        PlaySound (clearSound);
        updateScore (rowsCleared, 0);
    }
}

bool MainComponent::blockFits()
{
    auto tiles = currentBlock.getCellPositions();

    for (Position item : tiles)
    {
        if (!grid.isCellEmpty (item.getRow(), item.getColumn()))
            return false;
    }

    return true;
}

void MainComponent::updateScore (int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
        case 1:
            score += 100;
            break;

        case 2:
            score += 300;
            break;

        case 3:
            score += 500;
            break;

        default:
            break;
    }

    score += moveDownPoints;
}

Block MainComponent::getRandomBlock()
{
    if (blocks.empty())
        blocks = getAllBlocks();

    std::random_device os_seed;
    const uint_least32_t seed = os_seed();

    std::mt19937 generator (seed);
    std::uniform_int_distribution<uint_least32_t> distribute (0, (int) (blocks.size() - 1));

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
    auto tiles = currentBlock.getCellPositions();

    for (Position item : tiles)
    {
        if (grid.isCellOutside (item.getRow(), item.getColumn()))
            return true;
    }

    return false;
}
