//	this file contains functions that are used in reading data from text files.

#include "FileIO.h"

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
				logMessage("ERROR: Could not retrieve " + heading + " settings in " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
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
		logMessage("ERROR: Could not open " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
	}

	return settings;
}