#include "GameState.h"

GameState::GameState() { logger.logInfo("GameState.cpp: " + StateName + " | No Args Constructor"); }

GameState::~GameState()
{
}

void GameState::DisplayState()
{
	logger.logInfo("GameState.cpp: " + StateName + " | DisplayState");

	//	Loop through objects and draw each one
	for (int i = 0; i < Objects.size(); i++) {
		Objects.at(i)->DrawObject();
	}
}