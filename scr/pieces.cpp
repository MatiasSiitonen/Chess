#include "pieces.h"

Piece::Piece(int* location, bool colour)
{
    current_location = location;
    black = colour;
}