# Changelog

### 2019.05.07
- Creation of gameprefs text file to store settings of the game
- Changed FileLogger to use strings for printing instead of const char*
- Creation of FileReader class
	- Implementation of getSettings function to retrieve the settings of the game stored in gameprefs file

**Next:**
- Open window using display settings specified in gameprefs.txt


### 2019.04.07
- Implemented basic directory structure
- Creation of FileLogger class to easily write to files and log messages
	- Properly working logMessage function
- Creation of FileIO header file for ease of use with FileLogger
- Creation of Game.cpp
	- Class that creates an instance of game and bootstraps
	- Class that will implement main
	- Replacement for main.cpp

**Next:**
- Unit testing for FileLogger
- Create and implement FileReader class
- Unit testing for FileReader
- Opening window with OpenGL