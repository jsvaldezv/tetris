#pragma once
#include <iostream>
#include <vector>
#include <raylib.h>
#include "../../Helpers/Colours.h"

class Grid
{
public:
    
    Grid();
    ~Grid();
    
    void prepare();
    
    void print();
    
    void draw();
    
    std::array<std::array<int, 10>, 20> grid;
    
private:
    
    std::vector<Color> getCellColours();
    
    int numRows { 20 };
    int numCols { 10 };
    
    int cellSize { 30 };
    
    std::vector<Color> colours;

};
