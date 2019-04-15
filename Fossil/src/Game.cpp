#include "Game.h"

//	Initialize the Log class
Log logger;

const int MAX_VERTICES = 150;

Game::Game()
{
	logger.logWarn("Game.cpp: Game | No Args Constructor");
	logger.logMessage(". . . Game Created . . . \n", "gamelogs.txt", true);
	//logger.logInfo("Game Created\n");
}

Game::~Game()
{
	logger.logWarn("Game.cpp: Game | Deconstructor");
	logger.logMessage("\n. . . Game Terminated . . .", "gamelogs.txt", false);

	//	Terminate glfw and destroy window
	glfwTerminate();
	glfwDestroyWindow(GameWindow);

	//logger.logInfo("GLFW & Game Terminated\n");
}

//	Initialize all settings
void Game::InitializeGame()
{
	logger.logWarn("Game.cpp: Game | InitializeGame");
	//logger.logInfo("Attempting to initialize game");

	//	Initialize the settings vectors
	initializeSettings();

	//	Initialize OpenGL
	if (!glfwInit()) { logger.logError("Unable to initialize GLFW"); }
	GameWindow = glfwCreateWindow(std::stoi(displaySettings.at(0)), std::stoi(displaySettings.at(1)), Name.c_str(), NULL, NULL);
	if (!GameWindow) {
		logger.logError("Unable to create GameWindow. Terminating.");
		glfwTerminate();
	}
	glfwMakeContextCurrent(GameWindow);

	//logger.logInfo("Finished attempt to initialize game\n");
}

//	Main game loop
void Game::Run()
{
	logger.logWarn("Game.cpp: Game | Run");

	//	Testing
	GLfloat normsArr[MAX_VERTICES * 3];
	int faceArr[MAX_VERTICES * 5];
	GLfloat vertArr[9];
	GLfloat textArr[9];

	logger.logWarn("Displaying:" + States.at(0)->Objects.at(0)->ObjectName);
	States.at(0)->Objects.at(0)->ConvertToArrays(vertArr, textArr, normsArr, faceArr);

	//logger.logInfo("Running Game\n");
	while (!glfwWindowShouldClose(GameWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		//Update();
		//Display();

		//	Copied from display
		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertArr);
		//glVertexPointer(3, GL_FLOAT, 0, textArr);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		//	End of copy from display()

		glfwSwapBuffers(GameWindow);

		glfwPollEvents();
	}

	/*
	while (running) {
		Update();
		Display();
	}
	*/

	//	More complex game loop to be implemented
	/*
	running = true;
	const int TICKS_SEC = 100;
	const int SKIP_TICKS = 1000 / TICKS_SEC;
	const int MAX_FRAMESKIP = 10;

	DWORD next_tick = GetTickCount();
	int loops;

	while (running) {

		loops = 0;
		while (GetTickCount() > next_tick && loops < MAX_FRAMESKIP) {

			next_tick += SKIP_TICKS;
			loops++;
		}

		Display();
	}
	*/

	//	Another possible implementation of game loop
	/*
	int prevTick = GetTickCount();
	int currTick;
	int elapsedTicks;
	while (running) {
		currTick = GetTickCount();
		elapsedTicks = currTick - prevTick;
		prevTick = currTick;
		Update(elapsedTicks);
		Display();
	}
	*/
}

//	Updates state of the game
void Game::Update()
{
	logger.logWarn("Game.cpp: Game | Update");
	//logger.logInfo("Updating Game\n");
	//	Get user input

	//	Update game state
}

//	Displays game to the Window
void Game::Display()
{
	logger.logWarn("Game.cpp: Game | Display");
	//logger.logInfo("Displaying Game");

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//	Display the GameStates starting at the bottom of the stack
	//for (int i = 0; i < States.size(); i++) {
		
		//GLfloat vertArr[MAX_VERTICES * 3];
		//GLfloat textArr[MAX_VERTICES * 5];
		
		GLfloat normsArr[MAX_VERTICES * 3];
		int faceArr[MAX_VERTICES * 5];

		GLfloat vertArr[9];
		GLfloat textArr[9];

		//	Loop through all objects in current state
		//for (int j = 0; i < States.at(i)->Objects.size(); j++) {

			logger.logWarn("Displaying:" + States.at(0)->Objects.at(0)->ObjectName);
			States.at(0)->Objects.at(0)->ConvertToArrays(vertArr, textArr, normsArr, faceArr);

			glVertexPointer(3, GL_FLOAT, 0, vertArr);
			glVertexPointer(3, GL_FLOAT, 0, textArr);
			glDrawArrays(GL_TRIANGLES, 0, 3);

		//}
	//}
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

//	Pushes new gamestate to the stack
void Game::PushState(GameState* state)
{
	logger.logWarn("Game.cpp: Game | PushState");
	//	Initialize the gamestate then push it to the stack
	state->InitializeState();
	States.push_back(state);
}

//	Returns number of milliseconds elapsed since the system was started
int Game::GetTickCount()
{
	return 0;
}