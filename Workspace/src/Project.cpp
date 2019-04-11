#include "Fossil.h"

Log logger2;

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

int main()
{

	//	Log message noting that the game started
	logger2.logMessage(". . . Starting . . . \n", "gamelogs.txt", true);

	//	Create instance of game
	Workspace game = Workspace();
	game.InitializeGame();
	game.Run();

	//	Log message noting that the game has exited
	logger2.logMessage("\n . . . Ending . . .", "gamelogs.txt", false);
}