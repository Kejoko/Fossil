#pragma once

#include <vector>
#include <string>
#include "BuildDll.h"
#include "GameObject.h"
#include "glew.h"
#include "glfw3.h"

class FSL_API GameState
{
public:
	std::string StateName;
	std::vector<GameObject*> Objects;
	
	virtual ~GameState();

	virtual void InitializeState() = 0;

	virtual void PauseState() = 0;
	virtual void ResumeState() = 0;

	virtual void UpdateState() = 0;
	void DisplayState();

protected:
	GameState();
};