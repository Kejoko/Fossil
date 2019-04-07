//	This file contains functionss that allow for easy writing to text files.

#include "FileIO.h"

//	A method that writes a string to a specified file
//	Returns true if the file was written to successfully
//	Returns false if file was not written to successfully
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