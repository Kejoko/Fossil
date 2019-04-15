#include "GameStateStack.h"

GameStateStack::GameStateStack(){}

GameStateStack::~GameStateStack(){}

//	Sets the GFWwindow
void GameStateStack::SetWindow(GLFWwindow* newWindow)
{
	Window = newWindow;
}

//	Changes game state to state on top of the stack
void GameStateStack::ChangeState(GameState* state)
{

}

void GameStateStack::InsertState(int index, GameState* state)
{
	//states.insert(index, state);
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
