//	Class where functions that run game will be

#include "Game.h"

//	Initialize the Log class
Log logger;

Game::Game()
{
}


Game::~Game()
{
}

//	Initialize all settings
void Game::InitializeGame()
{
	//	Initializing game
	logger.logInfo("Attempting to initialize game");

	//	Initialize the settings vectors
	initializeSettings();

	logger.logInfo("Finished attempt to initialize game");
}

//	Main game loop
void Game::Run()
{
	while (true) {

	}
}