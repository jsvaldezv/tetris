#pragma once
#include <vector>
#include <map>
#include "../Position/Position.h"
#include "../../Helpers/Colours.h"

class Block
{
public:
    
    explicit Block();
    ~Block() = default;
    
    struct Properties
    {
        int currentId { 0 };
        int cellSize { 30 };
        int rotationState { 0 };
        
        int rowOffset { 0 };
        int columnOffset { 0 };
    };
    
    void draw (int offsetX, int offsetY);
    
    void move (int rows, int columns);
    
    void rotate();
    
    void undoRotation();
    
    std::vector<Position> getCellPositions();
    
    int getId();
    
    void setId (int inID);
    
    std::map<int, std::vector<Position>> cells;
    
private:
    
    Properties properties;
    
    std::vector<Color> colours;
};
