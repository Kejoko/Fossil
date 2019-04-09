#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Log
{
public:
	Log();
	~Log();

	//	Function to log a message to a text file
	void logMessage(std::string message, std::string filePath, bool clear);
};

extern Log logger;