#pragma once

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
    bool gameon;
    bool moveturn;
    char board[8][8];
public:
    Chess();
    ~Chess();
};

