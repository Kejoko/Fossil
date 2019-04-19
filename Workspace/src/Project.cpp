#include "Fossil.h"

Log wkspcLog;

class GS_StartScreen : public GameState
{
public:

	GS_StartScreen() : GameState() { wkspcLog.logInfo("Project.cpp: GS_StartScreen | No Args Constructor"); }

	GS_StartScreen(std::string name)
	{
		wkspcLog.logInfo("Project.cpp: GS_StartScreen | Constructor");

		StateName = name;

		Objects.push_back(new GameObject("Triangle", "NoFileYet", 0.0, 0.0, 0));
		Objects.push_back(new GameObject("Triangle2", "NoFileYet", -0.25, -0.25, 0));
	}

	~GS_StartScreen() { wkspcLog.logInfo("Project.cpp: GS_StartScreen | Deconstructor"); }

	void InitializeState() { wkspcLog.logInfo("Project.cpp: GS_StartScreen | InitializeState"); }

	void PauseState() {}

	void ResumeState() {}

	void UpdateState() {}
};

class Workspace : public Game
{
public:
	Workspace()
	{
		GameName = "Sub to Pewds";

		wkspcLog.logInfo("Project.cpp: Workspace | No Args Constructor");

		//	Push start up screen to the stack
		PushState(new GS_StartScreen("Start Screen"));
	}

	~Workspace() { wkspcLog.logInfo("Project.cpp: Workspace | Deconstructor"); }
};

//	Create new game pointer
Game* CreateGame() {
	wkspcLog.logInfo("Project.cpp: | CreateGame");
	return new Workspace();
}