#include "Fossil.h"

class Workspace : public Game
{
public:
	Workspace()
	{
	}

	~Workspace()
	{
	}
};

//	Create new game pointer
Game* CreateGame() {
	return new Workspace();
}