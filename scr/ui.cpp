#include "ui.h"
#include <iostream>
using namespace std;
/*
char get_chesspiece(int piece)
{
    switch (piece)
    {
    case 107:
        return 0x2654;
        break;

    case 75:
        return 0x265A;
        break;

    case 113:
        return 0x2655;
        break;

    case 81:
        return 0x265B;
        break;

    case 98:
        return 0x2657;
        break;

    case 66:
        return 0x265D;
        break;

    case 110:
        return 0x2658;
        break;

    case 78:
        return 0x265E;
        break;

    case 114:
        return 0x2656;
        break;

    case 82:
        return 0x265F;
        break;

    case 80:
        return 0x2659;
        break;

    default:
        return 0x265F;
        break;
    }
}
*/

void print_board(Chess &game)
{
    cout << endl
         << endl;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            print_line(true, i, game);
        }
        else
        {
            print_line(false, i, game);
        }
    }
    cout << endl
         << "     A   "
         << "  B   "
         << "  C   "
         << "  D   "
         << "  E   "
         << "  F   "
         << "  G   "
         << "  H   " << endl;
}
void print_line(bool black, int line_number, Chess &game)
{

    char white_square = 0xDB;
    char black_square = 0xFF;
    // One square contains three command lines
    for (int a = 0; a < 3; a++)
    {
        if (a == 1)
        {
            cout << " " << 8 - line_number << " ";
        }
        else
        {
            cout << "   ";
        }
        // Each line have 8 squares
        for (int k = 0; k < 8; k++)
        {
            if (black)
            {

                for (int i = 0; i < 6; i++)
                {
                    if (a == 1 && i == 3)
                    {
                        cout << (game.getPiceAtPosition(line_number, k) != 0x20 ? (game.getPiceAtPosition(line_number, k)) : black_square);
                    }
                    else
                    {
                        cout << black_square;
                    }
                }
                black = false;
            }
            else
            {
                for (int i = 0; i < 6; i++)
                {
                    if (a == 1 && i == 3)
                    {
                        cout << (game.getPiceAtPosition(line_number, k) != 0x20 ? (game.getPiceAtPosition(line_number, k)) : white_square);
                    }
                    else
                    {
                        cout << white_square;
                    }
                }
                black = true;
            }
        }
        cout << endl;
    }
}
