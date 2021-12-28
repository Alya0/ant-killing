#include<iostream>
using namespace std;

#pragma once;

static const int n = 52;
static bool GRID[n][n];

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

}

static bool checkMovement(float x, float z, int scale){
	int X = (((x * 2) / scale) - 26) * -1;
	int Z = ((z * (-1*2)) / scale) + 26;
	//cout << X << " " << Z << " " << GRID[X][Z] << endl;
	if (GRID[X][Z] == 1){
		cout << "cant proceed!"<<endl;
		return false;
	}
	return true;
}