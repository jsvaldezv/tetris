#include "Block.h"
#include "../Position/Position.h"

class LBlock : public Block
{
public:
    
    LBlock()
    {
        setId (1);
        
        cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
        cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
        cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
        cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
    }
};

class JBlock : public Block
{
public:
    
    JBlock()
    {
        setId (2);
        
        cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
    }
};

class IBlock : public Block
{
public:
    
    IBlock()
    {
        setId (3);
        
        cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
        cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
        cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
    }
};

class OBlock : public Block
{
public:
    
    OBlock()
    {
        setId (4);
        
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
    }
};

class SBlock : public Block
{
public:
    
    SBlock()
    {
        setId (5);
        
        cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
        cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
    }
};

class TBlock : public Block
{
public:
    
    TBlock()
    {
        setId (6);
        
        cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
    }
};

class ZBlock : public Block
{
public:
    
    ZBlock()
    {
        setId (7);
        
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
    }
};
