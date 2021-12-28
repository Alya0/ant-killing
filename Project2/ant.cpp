#pragma once
#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>	
#include <math.h>
#include<set>

#include "ant.h"

#include <stdlib.h>   /* for exit */

Ant::Ant(){
}

Ant::Ant(GLfloat x, GLfloat y, GLfloat z, GLTexture texture, char* path){
	ant = Model_3DS();
	ant.Load(path);
	ant.pos.x = x;
	ant.pos.y = y;
	ant.pos.z = z;
	ant.scale = 0.05; //0.025
	ant_texture = texture;
	posX = x;
	posY = y;
	posZ = z;
}


void Ant::draw(){
	ant.Materials[0].tex = ant_texture;
//	ant.Materials[1].tex = ant_texture;
	ant.Draw();
}

float Ant::get_posX(){
	return posX;
}

float Ant::get_posY(){
	return posY;
}

float Ant::get_posZ(){
	return posZ;
}
