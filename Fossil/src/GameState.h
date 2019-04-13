#pragma once

#include "BuildDll.h"

class FSL_API GameState
{
public:
	virtual ~GameState();

	virtual void InitializeState() = 0;

	virtual void PauseState() = 0;
	virtual void ResumeState() = 0;

	virtual void UpdateState() = 0;
	virtual void DisplayState() = 0;

protected:
	GameState();
};