#include "Block.h"

Block::Block()
{
    colours = Colours::getCellColours();
}

void Block::draw()
{
    std::vector<Position> tiles = cells[rotationState];
    
    for (Position item : tiles)
        DrawRectangle (item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colours[getId()]);
}

int Block::getId()
{
    return currentId;
}

void Block::setId (int inID)
{
    currentId = inID;
}
