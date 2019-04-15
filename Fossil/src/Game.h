#pragma once

#include "Settings.h"
#include "Log.h"
#include "GameState.h"
#include "GameStateStack.h"
#include "BuildDll.h"
#include <vector>
#include "glew.h"
#include "glfw3.h"

class FSL_API Game
{
public:
	std::string Name;
	GLFWwindow* GameWindow;

	bool running;

	Game();
	virtual ~Game();

	void InitializeGame();
	void Run();
	void Update();
	void Display();
	void PushState(GameState* state);

private:
	GameStateStack StateStack;
	int GetTickCount();
	std::vector<GameState*> States;
};

//	Definined in client
Game* CreateGame();