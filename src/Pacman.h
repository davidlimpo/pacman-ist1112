#pragma once
#include "Pacman.h"
#include "Maze.h"

class Pacman
{

private:
	float axeX;
	float axeY;
	float speed;
	int lives;

	int mover;

	float angle;

	bool up;
	bool down;
	bool left;
	bool right;

public:
	Pacman(float x, float y);
	~Pacman(void);

	void move(void);

	void draw(bool darkSide);
	void drawEye(float x, float y, bool leftEye, bool darkSide);
	void eyeBrow(float x, float y, bool leftEye, bool darkSide);


	float getAxisX(void);
	float getAxisY(void);

	void newAxisX(float n);
	void newAxisY(float n);

	float getSpeed(void);

	int getDir(void);
	int getLives(void);

	void setAxisX(float n);
	void setAxisY(float n);

	void setUp(void);
	void setDown(void);
	void setLeft(void);
	void setRight(void);
	void setLive(void);
};

