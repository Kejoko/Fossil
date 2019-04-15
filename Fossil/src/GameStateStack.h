#pragma once

#include "BuildDll.h"
#include "GameState.h"
#include <vector>
#include "glew.h"
#include "glfw3.h"

class FSL_API GameStateStack
{
public:
	GLFWwindow* Window;
	GameStateStack();
	~GameStateStack();

	void SetWindow(GLFWwindow* newWindow);

	void ChangeState(GameState* state);
	void InsertState(int index, GameState* state);
	void PushState(GameState* state);
	void PopState();

	int NumberStates() { return (int)states.size(); }
	GameState* FetchState(int i) { return states.at(i); }

private:
	std::vector<GameState*> states;
};

