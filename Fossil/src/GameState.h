#pragma once

#include <string>
#include "BuildDll.h"
#include "GameObject.h"
#include <vector>
#include "glew.h"
#include "glfw3.h"

class FSL_API GameState
{
public:
	std::vector<GameObject*> Objects;

	GLFWwindow* Window;

	virtual ~GameState();

	virtual void InitializeState() = 0;

	virtual void PauseState() = 0;
	virtual void ResumeState() = 0;

	virtual void UpdateState() = 0;
	virtual void DisplayState() = 0;

protected:
	std::string StateName;
	GameState();
};