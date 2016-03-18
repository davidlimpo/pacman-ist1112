#pragma once
class SP
{

private: 

	float axeX;
	float axeY;
	float axeZ;
	float direction;
	float speedX;
	float speedY;
	float speedZ;
	float randX;
	float randY;
	float randZ;
	float randomR;
	float randomG;
	float randomB;

public:
	SP(void);
	~SP(void);


	void setRandX(float r);
	float getRandX(void);
	void setRandY(float r);
	float getRandY(void);
	void setRandZ(float r);
	float getRandZ(void);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void addX(float x);
	void addY(float y);
	void addZ(float z);
	float getZ(void);
	void setColor(float r, float g, float b);

	void draw(void);
};

