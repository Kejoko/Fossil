#include "GameObject.h"

GameObject::GameObject() { logger.logWarn("GameObject.cpp: GameObject | No Args Constructor"); }

GameObject::GameObject(std::string name, std::string file)
{
	logger.logWarn("GameObject.cpp: GameObject | Constructor");
	ObjectName = name;
	ImportOBJ();
}

GameObject::~GameObject() { logger.logWarn("GameObject.cpp: GameObject | Constructor"); }

//	Import vertices from a 3d model
void GameObject::ImportOBJ()
{
	logger.logWarn("GameObject.cpp: GameObject | ImportOBJ");
	vertices.push_back(-0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0.0);
	vertices.push_back(0.0);
	vertices.push_back(0.5);
	vertices.push_back(0.0);
	vertices.push_back(0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0.0);
	textures.push_back(255);
	textures.push_back(0.0);
	textures.push_back(0.0);
	textures.push_back(0.0);
	textures.push_back(255);
	textures.push_back(0.0);
	textures.push_back(0.0);
	textures.push_back(0.0);
	textures.push_back(255);
}

void GameObject::ConvertToArrays(GLfloat *verts, GLfloat *txtrs, GLfloat *norms, int *face)
{
	logger.logWarn("GameObject.cpp: GameObject | ConvertToArrays");

	//	Copy vertices vector
	for (int i = 0; i < vertices.size(); i++) {
		verts[i] = vertices.at(i);
	}

	//	Copy textures vector
	for (int i = 0; i < textures.size(); i++) {
		txtrs[i] = textures.at(i);
	}

	//	Copy normals vector
	for (int i = 0; i < normals.size(); i++) {
		norms[i] = normals.at(i);
	}

	//	Copy faces vector
	for (int i = 0; i < faces.size(); i++) {
		face[i] = faces.at(i);
	}
}