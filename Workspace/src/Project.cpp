#include "Fossil.h"

Log wkspcLog;

class GS_StartScreen : public GameState
{
public:

	GS_StartScreen() : GameState(){}

	GS_StartScreen(std::string name, GLFWwindow* newWindow)
	{
		wkspcLog.logWarn("Start Screen Created\n");

		StateName = name;
		Window = newWindow;

		Objects.at(0) = new GameObject("Triangle", "NoFileYet");
	}

	void InitializeState() {}

	void PauseState() {}

	void ResumeState() {}

	void UpdateState() {}

	void DisplayState() {}
};

class Workspace : public Game
{
public:
	Workspace()
	{
		Name = "Sub to Pewds";

		wkspcLog.logWarn("Workspace Created\n");

		//	Push start up screen to the stack
		PushState(new GS_StartScreen("Start Screen", GameWindow));
	}

	~Workspace() {}
};

//	Create new game pointer
Game* CreateGame() {
	return new Workspace();
}