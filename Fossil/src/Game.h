#pragma once

#include "Settings.h"
#include "Log.h"
#include "BuildDll.h"

class FSL_API Game
{
public:
	Game();
	virtual ~Game();

	void InitializeGame();
	void Run();
};

//	Definined in client
Game* CreateGame();