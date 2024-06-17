#pragma once
#include "../Helpers/Colours.h"
#include "../Helpers/Sizes.h"
#include "../Helpers/Time.h"
#include "Grid/Grid.h"
#include "Block/Blocks.h"
#include <raylib.h>
#include <random>

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
    
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    
    Block getRandomBlock();
    
    std::vector<Block> getAllBlocks();

private:
    
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    
    Grid grid;
        
    std::vector<Block> blocks;
    
    Block currentBlock;
    Block nextBlock;
    
};
