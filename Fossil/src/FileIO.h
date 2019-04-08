#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Settings.h"

//	Methods implemented in FileLogger.cpp
void logMessage(std::string message, std::string filePath, bool clear);
void changeSetting(std::string filePath, std::string heading, int settingNum, std::string update);

//	Methods implemented in FileReader.cpp
std::vector<std::string> getSettings(std::string filePath, std::string heading);