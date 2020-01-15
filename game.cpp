#include <iostream>
#include "agent.h"

const unordered_map<int, pair<int, int>> indexLookupTable({{0, make_pair(0, 0)}, {1, make_pair(0, 1)}, {2, make_pair(0, 2)}, {3, make_pair(1, 0)}, {4, make_pair(1, 1)}, {5, make_pair(1, 2)}, {6, make_pair(2, 0)}, {7, make_pair(2, 1)}, {8, make_pair(2, 2)}});
char gameBoard[3][3];

void InitGameBoard();
void DisplayGameBoard();
void GameLoop();

char CheckWinner(char gameBoard[3][3]);

/**
 * Entry point for the program
 *
 * @param null
 * @return exit code
 */
int main()
{
    InitGameBoard();
    GameLoop();
    return 0;
}

/**
 * Initializes the GameBoard to a 3x3 array of spaces
 *
 * @param null
 * @return null
 */
void InitGameBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
}

/**
 * Outputs the 3x3 array to the console
 *
 * @param null
 * @return null
 */
void DisplayGameBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == ' ')
                cout << "| - |";
            if (gameBoard[i][j] == 'X')
                cout << "| X |";
            if (gameBoard[i][j] == 'O')
                cout << "| 0 |";
        }
        cout << endl;
    }
}

/**
 * Handles the logic for the Game
 *
 * @param null
 * @return null
 */
void GameLoop()
{
    Players currentPlayer = MAXIMIZING;
    Agent agent;
    while (true)
    {
        cout << endl;
        char winner = CheckWinner(gameBoard);
        if (winner == 'X' || winner == 'O')
        {
            cout << winner << " has won!" << endl;
            break;
        }
        else if (winner == 'T')
        {
            cout << "there was a tie!" << endl;
            break;
        }

        if (currentPlayer == MINIMIZING)
        {
            cout << "Enter a position in [0, 8]: ";
            int position;
            cin >> position;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input: Unrecognized Input" << endl;
                cin >> position;
            }
            if (indexLookupTable.find(position) != indexLookupTable.end())
            {
                pair<int, int> index = indexLookupTable.at(position);
                if (gameBoard[index.first][index.second] == ' ')
                {
                    gameBoard[index.first][index.second] = 'O';
                    currentPlayer = MAXIMIZING;
                }
                else
                {
                    cout << "Invalid Move: Position Already Taken" << endl;
                }
            }
            else
            {
                cout << "Invalid Move: Invalid Position" << endl;
            }
        }
        else if (currentPlayer == MAXIMIZING)
        {
            pair<int, int> response = agent.calculateNextMove(gameBoard);
            gameBoard[response.first][response.second] = 'X';
            currentPlayer = MINIMIZING;
        }
        DisplayGameBoard();
    }
}