#pragma once
#include <windows.h>		// Header File For Windows
#include <gl/GL.h>				// Header File For The OpenGL32 Library
#include <gl/glu.h>	
#include <math.h>
#include<set>

#include "ant.h"

#include <stdlib.h>   /* for exit */
#include <iostream> 

#define SQR(x) (x*x)

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
	ant.Draw();
}


void Ant::moveAnt(float lX, float lZ){
	// integer values here are multiplied by s, which means changing s change these values
	if (sqrt(SQR((ant.pos.x - lX)) + SQR((ant.pos.z - lZ))) > 40){
		// if ant is far away from me it doesnt move;
		return;
	}
	if (abs(lX - ant.pos.x) <= 2 && abs(lZ  - ant.pos.z) <= 2){
		std::cout << "GAME OVER!" ;
		exit(0);
	}

	float X = ant.pos.x;
	float Z = ant.pos.z;
	// make ant pos (0,0) and camera pos relevant to it
	lX -= X;
	lZ -= Z;

	float addX = speed*lX;
	float addZ = speed*lZ;
	 
	//TODO: check for collision
	ant.pos.x += addX;
	ant.pos.z += addZ;
}

float Ant::get_posX(){
	return ant.pos.x;
}

float Ant::get_posY(){
	return ant.pos.y;
}

float Ant::get_posZ(){
	return ant.pos.z;
}
