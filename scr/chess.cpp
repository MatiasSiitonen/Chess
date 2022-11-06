#include "chess.h"
#include "pieces.h"
#include <iostream>
#include <vector>
#include <cctype>

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

vector<position> Chess::moves_king(int *current, bool black)
{

    vector<position> possibles;

    for (int i = -1; i < 2; i++)
    {
        if (current[0] + i >= 0 && current[0] + i < 8)
        {
            for (int k = -1; k < 2; k++)
            {
                if (current[1] + k >= 0 && current[1] + k < 8)
                {
                    if (k == 0 && i == 0)
                    {
                    }
                    else
                    {
                        if (board[current[0] + i][current[1] + k] == 0x20)
                        {
                            possibles.push_back({current[0] + i, current[1] + k});
                        }
                        else if (black)
                        {
                            if (islower(board[current[0] + i][current[1] + k]))
                            {
                                possibles.push_back({current[0] + i, current[1] + k});
                            }
                        }
                        else
                        {
                            if (isupper(board[current[0] + i][current[1] + k]))
                            {
                                possibles.push_back({current[0] + i, current[1] + k});
                            }
                        }
                    }
                }
            }
        }
    }
    return possibles;
}
vector<position> Chess::moves_pawn(int *current, bool black)
{
    vector<position> possibles;
    if (black)
    {
        for (int i = -1; i < 2; i += 2)
        {
            if (islower(board[current[0] + 1][current[1] + i]))
            {
                possibles.push_back({current[0] + 1, current[1] + i});
            }
        }
        if (board[current[0] + 1][current[1]] == 0x20)
        {
            possibles.push_back({current[0] + 1, current[1]});
        }
    }
    else
    {
        for (int i = -1; i < 2; i += 2)
        {

            if (isupper(board[current[0] - 1][current[1] + i]))
            {
                possibles.push_back({current[0] - 1, current[1] + i});
            }
        }
        if (board[current[0] - 1][current[1]] == 0x20)
        {
            possibles.push_back({current[0] - 1, current[1]});
        }
    }

    return possibles;
}

bool Chess::move(int *current, int *future)
{
    if (valid_move(current, future))
    {
        board[future[0]][future[1]] = board[current[0]][current[1]];
        board[current[0]][current[1]] = 0x20;
        return true;
    }
    else
    {
        cout << "INVALID MOVE" << endl;
    }
    return false;
}

bool Chess::valid_move(int *current, int *future)
{
    int int_piece = board[current[0]][current[1]];
    vector<position> possible_moves;
    switch (int_piece)
    {
    case 107:
        cout << "WHITE KING" << endl;
        possible_moves = moves_king(current, false);
        break;

    case 75:
        cout << "BLACK KING" << endl;
        possible_moves = moves_king(current, true);
        break;
    /*
    case 113:
        Queen piece(current, false);
        break;

    case 81:
        Queen piece(current, true);
        break;

    case 98:
        Bishop piece(current, false);
        break;

    case 66:
        Bishop piece(current, true);
        break;

    case 110:
        Knight piece(current, false);
        break;

    case 78:
        Knight piece(current, true);
        break;

    case 114:
        Rook piece(current, false);
        break;

    case 82:
        Rook piece(current, true);
        break;
    */
    case 112:
        cout << "white PAWN" << endl;
        possible_moves = moves_pawn(current, false);
        break;

    default:
        cout << "BLACK PAWN" << endl;
        possible_moves = moves_pawn(current, true);
        break;
    }
    if (possible_moves.size() == 0)
    {
        return false;
    }
    for (int i = 0; i < possible_moves.size(); i++)
    {
        if (future[0] == possible_moves.at(i).row && future[1] == possible_moves.at(i).line)
        {
            return true;
        }
    }
    return false;
}
