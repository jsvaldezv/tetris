#pragma once
#include "../Helpers/Colours.h"
#include "../Helpers/Sizes.h"
#include "Grid/Grid.h"
#include "Block/Blocks.h"
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
    
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    
    void rotateBlock();
    
    Block getRandomBlock();
    
    std::vector<Block> getAllBlocks();

private:
    
    bool isBlockOutside();
    
    Grid grid;
        
    std::vector<Block> blocks;
    
    Block currentBlock;
    Block nextBlock;
    
};
