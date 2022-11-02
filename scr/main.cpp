#include "ui.h"
#include <iostream>
using namespace std;

bool valid_location(string position);
int* position_to_index(string position);

main()
{
    Chess game;
    cout << endl << endl << "   Welcome to Chess" << endl << endl << endl;
    while (game.gameon)
    {
        print_board(game);
        string current_place;
        string future_place;
        
        while (true)
        {
            cout << "What piece do you want move (What is its location)?" << endl;
            cin >> current_place;
            cout << endl;

            if (valid_location(current_place))
            {
                break;
            }
            
        }
        while (true)
        {
            cout << "Where do you want to move it?" << endl;
            cin >> future_place;
            cout << endl;
            if (valid_location(future_place))
            {
                break;
            }
        }
        int* current = position_to_index(current_place);
        int* future = position_to_index(future_place);
        game.move(current, future);    
        free(current);
        free(future);


    }
    
    return 0;
    
}

int* position_to_index(string position)
{
    int* int_position = (int*) malloc(2);
    char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++)
    {
        if (toupper(position[0]) == letters[i])
        {   
            int_position[1] = i;
        }

    }
    int_position[0] = position[1] - '0' - 1;
    int_position[0] = 7 - int_position[0];
    return int_position;
}   


bool valid_location (string position)
{
    int* index = position_to_index(position);
    if (index[0] < 0 || index[0] > 7 || index[1] < 0 || index[1] > 7 )
    {
        cout << "Location is not in the board" << endl;
        free(index);
        return false;
    }
    else 
    {
        free(index);
        return true;
    }
}