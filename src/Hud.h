#pragma once
class Hud
{
private:
	void drawDigit(int point);
	void drawLifes(int num);

	int uni;
	int dez;
	int cent;

public:

	void draw(int lifes);

	void smallBallPoint(void);
	void bigBallPoint(void);
	void ghostPoint(void);

	Hud(void);
	~Hud(void);
};

