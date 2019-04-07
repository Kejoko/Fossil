//	This file is going to be the class that instantiates the game

#include "FileIO.h"

int main() {
	//	Log message noting that the game started
	logMessage("Game started", "game.txt", true);

	//	Log message noting that the game has exited
	logMessage("Game finished", "game.txt", false);
}