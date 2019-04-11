// Functions to store the vectors containing all of the setings

#include "Settings.h"

//	Initialize the global settings vectors
std::vector<std::string> displaySettings;
std::vector<std::string> graphicsSettings;
std::vector<std::string> multSettings;

//	A function to initialize the setting vectors with the settings in the proper file under the proper heading
void initializeSettings()
{
	//	Boolean to store whether or not settings have initialized properly
	bool settingsInit = true;

	displaySettings = getSettings("../../../gameprefs.txt", "Display");
	if (!displaySettings.empty()) {
		//	Log message to console noting display settings have been initialized
		logger.logInfo("Display settings initialized");
	}
	else {
		//	Log message noting display has not been initialized properly
		logger.logError("Unable to initialize Display settings");

		//	Set settingsInit to false
		settingsInit = false;
	}

	graphicsSettings = getSettings("../../../gameprefs.txt", "Graphics");
	if (!graphicsSettings.empty()) {
		//	Log message to console noting graphics settings have been initialized
		logger.logInfo("Graphics settings initialized");
	}
	else {
		//	Log message noting display has not been initialized properly
		logger.logError("Unable to initialize Graphics settings");

		//	Set settingsInit to false
		settingsInit = false;
	}

	multSettings = getSettings("../../../multiplayerprefs.txt", "Multiplayer");
	if (!multSettings.empty()) {
		//	Log message to console noting multiplayer settings have been initialized
		logger.logInfo("Multiplayer settings initialized");
	}
	else {
		//	Log message noting multiplayer settings has not been initialized properly
		logger.logError("Unable to initialize Multiplayer settings");

		//	Set settingsInit to false
		settingsInit = false;
	}

	//	Determine if all settings have initialized properly
	if (settingsInit) {
		//	Log message noting that settings have been initialized
		logger.logMessage("Settings initialized", "gamelogs.txt", false);
	}
	else {
		//	Log message noting that one or more settings have not been initialized
		logger.logMessage("One or more settings failed to initialize", "gamelogs.txt", false);
	}
}

//	A function that gets the settings specified in gameprefs.txt and
//		returns a vector containing them as strings.
std::vector<std::string> getSettings(std::string filePath, std::string heading)
{
	//	Create vector to store settings
	std::vector<std::string> settings;

	//	Open gameprefs.txt
	std::ifstream prefsFile;
	prefsFile.open(filePath);

	//	Check if prefsFile opened correctly
	if (prefsFile.is_open()) {
		//	Iterate through lines of prefsFile until we reach the specified heading or end of file
		std::string currLine;
		std::getline(prefsFile, currLine);
		while (currLine != "[" + heading + "]" && !prefsFile.eof()) {
			std::getline(prefsFile, currLine);

			if (prefsFile.eof()) {
				logger.logMessage("ERROR: Could not retrieve " + heading + " settings in " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
			}
		}

		//	Read in lines until we reach a blank line
		//	Add value of each line read in to the settings vector
		std::getline(prefsFile, currLine);
		while (currLine != "") {
			//	Add currLine after =
			settings.push_back(currLine.substr(currLine.find("=") + 1, currLine.length() - 1));

			std::getline(prefsFile, currLine);
		}

		prefsFile.close();
	}
	else {
		//	Log an error message to gamelogs stating that the specified file could not be opened
		logger.logMessage("ERROR: Could not open " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
	}

	return settings;
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

//	A function that updates the specified setting in the specified file
void changeSetting(std::string filePath, std::string heading, int settingNum, std::string update)
{
	//	Open specified file
	std::ifstream prefsFileRead;
	prefsFileRead.open(filePath);

	//	Check if the file has opened successfully
	if (prefsFileRead.is_open()) {
		//	Update settings vector
		updateSettings(heading, settingNum, update);

		//	Create a vector to store every line of file
		std::vector<std::string> lines;

		//	Iterate through lines of prefsFileRead, adding each line to lines, until we reach end of file
		std::string currLine;
		while (!prefsFileRead.eof()) {
			std::getline(prefsFileRead, currLine);
			lines.push_back(currLine);
		}

		prefsFileRead.close();

		//	Get index of specified heading by iterating through lines and comparing each string
		int headingIndex = -1;
		for (int i = 0; i < lines.size(); i++) {
			if (lines.at(i) == "[" + heading + "]") {
				headingIndex = i;
				break;
			}
		}

		//	Check if the heading was missing
		if (headingIndex != -1) {
			//	Get specified line by adding setting to heading index
			std::string newLine = lines.at(headingIndex + settingNum);

			//	Change line
			newLine = newLine.substr(0, newLine.find("=") + 1) + update;
			lines.at(headingIndex + settingNum) = newLine;

			//	Open file to write to it
			std::ofstream prefsFileWrite;
			prefsFileWrite.open(filePath);

			//	Write every string in lines to the file
			for (int i = 0; i < lines.size(); i++) {
				prefsFileWrite << lines.at(i);
				if (i < lines.size() - 1)
					prefsFileWrite << "\n";

			}

			prefsFileWrite.close();
		}
		else {
			//	Log an error to gamelogs that the specified heading was not found
			logger.logMessage("ERROR: Could not retrieve " + heading + " settings in " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
		}
	}
	else {
		//	Log an error message to gamelogs stating that the specified file could not be opened
		logger.logMessage("ERROR: Could not open " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
	}
}