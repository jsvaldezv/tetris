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
    
    struct Properties
    {
        int numRows { 20 };
        int numCols { 10 };
        int cellSize { 30 };
    };
    
    void prepare();
    
    void print();
    
    void draw();
    
    bool isCellOutside (int inRow, int inColumn);
    
private:
    
    Properties properties;
    
    std::array<std::array<int, 10>, 20> grid;
    
    std::vector<Color> colours;

};
