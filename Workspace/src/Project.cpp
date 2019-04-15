#include "Fossil.h"

Log wkspcLog;

class GS_StartScreen : public GameState
{
public:

	GS_StartScreen() : GameState() { wkspcLog.logWarn("Project.cpp: GS_StartScreen | No Args Constructor"); }

	GS_StartScreen(std::string name, GLFWwindow* newWindow)
	{
		wkspcLog.logWarn("Project.cpp: GS_StartScreen | Constructor");

		StateName = name;
		Window = newWindow;

		Objects.push_back(new GameObject("Triangle", "NoFileYet"));
	}

	~GS_StartScreen() { wkspcLog.logWarn("Project.cpp: GS_StartScreen | Deconstructor"); }

	void InitializeState() { wkspcLog.logWarn("Project.cpp: GS_StartScreen | InitializeState"); }

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

		wkspcLog.logWarn("Project.cpp: Workspace | No Args Constructor");

		//	Push start up screen to the stack
		PushState(new GS_StartScreen("Start Screen", GameWindow));
		//States.push_back(new GS_StartScreen("Start Screen", GameWindow));
	}

	~Workspace() { wkspcLog.logWarn("Project.cpp: Workspace | Deconstructor"); }
};

//	Create new game pointer
Game* CreateGame() {
	wkspcLog.logWarn("Project.cpp: | CreateGame");
	return new Workspace();
}