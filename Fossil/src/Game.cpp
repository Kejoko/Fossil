//	This file is going to be the class that instantiates the game

#include "FileIO.h"

int main() {
	//	Log message noting that the game started
	logMessage(". . . Starting . . . \n", "gamelogs.txt", true);

	//	Create an array to store the settings and get settings from gameprefs
	std::vector<std::string> displaySettings = getSettings("../../../gameprefs.txt", "Display");
	std::vector<std::string> graphicsSettings = getSettings("../../../gameprefs.txt", "Graphics");
	std::vector<std::string> multSettings = getSettings("../../../multiplayerprefs.txt", "Multiplayer");

	//	Log message noting that the game has exited
	logMessage("\n . . . Ending . . .", "gamelogs.txt", false);
}