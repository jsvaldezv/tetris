#include "Grid.h"

Grid::Grid()
{
    colours = Colours::getCellColours();
}

Grid::~Grid()
{
    colours.clear();
}

void Grid::prepare()
{
    for (int row = 0; row < properties.numRows; row++)
    {
        for (int column = 0; column < properties.numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::print()
{
    for (int row = 0; row < properties.numRows; row++)
    {
        for (int column = 0; column < properties.numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        
        std::cout << "\n";
    }
}

void Grid::draw()
{
    for (int row = 0; row < properties.numRows; row++)
    {
        for (int column = 0; column < properties.numCols; column++)
        {
            int cellValue = grid[row][column];
            
            DrawRectangle (column * properties.cellSize + 1,
                           row * properties.cellSize + 1,
                           properties.cellSize - 1,
                           properties.cellSize - 1,
                           colours[cellValue]);
        }
    }
}

bool Grid::isCellOutside (int row, int column)
{
    if (row >= 0 && row < properties.numRows && column >= 0 && column < properties.numCols)
        return false;
    
    return true;
}

bool Grid::isCellEmpty (int row, int column)
{
    if (grid[row][column] == 0)
        return true;
    
    return false;
}

std::array<std::array<int, 10>, 20>& Grid::getGrid()
{
    return grid;
}
