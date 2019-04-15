#pragma once

#include <vector>
#include <string>
#include "BuildDll.h"
#include "Settings.h"
#include "glew.h"

class FSL_API GameObject
{
public:
	std::string ObjectName;
	std::string FilePath;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> textures;
	std::vector<GLfloat> normals;
	std::vector<int> faces;
	bool Visible = true;

	GameObject();
	GameObject(std::string name, std::string file);
	~GameObject();

	void ImportOBJ();

	void ConvertToArrays(GLfloat* verts, GLfloat* txtrs, GLfloat* norms, int* face);

};

