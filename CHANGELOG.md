# Changelog

### 2019.04.14
- Removal of GameStateStack
	- Implemented vector stack into Game
- Creation of GameObject class
	- Objects stored in vector of a GameState object
	
**Next**
- Draw to window from Game Display function properly
	- Iterate through GameStates and through each State's vector of Objects
- Configure reference settings properly
	- Add solution directory as a reference so ther will no longer be the need to include relative path to gameprefs and multiplayerprefs
	- Can simply open "gameprefs.txt" instead of "../../../gameprefs.txt"
- Configure build settings properly
	- Make Fossil.dll be linked directly to Workspace.exe
	- Remove need to copy-paste Fossil.dll into Workspaces build path for it to run properly
	- The objects to be rendered

### 2019.04.13
- Initialization of OpenGL context and window

### 2019.04.11
- Create abstract GameState class
- Creation of GameStateStack class
	- Stack of GameState pointers in Game class as data field

### 2019.04.10
- Change directory heirarchy to be one less level deep
	- Build to Bin/Debug-x64 rather than Bin/Debug/x64
- Creation of Workspace project
	- Builds an executable
	- Where actual game will be built
- Changed build settings of Fossil project
	- Builds a .dll to be referenced by Workspace project
- Working entry point in Fossil
- Declaration of functions in Game class
	- Basic implementation of main game loop

### 2019.04.09
- Creation of Game class
- Changed Log class
	- Creation of funtions to log erros and messages to the console
	- Defined macros to determine whether or not to output, based on type of build (debug or release)

### 2019.04.08
- Renaming of Game.cpp in Fossil project to Core.cpp
	- Instantiation of global Log object
- Creation of Fossil.h to include all of the methods and namespace created in Fossil project
	- To be used in game project, not in Fossil project
- Creation of logger class to more easily log messages to files and terminals
	- Declaration of global Log object
- Removal of FileLogger, FileReader, and FileIO
	- Moved logMessage to Log class
	- Moved changeSetting to Settings.cpp
	- Moved getSettings to Settings.cpp
	- Initializes Game
- Renaming of Test_FileIO to Test_IO

**Next**
- Creation of Game project
	- Where actual game will be created
	- Location of entry point
- Create entry point and basic game loop
- Change output of Fossil project
	- Now outputs a dynamic library for Game poject's executable to utilize


### 2019.04.07
- Creation of gameprefs text file to store settings of the game
- Changed FileLogger to use strings for printing instead of const char*
- Creation of FileReader class
	- Implementation of getSettings function to retrieve the settings of the game stored in specified file under specified heading
- Creation of multiplayerprefs file to store multiplayer settings
	- I am not near the implementation of multiplayer yet, but I figured it'd be good to get my idea concreted and to get general architecture in place.
- Implementation of function in FileLogger to change a specified setting value in gameprefs
- Creation of Settings.h and Settings.cpp
	- No longer have to store vectors for settings inside of game
	- Creation of function to initialize the settings vectors with settings in specified files
	- Creation of function to update settings vectors
		- Called by changeSetting function in FileLogger
- Changed the vectors storing settings to be global variables declared in Settings.h
- Creation of header and files to declare and implement functions for testing file io
	- Makes use of the testprefs text file


### 2019.04.06
- Implemented basic directory structure
- Creation of FileLogger class to easily write to files and log messages
	- Properly working logMessage function
- Creation of FileIO header file for ease of use with FileLogger
- Creation of Game.cpp
	- Class that creates an instance of game and bootstraps
	- Class that will implement main
	- Replacement for main.cpp