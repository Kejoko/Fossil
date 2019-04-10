#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class Log
{
public:
	Log();
	~Log();

	//	Function to log a message to a text file
	void logMessage(std::string message, std::string filePath, bool clear);

	//	function to log message to console
	void logInfo(std::string message);

	//	Function to log warning to console
	void logWarn(std::string message);

	//	Function to log warning to console
	void logError(std::string message);
};

extern Log logger;