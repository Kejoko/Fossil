#include "Game.h"

//	Initialize the Log class
Log logger;

Game::Game()
{
	logger.logInfo("Game.cpp: " + GameName + " | No Args Constructor");
	logger.logMessage(". . . Game Created . . . \n", "gamelogs.txt", true);
	//logger.logInfo("Game Created\n");
}

Game::~Game()
{
	logger.logInfo("Game.cpp: " + GameName + " | Deconstructor");
	logger.logMessage("\n. . . Game Terminated . . .", "gamelogs.txt", false);

	//	Terminate glfw and destroy window
	glfwTerminate();
	glfwDestroyWindow(GameWindow);

	//logger.logInfo("GLFW & Game Terminated\n");
}

//	Initialize all settings
void Game::InitializeGame()
{
	logger.logWarn("Game.cpp: " + GameName + " | InitializeGame");
	//logger.logInfo("Attempting to initialize game");

	//	Initialize the settings vectors
	initializeSettings();

	//	Initialize OpenGL
	if (!glfwInit()) { logger.logError("Unable to initialize GLFW"); }
	GameWindow = glfwCreateWindow(std::stoi(displaySettings.at(0)), std::stoi(displaySettings.at(1)), GameName.c_str(), NULL, NULL);
	if (!GameWindow) {
		logger.logError("Unable to create GameWindow. Terminating.");
		glfwTerminate();
	}
	glfwMakeContextCurrent(GameWindow);

	//logger.logInfo("Finished attempt to initialize game\n");
}

//	Main game loop
void Game::Run()
{
	logger.logInfo("Game.cpp: " + GameName + " | Run");

	//logger.logInfo("Running Game\n");
	while (!glfwWindowShouldClose(GameWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		//Update();
		Display();

		glfwSwapBuffers(GameWindow);

		glfwPollEvents();
	}
}

//	Updates state of the game
void Game::Update()
{
	logger.logInfo("Game.cpp: " + GameName + " | Update");
	//logger.logInfo("Updating Game\n");
	//	Get user input

	//	Update game state
}

//	Displays game to the Window
void Game::Display()
{
	logger.logInfo("Game.cpp: " + GameName + " | Display");

	//	Display the GameStates starting at the bottom of the stack
	for (int i = 0; i < States.size(); i++) {
		States.at(i)->DisplayState();
	}
}

//	Pushes new gamestate to the stack
void Game::PushState(GameState* state)
{
	logger.logInfo("Game.cpp: " + GameName + " | PushState");
	//	Initialize the gamestate then push it to the stack
	state->InitializeState();
	States.push_back(state);
}

//	Returns number of milliseconds elapsed since the system was started
int Game::GetTickCount()
{
	return 0;
}