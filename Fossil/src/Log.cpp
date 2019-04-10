#include "Log.h"

#ifdef FSL_DEBUG
	#define INFO(x) std::cout << "[INFO]\t" + x + "\n"
	#define WARN(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);\
		std::cout << "[WARN]\t" + x + "\n";\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
	#define ERROR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);\
		std::cout << "[ERROR]\t" + x + "\n";\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
	#define Debugging true
#else
	#define INFO(x)
	#define WARN(x)
	#define ERROR(x)
	#define Debugging false
#endif

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
	//	Check if debug release
	if (Debugging) {
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
}

//	function to log message to console
void Log::logInfo(std::string message)
{
	INFO(message);
}

//	Function to log warning to console
void Log::logWarn(std::string message)
{
	WARN(message);
}

//	Function to log warning to console
void Log::logError(std::string message)
{
	ERROR(message);
}