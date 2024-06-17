#pragma once
#include <iostream>
#include <vector>
#include <raylib.h>
#include "../../Helpers/Colours.h"

class Grid
{
public:
    
    explicit Grid();
    ~Grid();
    
    void prepare();
    
    void print();
    
    void draw();
    
private:
    
    int numRows { 20 };
    int numCols { 10 };
    
    int cellSize { 30 };
    
    std::array<std::array<int, 10>, 20> grid;
    
    std::vector<Color> colours;

};
