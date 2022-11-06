#pragma once
#include <vector>
using namespace std;

struct position
{
    int row;
    int line;
};

 const char start_board[8][8] =
   {

      { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
      { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
      { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
      { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
   };


class Chess
{
private:
    char board[8][8];
    bool whiteturn;
    bool valid_move(int* current, int* future);
public:
    bool gameon;
    Chess();
    ~Chess();
    char getPiceAtPosition(int row, int spot);

    vector<position> moves_king(int* current, bool black);
    vector<position> moves_pawn(int* current, bool black);
    bool move(int* current, int* future);

};

