#pragma once

#include "Settings.h"
#include "Log.h"
#include "BuildDll.h"

class FSL_API Game
{
public:
	bool running;

	Game();
	virtual ~Game();

	void InitializeGame();
	void Run();
	void Update();
	void Display();
	
	int GetTickCount();
};

//	Definined in client
Game* CreateGame();