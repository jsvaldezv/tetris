#pragma once
#include "../Helpers/Colours.h"
#include "../Helpers/Sizes.h"
#include "../Helpers/Time.h"
#include "Block/Blocks.h"
#include "Grid/Grid.h"
#include <iostream>
#include <random>
#include <raylib.h>

class MainComponent
{
public:
    explicit MainComponent();
    ~MainComponent();

    void prepare();

    void process();

    void draw();

    void drawBackground();

    void handleInput();

    void moveBlockDown();

    void reset();

    bool gameOver { false };

    Music music;

private:
    
    Grid grid;
    
    Block getRandomBlock();
    std::vector<Block> blocks;
    std::vector<Block> getAllBlocks();
    
    Block currentBlock;
    Block nextBlock;

    void moveBlockLeft();
    void moveBlockRight();

    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();

    void updateScore (int linesCleared, int moveDownPoints);

    Font font;

    int score { 0 };

    Sound rotateSound;
    Sound clearSound;
};
