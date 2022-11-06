#pragma once
#include "chess.h"

class Piece
{
protected:
    int* current_location;
public:
    bool black;
    int* possible_moves(Chess& game);
    Piece(int* location, bool colour);
    ~Piece();
};

class Bishop: public Piece {};

class Pawn: public Piece{};

class Queen: public Piece{};

class King: public Piece{};

class Knight: public Piece{};

class Rook: public Piece{};
