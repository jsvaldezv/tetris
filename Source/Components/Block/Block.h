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
    
    void draw();
    
    int getId();
    
    void setId (int inID);
    
    std::map<int, std::vector<Position>> cells;
    
private:
    
    int currentId;
    
    int cellSize { 30 };
    int rotationState { 0 };
    
    std::vector<Color> colours;
};
