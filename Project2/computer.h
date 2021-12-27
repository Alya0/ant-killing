#include "utility.h"

#pragma once


class Computer{
public:
	const float s = 15;   // scale
	const float ground_y = -2;
	// images
	int SKYBOX_UP, SKYBOX_SIDES, SKYBOX_DOWN;
	int BLACK, RAM, GPU_FRONT, GPU_SIDE;



	//functions
	void Draw_ground(float x, float y, float z, float width, float height, float length){
		x = x - width / 2;
		z = z - length / 2;
		//glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, SKYBOX_DOWN);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
		glEnd();
		//glDisable(GL_TEXTURE_2D);
	}

	void Draw_Skybox(float x, float y, float z, float width, float height, float length)
	{
		// Center the Skybox around the given x,y,z position
		x = x - width / 2;
		y = y - height / 2;
		z = z - length / 2;
		//glEnable(GL_TEXTURE_2D);

		// Draw Front side
		glBindTexture(GL_TEXTURE_2D, SKYBOX_SIDES);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
		glEnd();

		// Draw Back side
		glBindTexture(GL_TEXTURE_2D, SKYBOX_SIDES);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glEnd();

		// Draw Left side
		glBindTexture(GL_TEXTURE_2D, SKYBOX_SIDES);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
		glEnd();

		// Draw Right side
		glBindTexture(GL_TEXTURE_2D, SKYBOX_SIDES);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
		glEnd();

		// Draw Up side
		glBindTexture(GL_TEXTURE_2D, SKYBOX_UP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
		glEnd();

		// Draw Down side
		/*glBindTexture(GL_TEXTURE_2D, SKYBOX);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
		glEnd();*/

		glColor3f(1, 1, 1);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//glDisable(GL_TEXTURE_2D);
	}
	
	void Draw_RAM(float x, float y, float z){
		for (int i = 0; i < 3; i++){
			Draw_Building(x + (2*i*s), ground_y, z, 0.1*s, 1 * s, 12 * s, BLACK, BLACK, RAM, RAM, BLACK, BLACK);
		}
	}

	void Draw_GPU(float x, float y, float z, float width, float height, float length){
		Draw_Building(-12 * s, -1, 2 * s, 9 * s, 3 * s, 4 * s, GPU_SIDE, GPU_SIDE, GPU_SIDE, GPU_SIDE, GPU_FRONT, GPU_FRONT);
	}

	void Draw_CPU(){
		// MIRNA
	}

	void Draw_Fan(){
		//MIRNA
	}

	void Draw_Storage(){
		//ALAA
	}
};