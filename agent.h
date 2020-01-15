#include <climits>
#include <utility>
#include <unordered_map>
using namespace std;

enum Players
{
    MINIMIZING, // AI PLAYER
    MAXIMIZING  // HUMAN PLAYER
};

struct Agent
{
    pair<int, int> calculateNextMove(char board[3][3]);
};