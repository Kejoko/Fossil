#include "Log.h"


//	Log constructor
Log::Log()
{
}

//	Log destructor
Log::~Log()
{
}

//	A function that writes a string to a specified file
void Log::logMessage(std::string message, std::string filePath, bool clear)
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