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
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
    
    //print();
}

void Grid::print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        
        std::cout << "\n";
    }
}

void Grid::draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle (column * cellSize+1, row * cellSize + 1, cellSize-1, cellSize - 1, colours[cellValue]);
        }
    }
}
