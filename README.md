# C++ MiniMax Tic-Tac-Toe Implementation
A C++ implementation of the Minimax Algorithm for playing the optimal game in Tic Tac Toe.
<br />
To run the program, compile it with make or manually with gcc. 
```
make
```
To run the program
```
./game
```
The position codes are as follow:
```
| 0 || 1 || 2 |
| 3 || 4 || 5 |
| 6 || 7 || 8 |
```
An example run of the program is:
```
| X || - || - |
| - || - || - |
| - || - || - |

Enter a position in [0, 8]: 4
| X || - || - |
| - || 0 || - |
| - || - || - |

| X || X || - |
| - || 0 || - |
| - || - || - |

Enter a position in [0, 8]: 2
| X || X || 0 |
| - || 0 || - |
| - || - || - |

| X || X || 0 |
| - || 0 || - |
| X || - || - |

Enter a position in [0, 8]: 3
| X || X || 0 |
| 0 || 0 || - |
| X || - || - |

| X || X || 0 |
| 0 || 0 || X |
| X || - || - |

Enter a position in [0, 8]: 8
| X || X || 0 |
| 0 || 0 || X |
| X || - || 0 |

| X || X || 0 |
| 0 || 0 || X |
| X || X || 0 |

there was a tie!
```
There is no possible way for the player to win because the algorithim guarantee's either a win or a tie
