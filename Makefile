all: game

game: agent.h agent.cpp game.cpp
	g++ -g agent.h agent.cpp game.cpp -o game