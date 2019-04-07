# Project Fossil
Project Fossil is a game engine that I am creating using C++ and OpenGL. I aam creating this engine with the intention of better learning C++, project organization, game engine architecture, and basic game design.

Goals:
While I am unsure exactly what the final game will look like, I have a few ideas and details that I am going to keep in mind while constructing this engine.
I would like the game to be 3 dimensional and 3rd person.
The character will move around via input from the mouse (clicking where you would like the character to move to).
The camera will be able to pan/rotate around the character and be able to zoom.
The core gameplay will take place in a procedurally generated dungeon.
The player may enter combat in the dungeons, and combat will be turn based.
Dungeons will contain collectables.
The player will have a party system.
Cross platform multiplayer will be supported.

To-Do:
This is a tentative list of features that I plan on implementing. I may implement them in an order differing from the order I have listed.
Upon implementation of a feature more information and details will be recorded.
	(** denotes that this feature may not be implemented.)
1) Boot Strapping
	- Opening a window
	- Logging for trouble shooting
2) File System access
	- Reading and writing files
	- Methods for ease and simplification
3) **Networking layer
	- Communication between two clients
4) Graphics API
	- Initialization and interaction with OpenGL
5) Asset Pipeline
	- Determination of how assets will be imported
	- Object animator
6) Player Interaction & UI
	- Implement player input
7) World & Scene Creation
	- Game world & level creation
	- Lighting
	- Camera functionality
8) **Client Communicaton regarding Game Objects
	- Proper display and logging of objects
	- Synchronization of game world
9) Physics
	- Objects interaction with game world
	- **Synchronized updates between clients
10) Tools
	- Asset importer
	- Level editor