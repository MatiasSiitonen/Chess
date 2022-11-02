#include "chess.h"
#include <iostream>
using namespace std;

Chess::Chess()
{
    memcpy(board, start_board, sizeof(start_board));
    gameon = true;
    whiteturn = true;
}
Chess::~Chess()
{
    cout << "Object Deleted realyl" << endl;
}

char Chess::getPiceAtPosition(int row, int spot)
{
    return board[row][spot];
}

bool Chess::move(int* current, int* future)
{
    board[future[0]][future[1]] = board[current[0]][current[1]];
    board[current[0]][current[1]] = 0x20;
    return true;
}


