#pragma once

#include <vector>
#include <string>
#include "BuildDll.h"
#include "Settings.h"
#include "Log.h"
#include "GameState.h"
#include "GameObject.h"
#include "glew.h"
#include "glfw3.h"

class FSL_API Game
{
public:
	std::string GameName;
	GLFWwindow* GameWindow;
	std::vector<GameState*> States;

	bool running;

	Game();
	virtual ~Game();

	void InitializeGame();
	void Run();
	void Update();
	void Display();
	void PushState(GameState* state);

private:
	int GetTickCount();
};

//	Definined in client
Game* CreateGame();