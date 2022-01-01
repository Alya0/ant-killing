#pragma once
#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>	
#include <math.h>
#include <cmath>
#include<set>

#include "ant.h"

#include <stdlib.h>   /* for exit */
#include <iostream> 
using namespace std;

#define SQR(x) (x*x)

Ant::Ant(){
}

Ant::Ant(GLfloat x, GLfloat y, GLfloat z,float rotate,  GLTexture texture, char* path){
	ant = Model_3DS();
	ant.Load(path);
	ant.pos.x = 0;
	ant.pos.y = 0;
	ant.pos.z = 0;
	ant.scale = 0.05; //0.025
	ant_texture = texture;
	rotation_angle = rotate;
	posX = x;
	posY = y;
	posZ = z;
}



void Ant::draw(){
	ant.Materials[0].tex = ant_texture;
	glPushMatrix();
	glTranslated(posX, posY, posZ);
	glRotated(rotation_angle, 0, 1, 0);
	ant.Draw();
	glPopMatrix();
}


pair<float, float> Ant::getAntNextStep(float lX, float lY, float lZ, float scale){
	if (sqrt(SQR((posX - lX)) + SQR((posZ - lZ))) > 4*scale){                         // ant is far away
		return {posX, posZ};
	}
	if (abs(lX - posX) <= 2 && abs(lZ - posZ) <= 0.2*scale){                             // ant reached my pos
		std::cout << "GAME OVER!" ;
		exit(0);
	}

	float X = posX;
	float Z = posZ;
	float Y = posY;
	// make ant pos (0,0) and camera pos relevant to it
	lX -= X;
	lZ -= Z;
	float addX = (speed)*lX;
	float addZ = (speed)*lZ; 
	 
	float newX = posX + addX;
	float newZ = posZ + addZ;
	return { newX, newZ };
}


void Ant::assignPosition(float x, float z){
	posX = x;
	posZ = z;
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
