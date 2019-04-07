//	this file contains functions that are used in reading data from text files.

#include "FileIO.h"

//	A function that gets the settings specified in gameprefs.txt and
//		returns a vector containing them as strings.
std::vector<std::string> getSettings(std::string heading)
{
	//	Create vector to store settings
	std::vector<std::string> settings;

	//	Open gameprefs.txt
	std::ifstream prefsFile;
	prefsFile.open("../../../gameprefs.txt");

	//	Check if prefsFile opened correctly
	if (prefsFile.is_open()) {
		//	Iterate through lines of gameprefs.txt until we reach the specified heading or end of file
		std::string currLine;
		std::getline(prefsFile, currLine);
		while (currLine != "[" + heading + "]" && !prefsFile.eof()) {
			std::getline(prefsFile, currLine);

			if (prefsFile.eof()) {
				logMessage("Could not retrieve settings for " + heading, "gamelogs.txt", false);
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

		//	Close gameprefs.txt
		prefsFile.close();
	}
	else {
		logMessage("Could not open gameprefs.txt", "gamelogs.txt", false);
	}

	return settings;
}