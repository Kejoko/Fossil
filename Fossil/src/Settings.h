#pragma once

//	Declare global settings vectors
extern std::vector<std::string> displaySettings;
extern std::vector<std::string> graphicsSettings;
extern std::vector<std::string> multSettings;

//	A function to initialize the setting vectors with the settings in the proper file under the proper heading
void initializeSettings();

//	A function that updates the values stored in the settings vectors, NOT in the prefs file
void updateSettings(std::string heading, int settingNum, std::string update);