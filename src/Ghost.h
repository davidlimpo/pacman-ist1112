#pragma once
class Ghost
{
private:
	GLfloat red;
	GLfloat green;
	GLfloat blue;

	float axeX;
	float axeY;
	float angle;

	int dir;
	float speed;

	bool up;
	bool down;
	bool left;
	bool right;

public:
	Ghost(GLfloat red, GLfloat green, GLfloat blue, float x, float y);
	~Ghost(void);

	void draw(bool effect, bool spotlight);
	void drawEye(float x, float y, bool effect);
	float getAxisX(void);
	float getAxisY(void);
	int getDir(void);
	float getSpeed(void);
	float getAngle(void);

	void setAxisX(float n);
	void setAxisY(float n);

	void newAxisX(float n);
	void newAxisY(float n);

	void setAngle(float a);
	void setUp(void);
	void setDown(void);
	void setLeft(void);
	void setRight(void);

	void move(void);
};