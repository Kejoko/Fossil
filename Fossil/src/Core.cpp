//	This file is going to be the class that instantiates the game

#include "Settings.h"
#include "Log.h"
#include "Game.h"
#include "../test/TestHeader.h"

//	Instantiate global objects
Log logger;
Game game;

int main() {
	//	Log message noting that the game started
	logger.logMessage(". . . Starting . . . \n", "gamelogs.txt", true);

	//	Initialize the game
	game.InitializeGame();

	//	Log message noting that the game has exited
	logger.logMessage("\n . . . Ending . . .", "gamelogs.txt", false);

	//	For testing to allow console to stay open
	std::cin.get();
}