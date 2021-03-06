#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Log.h"

//	Declare instance of Log to log to console and files
extern Log logger;

//	Declare global settings vectors
extern std::vector<std::string> displaySettings;
extern std::vector<std::string> graphicsSettings;
extern std::vector<std::string> multSettings;

//	A function to initialize the setting vectors with the settings in the proper file under the proper heading
void initializeSettings();

//	A function to get all of the settings from a file and set them in a vector
//	Called in initialize settings
std::vector<std::string> getSettings(std::string filePath, std::string heading);

//	A function that updates the values stored in the settings vectors, NOT in the prefs file
//	Called in changeSetting
void updateSettings(std::string heading, int settingNum, std::string update);

//	A function to change a specified setting in a text file
void changeSetting(std::string filePath, std::string heading, int settingNum, std::string update);