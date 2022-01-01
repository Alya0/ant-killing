#include<iostream>
using namespace std;

#pragma once;

static const int n = 52;
static bool GRID[n][n];
static bool Bullet_GRID[n][n];

static void initialize_GRID(){
	// all false
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			GRID[i][j] = false;
		}
	}
	// skybox borders
	for (int i = 0; i < n; i++){
		GRID[i][n - 1] = true;
		GRID[i][0] = true;
	}
	for (int i = 0; i < n; i++){
		GRID[n - 1][i] = true;
		GRID[0][i] = true;
	}
	// ram borders
	for (int i = 24; i <= 47; i++) {
		GRID[11][i] = true;
		GRID[7][i] = true;
		GRID[3][i] = true;
	}
	// ram Glass borders
	for (int i = 22; i <= 49; i++){
		GRID[13][i] = true;
		GRID[2][i] = true;
	}
	for (int i = 13; i >= 2; i--){
		GRID[i][49] = true;
	}

	//cpu borders
	for (int i = 17; i >= 4; i--){
		GRID[i][16] = true;
	} 
	for (int i = 15; i >= 0; i--){
		GRID[3][i] = true;
		if (i != 8 && i != 7){
			GRID[18][i] = true;
		}
	}
	// cpu inside
	for (int i = 12; i >= 8; i--){
		GRID[i][13] = true;
		GRID[i][9] = true;
		GRID[i][6] = true;
		GRID[i][2] = true;
	}
	for (int i = 9; i >= 6; i--){
		GRID[9][i] = true;
		GRID[12][i] = true;
	}
	for (int i = 11; i >= 5; i -= 3){
		GRID[15][i] = true;
		GRID[6][i] = true;
	}
	GRID[16][1] = true;
	GRID[16][14] = true;
	GRID[5][1] = true;
	GRID[5][14] = true;

	//SSD borders
	for (int i = 47; i >= 18; i--){
		GRID[i][33] = true;
		GRID[i][50] = true;
	}
	for (int i = 50; i >= 33; i--){
		//GRID[50][i] = true;
		GRID[18][i] = true;
	}
	//SSD inside borders (vertical)
	for (int i = 47; i >= 36; i--){
		GRID[47][i] = true;
		GRID[44][i] = true;
		GRID[39][i] = true;
		GRID[36][i] = true;
		GRID[31][i] = true;
		GRID[28][i] = true;
		GRID[23][i] = true;
		GRID[20][i] = true;
	}
	//SSD inside borders (horizontal)
	for (int i = 0; i < 4; i++){
		GRID[44 + i][47] = true;
		GRID[36 + i][47] = true;
		GRID[28 + i][47] = true;
		GRID[20 + i][47] = true;
		GRID[44 + i][36] = true;
		GRID[36 + i][36] = true;
		GRID[28 + i][36] = true;
		GRID[20 + i][36] = true;

	}
}

static void initialize_Bullet_GRID(){
	// all false
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			Bullet_GRID[i][j] = false;
		}
	}
	// skybox borders
	for (int i = 0; i < n; i++){
		Bullet_GRID[i][n - 1] = true;
		Bullet_GRID[i][0] = true;
	}
	for (int i = 0; i < n; i++){
		Bullet_GRID[n - 1][i] = true;
		Bullet_GRID[0][i] = true;
	}
	// ram borders
	for (int i = 24; i <= 47; i++) {
		Bullet_GRID[11][i] = true;
		Bullet_GRID[7][i] = true;
		Bullet_GRID[3][i] = true;
	}
	// ram Glass borders
	for (int i = 22; i <= 49; i++){
		Bullet_GRID[13][i] = true;
		Bullet_GRID[2][i] = true;
	}
	for (int i = 13; i >= 2; i--){
		Bullet_GRID[i][49] = true;
	}

	//cpu borders
	for (int i = 17; i >= 4; i--){
		Bullet_GRID[i][16] = true;
	}
	for (int i = 15; i >= 0; i--){
		Bullet_GRID[3][i] = true;
		if (i != 8 && i != 7){
			Bullet_GRID[18][i] = true;
		}
	}
	//SSD borders
	for (int i = 47; i >= 18; i--){
		Bullet_GRID[i][33] = true;
		Bullet_GRID[i][50] = true;
	}
	for (int i = 50; i >= 33; i--){
		//GRID[50][i] = true;
		Bullet_GRID[18][i] = true;
	}
}

static bool checkMovement(float x, float z, float scale){
	int X = (((x * 2) / scale) - 26) * -1;
	int Z = ((z * (-1*2)) / scale) + 26;
	//cout << X << " " << Z << " " << GRID[X][Z] << endl;
	if (GRID[X][Z] == 1){
		//cout << "cant proceed!"<<endl;
		return false;
	}
	return true;
}

static bool checkBulletMovement(float x, float z, float scale){
	int X = (((x * 2) / scale) - 26) * -1;
	int Z = ((z * (-1 * 2)) / scale) + 26;
	//cout << X << " " << Z << " " << GRID[X][Z] << endl;
	if (Bullet_GRID[X][Z] == 1){
		//cout << "cant proceed!"<<endl;
		return false;
	}
	return true;
}