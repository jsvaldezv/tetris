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

private:
    
    Grid grid;
    
    LBlock block;
    
};
