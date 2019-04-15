#include "GameObject.h"

GameObject::GameObject() {}

GameObject::GameObject(std::string name, std::string file)
{
	ObjectName = name;
	logger.logWarn(ObjectName + " Constructed\n");
	ImportOBJ();
}

GameObject::~GameObject() {}

//	Import vertices from a 3d model
void GameObject::ImportOBJ()
{
	vertices.at(0) = -0.5;
	vertices.at(1) = -0.5;
	vertices.at(2) = 0.0;
	vertices.at(3) = 0.0;
	vertices.at(4) = 0.5;
	vertices.at(5) = 0.0;
	vertices.at(6) = 0.5;
	vertices.at(7) = -0.5;
	vertices.at(8) = 0.0;
	textures.at(0) = 255;
	textures.at(1) = 0.0;
	textures.at(2) = 0.0;
	textures.at(3) = 0.0;
	textures.at(4) = 255;
	textures.at(5) = 0.0;
	textures.at(6) = 0.0;
	textures.at(7) = 0.0;
	textures.at(8) = 255;
	logger.logWarn("OBJ Imported\n");
}

void GameObject::ConvertToArrays(GLfloat *verts, GLfloat *txtrs, GLfloat *norms, int *face)
{
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