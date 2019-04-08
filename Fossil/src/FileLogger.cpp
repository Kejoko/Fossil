//	This file contains functionss that allow for easy writing to text files.

#include "FileIO.h"

//	A function that writes a string to a specified file
void logMessage(std::string message, std::string filePath, bool clear)
{
	//	Open a file specified by filePath
	std::ofstream outputFile;
	if (clear == true)
		outputFile.open(filePath, std::ios::trunc);
	else
		outputFile.open(filePath, std::ios::app);

	//	Check if file opened successfully
	if (outputFile.is_open()) {
		//	Write the message to the file
		outputFile << message << "\n";

		//	Close the file
		outputFile.close();
	}
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
			logMessage("ERROR: Could not retrieve " + heading + " settings in " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
		}
	}
	else {
		//	Log an error message to gamelogs stating that the specified file could not be opened
		logMessage("ERROR: Could not open " + filePath.substr(filePath.find_last_of("/") + 1, filePath.length()), "gamelogs.txt", false);
	}
}