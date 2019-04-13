#pragma once

#include "BuildDll.h"
#include "GameState.h"
#include <vector>

class FSL_API GameStateStack
{
public:
	GameStateStack();
	~GameStateStack();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	int NumberStates() { return states.size(); }
	GameState* FetchState(int i) { return states.at(i); }

private:
	std::vector<GameState*> states;
};

