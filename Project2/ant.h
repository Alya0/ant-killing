//***************************************************************************
//  ANT MODEL
//***************************************************************************
#pragma once

#include <glut.h>		
#include "Model_3DS.h"
#include "3DTexture.h"
#include <set>

class Ant
{
private:
	//AntCoordinates position;	
	Model_3DS ant;
	GLTexture ant_texture;
	float posX, posY, posZ;

public:
	Ant();
	Ant(GLfloat x, GLfloat y, GLfloat z, GLTexture texture, char* path);
	void assignPosition();
	void assignTexture(GLTexture texture); // adds texture to ant
	void draw(); // draws the ant
	float get_posX();
	float get_posY();
	float get_posZ();
};


