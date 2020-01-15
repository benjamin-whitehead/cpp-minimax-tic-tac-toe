#include "agent.h"

const unordered_map<char, int> scoreTable({{'X', 100}, {'O', -100}, {'T', 0}});

/**
 * Determine's if there is a winner on a given board
 *
 * @param char[][], the actual gameboard
 * @return char, a code based on the result, X for x winner, O for o winner, T for tie, P for present
 */
char CheckWinner(char gameBoard[3][3])
{
    char winner;
    for (int i = 0; i <= 2; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != 0)
        {
            winner = gameBoard[i][0];
            if (winner != ' ')
                return winner;
        }
    }
    for (int i = 0; i <= 2; i++)
    {
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != 0)
        {
            winner = gameBoard[0][i];
            if (winner != ' ')
                return winner;
        }
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != 0)
    {
        winner = gameBoard[0][0];
        if (winner != ' ')
            return winner;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != 0)
    {
        winner = gameBoard[0][2];
        if (winner != ' ')
            return winner;
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (gameBoard[i][j] == ' ')
            {
                winner = 'P';
                return winner;
            }
        }
    }
    winner = 'T';
    return winner;
}

/**
 * Calculates the score of all possible game states and returns either the largest or smallest score
 *
 * @param char[][], the actual gameboard, int, the current depth of the operation, Players, the current players turn
 * @return int, a min or max score
 */
int minimax(char board[3][3], int depth, Players cPlayer)
{
    char result = CheckWinner(board);
    if (result == 'X' || result == 'O' || result == 'T')
    {
        return scoreTable.at(result);
    }
    if (cPlayer == MAXIMIZING)
    {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, MINIMIZING);
                    board[i][j] = ' ';
                    if (score > bestScore)
                        bestScore = score;
                }
            }
        }
        return bestScore;
    }
    if (cPlayer == MINIMIZING)
    {
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, MAXIMIZING);
                    board[i][j] = ' ';
                    if (score < bestScore)
                        bestScore = score;
                }
            }
        }
        return bestScore;
    }
    return -1;
}

/**
 * Calculates the next optimal move for the AI to take
 *
 * @param char[][], the actual gameboard
 * @return pair<int, int> an x,y pair in the range of [0, 3][0, 3] of the AI's next move
 */
pair<int, int> Agent::calculateNextMove(char board[3][3])
{
    int best = INT_MIN;
    pair<int, int> move;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'X';
                int score = minimax(board, 0, MINIMIZING);
                board[i][j] = ' ';
                if (score > best)
                {
                    best = score;
                    move = make_pair(i, j);
                }
            }
        }
    }
    return move;
}
