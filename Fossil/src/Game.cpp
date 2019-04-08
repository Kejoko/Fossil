//	This file is going to be the class that instantiates the game

#include "FileIO.h"
#include "Settings.h"
#include "../test/TestHeader.h"

int main() {
	//	Log message noting that the game started
	logMessage(". . . Starting . . . \n", "gamelogs.txt", true);

	//	Initialize the settings vectors
	initializeSettings();

	//	Log message noting that the game has exited
	logMessage("\n . . . Ending . . .", "gamelogs.txt", false);
}