#pragma once
#include "chess.h"

class Piece
{
protected:
    int* current_location;
public:
    int* possible_moves(Chess& game)
    Piece(int* location);
    ~Piece();
};

class Bishop: public Piece 
{

};

