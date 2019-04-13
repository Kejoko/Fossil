#include "Fossil.h"

Log wkspcLog;

class GS_StartScreen : public GameState
{
public:
	GS_StartScreen() : GameState() {}

	void InitializeState()
	{
		//	Create an object to be drawn
	}

	void PauseState() {}

	void ResumeState() {}

	void UpdateState()
	{
		//	Animate the object
	}

	void DisplayState()
	{
		//	Draw object to the window
	}
};

class Workspace : public Game
{
public:
	Workspace()
	{
		//	Push start up screen to the stack
		PushState(new GS_StartScreen);
	}

	~Workspace()
	{
	}
};

//	Create new game pointer
Game* CreateGame() {
	return new Workspace();
}