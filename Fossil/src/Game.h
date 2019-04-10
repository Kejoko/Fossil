#pragma once

#include "Settings.h"
#include "Log.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void InitializeGame();
	void Run();
};

extern Game game;