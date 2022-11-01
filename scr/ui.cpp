#include "ui.h"
#include <iostream>
using namespace std;

void print_board()
{
    cout << endl << endl;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            print_line(true, i+1);
        }
        else
        {
            print_line(false, i+1);
        }
    }
    cout << endl << "     A   " << "  B   " << "  C   " << "  D   " << "  E   " << "  F   " << "  G   " << "  H   " << endl;

}
void print_line(bool black, int line_number){

    char white_square = 0xDB;
    char black_square = 0xFF;
    // One square contains three command lines
    for(int a = 0; a < 3; a++)
    {
        if (a == 1)
        {
            cout << " " << line_number << " ";
        }
        else
        {
            cout << "   ";
        }
        // Each line have 8 squares
        for(int k = 0; k < 8; k++)
        {
            if (black)
            {
                for (int i = 0; i < 6; i++)
                {
                    cout << black_square;
                }
                black = false;
            }
            else
            {
                for (int i = 0; i < 6; i++)
                {
                    cout << white_square;
                }                
                black = true;
            }
        }
        cout << endl;
    }
}   