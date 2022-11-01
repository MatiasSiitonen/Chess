#include "chess.h"
#include <iostream>
using namespace std;

Chess::Chess()
{
    memcpy(board, start_board, sizeof(start_board));
    gameon = true;
}
Chess::~Chess()
{
    cout << "Object Deleted" << endl;
}