//	This file is going to be the class that instantiates the game

#include "Settings.h"
#include "Log.h"
#include "../test/TestHeader.h"

//	Instantiate global logger
Log logger;

int main() {
	//	Log message noting that the game started
	logger.logMessage(". . . Starting . . . \n", "gamelogs.txt", true);

	//	Initialize the settings vectors
	initializeSettings();

	//	Log message noting that the game has exited
	logger.logMessage("\n . . . Ending . . .", "gamelogs.txt", false);
}