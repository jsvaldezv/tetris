#include "Position.h"

Position::Position (int inRow, int inColumn)
{
    properties.row = inRow;
    properties.column = inColumn;
}

int Position::getRow()
{
    return properties.row;
}

int Position::getColumn()
{
    return properties.column;
}
