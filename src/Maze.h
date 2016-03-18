#pragma once
#include "Sphere.h"
#include "Pacman.h"
#include "Cube.h"

typedef int MazeMatrix[24][24];

class Maze
{

int mazeMatrix[24][24];

public:

	Maze(void);
	~Maze(void);

	void draw(bool darkSide);

	int getMaze(int x, int y);
	void setMaze(int x, int y, int k);

};

