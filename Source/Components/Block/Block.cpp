#include "Block.h"

Block::Block()
{
    colours = Colours::getCellColours();
}

void Block::draw (int offsetX, int offsetY)
{
    std::vector<Position> tiles = getCellPositions();
    
    for (Position item : tiles)
    {
        DrawRectangle (item.getColumn() * properties.cellSize + offsetX,
                       item.getRow() * properties.cellSize + offsetY,
                       properties.cellSize - 1,
                       properties.cellSize - 1,
                       colours[getId()]);
    }
}

void Block::move (int rows, int columns)
{
    properties.rowOffset += rows;
    properties.columnOffset += columns;
}

void Block::rotate()
{
    properties.rotationState++;
    
    if (properties.rotationState == (int) cells.size())
        properties.rotationState = 0;
}

void Block::undoRotation()
{
    properties.rotationState--;
    
    if (properties.rotationState == -1)
        properties.rotationState = (int) (cells.size() - 1);
}

std::vector<Position> Block::getCellPositions()
{
    auto tiles = cells[properties.rotationState];
    std::vector<Position> movedTiles;
    
    for (Position item : tiles)
    {
        Position newPos = Position (item.getRow() + properties.rowOffset, item.getColumn() + properties.columnOffset);
        movedTiles.push_back (newPos);
    }
    
    return movedTiles;
}

int Block::getId()
{
    return properties.currentId;
}

void Block::setId (int inID)
{
    properties.currentId = inID;
}
