//***************************************************************************
//  ANT MODEL
//***************************************************************************
#pragma once

#include <glut.h>		
#include "Model_3DS.h"
#include "3DTexture.h"
#include <set>
#include <iostream> 
using namespace std;
class Ant
{
private:
	//AntCoordinates position;	
	Model_3DS ant;
	GLTexture ant_texture;
	float posX, posY, posZ;
	float rotation_angle = 180;

public:
	Ant();
	Ant(GLfloat x, GLfloat y, GLfloat z,float rotate, GLTexture texture, char* path);
	void assignPosition(float x, float z);
	void assignTexture(GLTexture texture); // adds texture to ant
	void draw(); // draws the ant
	pair <float, float> getAntNextStep(float lX, float lY, float lZ, float scale, float speed);
	float get_posX();
	float get_posY();
	float get_posZ();
};


