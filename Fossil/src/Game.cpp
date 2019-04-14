//	Class where functions that run game will be

#include "Game.h"
#include "Settings.h"

//	Initialize the Log class
Log logger;

Game::Game()
{
	logger.logMessage(". . . Game Created . . . \n", "gamelogs.txt", true);

	logger.logInfo("Game Created\n");
}


Game::~Game()
{
	logger.logMessage("\n. . . Game Terminated . . .", "gamelogs.txt", false);

	//	Terminate glfw and destroy window
	glfwTerminate();
	glfwDestroyWindow(GameWindow);

	logger.logInfo("GLFW & Game Terminated\n");
}

//	Initialize all settings
void Game::InitializeGame()
{
	logger.logInfo("Attempting to initialize game");

	//	Initialize the settings vectors
	initializeSettings();

	//	Initialize OpenGL
	if (!glfwInit()) { logger.logError("Unable to initialize GLFW"); }
	GameWindow = glfwCreateWindow(std::stoi(displaySettings.at(0)), std::stoi(displaySettings.at(1)), Name.c_str(), NULL, NULL);
	if (!GameWindow) {
		logger.logError("Unable to create GameWindow. Terminating.");
		glfwTerminate();
	}
	glfwMakeContextCurrent(GameWindow);

	logger.logInfo("Finished attempt to initialize game\n");
}

//	Main game loop
void Game::Run()
{
	logger.logInfo("Running Game\n");
	while (!glfwWindowShouldClose(GameWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		Update();
		Display();

		glfwSwapBuffers(GameWindow);

		glfwPollEvents();
	}

	/*
	while (running) {
		Update();
		Display();
	}
	*/

	//	More complex game loop to be implemented
	/*
	running = true;
	const int TICKS_SEC = 100;
	const int SKIP_TICKS = 1000 / TICKS_SEC;
	const int MAX_FRAMESKIP = 10;

	DWORD next_tick = GetTickCount();
	int loops;

	while (running) {

		loops = 0;
		while (GetTickCount() > next_tick && loops < MAX_FRAMESKIP) {

			next_tick += SKIP_TICKS;
			loops++;
		}

		Display();
	}
	*/

	//	Another possible implementation of game loop
	/*
	int prevTick = GetTickCount();
	int currTick;
	int elapsedTicks;
	while (running) {
		currTick = GetTickCount();
		elapsedTicks = currTick - prevTick;
		prevTick = currTick;
		Update(elapsedTicks);
		Display();
	}
	*/
}

//	Updates state of the game
void Game::Update()
{
	logger.logInfo("Updating Game\n");
	//	Get user input

	//	Update game state
}

//	Displays game to the Window
void Game::Display()
{
	logger.logInfo("Displaying Game\n");
	//	Display the GameStates starting at the bottom of the stack
	for (int i = 0; i < StateStack.NumberStates(); i++) {
		StateStack.FetchState(i)->DisplayState();
	}
}

void Game::PushState(GameState* state)
{
	logger.logInfo("Pushing State\n");
	//	Push game state using StateStack
	StateStack.PushState(state);
}

//	Returns number of milliseconds elapsed since the system was started
int Game::GetTickCount()
{
	return 0;
}