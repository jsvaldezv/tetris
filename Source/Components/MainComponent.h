#pragma once
#include <raylib.h>
#include <random>
#include <iostream>
#include "../Helpers/Colours.h"
#include "../Helpers/Sizes.h"
#include "../Helpers/Time.h"
#include "Grid/Grid.h"
#include "Block/Blocks.h"

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
    
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    
    void moveBlockLeft();
    void moveBlockRight();
    
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    
    void updateScore (int linesCleared, int moveDownPoints);
    
    Grid grid;
        
    std::vector<Block> blocks;
    
    Block currentBlock;
    Block nextBlock;
    
    Font font;
    
    int score { 0 };
    
    Sound rotateSound;
    Sound clearSound;
    
};
