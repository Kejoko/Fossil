#include "GameStateStack.h"

GameStateStack::GameStateStack()
{
}

GameStateStack::~GameStateStack()
{
}

//	Changes game state to state on top of the stack
void GameStateStack::ChangeState(GameState* state)
{

}

//	Pushes new game state to the top of the stack
void GameStateStack::PushState(GameState* state)
{
	states.push_back(state);
}

//	Get next game state on stack
void GameStateStack::PopState()
{
	states.pop_back();
}
