#include<iostream>
using namespace std;

#pragma once;

const int n = 25;
bool GRID[n][n];

void initialize_GRID(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			GRID[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++){
		GRID[i][n - 1] = true;
		GRID[i][0] = true;
	}
	for (int i = 0; i < n; i++){
		GRID[n - 1][i] = true;
		GRID[0][i] = true;
	}
	for (int i = 11; i <= 20; i++) {
		//ram
		GRID[19][i] = true;
		GRID[21][i] = true;
		GRID[23][i] = true;
	}
}

bool checkMovement(float x, float z, int scale){
	int X = (x / scale) + 13;
	int Z = -1 * ((z / scale) - 13);
	cout << X << " " << Z << endl;
	if (GRID[X - 1][Z - 1] == 1) return false;
	return true;
}