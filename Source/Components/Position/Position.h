#pragma once

class Position
{
public:
    
    Position (int inRow, int inColumn);
    ~Position() = default;
    
    struct Properties
    {
        int row;
        int column;
    };
    
    int getRow();
    
    int getColumn();
    
private:
    
    Properties properties;
    
};
