#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//	Methods implemented in FileLogger.cpp
void logMessage(std::string message, std::string filePath, bool clear);

//	Methods implemented in FileReader.cpp
std::vector<std::string> getSettings(std::string heading);