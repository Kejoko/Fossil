//	A class to store the vectors containing all of the setings

#include "FileIO.h"

//	Initialize the global settings vectors
std::vector<std::string> displaySettings;
std::vector<std::string> graphicsSettings;
std::vector<std::string> multSettings;

//	A function to initialize the setting vectors with the settings in the proper file under the proper heading
void initializeSettings()
{
	displaySettings = getSettings("../../../gameprefs.txt", "Display");
	graphicsSettings = getSettings("../../../gameprefs.txt", "Graphics");
	multSettings = getSettings("../../../multiplayerprefs.txt", "Multiplayer");

	//	Log message noting that settings have been updated
	logMessage("Settings initialized", "gamelogs.txt", false);
}

//	A function that updates the values stored in the settings vectors, NOT in the prefs file
void updateSettings(std::string heading, int settingNum, std::string update)
{
	//	Determine which vector to update and update it
	if (heading == "Display")
		displaySettings.at(settingNum - 1) = update;
	else if (heading == "Graphics")
		graphicsSettings.at(settingNum - 1) = update;
	else if (heading == "Multiplayer")
		multSettings.at(settingNum - 1) = update;
}