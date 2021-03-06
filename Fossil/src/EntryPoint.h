#pragma once

#include "Game.h"
#include "Settings.h"
#include "Log.h"
#include "BuildDll.h"

//	Defined in Workspace/src/Project.cpp
//extern Game* CreateApplication(std::string GameName);

//	Entry point to game
int main(int argc, char** argv)
{
	//	Create instance of game
	auto game = CreateGame();
	game->InitializeGame();
	game->Run();
	delete game;

	std::cin.get();
}