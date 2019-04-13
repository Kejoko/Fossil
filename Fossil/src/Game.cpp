//	Class where functions that run game will be

#include "Game.h"

//	Initialize the Log class
Log logger;

Game::Game()
{
	//	Log message noting that the game has been created
	logger.logMessage(". . . Game Created . . . \n", "gamelogs.txt", true);

	//	Log info that game was created
	logger.logInfo("Game Created");
}


Game::~Game()
{
	//	Log message noting that the game has exited
	logger.logMessage("\n. . . Game Terminated . . .", "gamelogs.txt", false);

	//	Log info that game was created
	logger.logInfo("Game Terminated");
}

//	Initialize all settings
void Game::InitializeGame()
{
	logger.logInfo("Attempting to initialize game");

	//	Initialize the settings vectors
	initializeSettings();

	//	Initialize OpenGL window


	logger.logInfo("Finished attempt to initialize game");
}

//	Main game loop
void Game::Run()
{

	while (running) {
		Update();
		Display();
	}

	//	More complex game loop to be implemented
	/*
	isRunning = true;
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
}

//	Updates state of the game
void Game::Update()
{
	//	Get user input

	//	Update game state
}

//	Displays game to the Window
void Game::Display()
{
	//	Display the GameStates starting at the bottom of the stack
	for (int i = 0; i < StateStack.NumberStates(); i++) {
		StateStack.FetchState(i)->DisplayState();
	}
}

void Game::PushState(GameState * state)
{
	//	Push game state using StateStack
	StateStack.PushState(state);
}

//	Returns number of milliseconds elapsed since the system was started
int Game::GetTickCount()
{
	return 0;
}