#include "GameObject.h"

GameObject::GameObject() { logger.logInfo("GameObject.cpp: " + ObjectName + " | No Args Constructor"); }

GameObject::GameObject(std::string name, std::string file, GLfloat x, GLfloat y, GLfloat z)
{
	logger.logInfo("GameObject.cpp: " + ObjectName + " | Constructor");
	ObjectName = name;
	xpos = x;
	ypos = y;
	zpos = z;
	ImportOBJ();
}

GameObject::~GameObject() { logger.logInfo("GameObject.cpp: " + ObjectName + " | Constructor"); }

//	Import vertices from a 3d model
void GameObject::ImportOBJ()
{
	logger.logInfo("GameObject.cpp: " + ObjectName + " | ImportOBJ");
	vertices.push_back(-0.5 + xpos);
	vertices.push_back(-0.5 + ypos);
	vertices.push_back(0.0 + zpos);
	vertices.push_back(0.0 + xpos);
	vertices.push_back(0.5 + ypos);
	vertices.push_back(0.0 + zpos);
	vertices.push_back(0.5 + xpos);
	vertices.push_back(-0.5 + ypos);
	vertices.push_back(0.0 + zpos);
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
	logger.logInfo("GameObject.cpp: " + ObjectName + " | ConvertToArrays");

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

void GameObject::DrawObject()
{
	logger.logInfo("GameObject.cpp: " + ObjectName + " | DrawObject");

	GLfloat vertArr[sizeof(vertices)];
	GLfloat textArr[sizeof(textures)];
	GLfloat normsArr[sizeof(normals)];
	int faceArr[sizeof(faces)];
	ConvertToArrays(vertArr, textArr, normsArr, faceArr);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertArr);
	glColorPointer(3, GL_FLOAT, 0, textArr);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void GameObject::MoveObject(GLfloat xdist, GLfloat ydist, GLfloat zdist)
{
	//	Update xpos, ypos, zpos
	xpos += xdist;
	ypos += ydist;
	zpos += zdist;

	//	Update vertices vector
}