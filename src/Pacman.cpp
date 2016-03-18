#include "StdAfx.h"
#include <GL/glut.h>
#include "Pacman.h"
#include "Sphere.h"


/********************
*  get functions    *
*********************/

float Pacman::getAxisX(void)
{
	return axeX;
}

float Pacman::getAxisY(void)
{
	return axeY;
}

float Pacman::getSpeed(void)
{
	return speed;
}

int Pacman::getDir(void)
{
	if(up)
		return 2;
	else if(down)
		return -2;
	else if(left)
		return -1;
	else if(right)
		return 1;
	else
		return 0;
}

int Pacman::getLives(void)
{
	return lives;
}

/********************
*  set functions    *
*********************/

void Pacman::setLive(void)
{
	lives--;
}

void Pacman::setAxisX(float n)
{
	axeX += n;
}

void Pacman::setAxisY(float n)
{
	axeY += n;
}

void Pacman::newAxisX(float n)
{
	axeX = n;
}

void Pacman::newAxisY(float n)
{
	axeY = n;
}

void Pacman::setUp(void)
{
	angle = -90;

	up = true;
	down = false;
	left = false;
	right = false;
}

void Pacman::setDown(void)
{
	angle = 90;

	up = false;
	down = true;
	left = false;
	right = false;
}

void Pacman::setRight(void)
{
	angle = 180;

	up = false;
	down = false;
	left = false;
	right = true;
}

void Pacman::setLeft(void)
{
	angle = 0;

	up = false;
	down = false;
	left = true;
	right = false;
}
	

/********************
* move function   *
*********************/

void Pacman::move(void){

	if(up)
		setAxisY(1 - getSpeed());

	else if(down)
		setAxisY(-1 + getSpeed());

	else if(left)
		setAxisX(-1 + getSpeed());

	else if(right)
		setAxisX(1 - getSpeed());
}


/********************
* draws functions   *
*********************/

void Pacman::eyeBrow(float x, float y, bool leftEye, bool darkSide){

	int rot;

	if (darkSide)
		if(leftEye)
			rot = -45;
		else
			rot = 45;
	else
		rot = 0;

	glPushMatrix();

	GLfloat mat_ambient2[] = { 0.02, 0.02, 0.02, 1.0 };
	GLfloat mat_diffuse2[] = { 0.01, 0.01, 0.01, 1.0 };
	GLfloat mat_specular2[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_shine2 = 0.01;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine2 * 128);

	glTranslatef(x/2 - 0.09, y, 0.4);
	glRotatef(rot, 1, 0, 0);
	glScalef(0.5, 1.8, 1);
	glutSolidSphere(0.08, 20, 10);
	glPopMatrix();
}

void Pacman::drawEye(float x, float y, bool leftEye, bool darkSide)
{

	if(darkSide)
	{	//Parte vermelha
		glPushMatrix();
	
		GLfloat mat_ambient0[] = { 0.466, 0.01175, 0.01175, 1.0 };
		GLfloat mat_diffuse0[] = { 0.61424, 0.04136, 0.04136, 1.0 };
		GLfloat mat_specular0[] = { 0.727811, 0.626959, 0.626959, 1.0 };
		GLfloat mat_shine0 = 0.25;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient0);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse0);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular0);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine0 * 128);

		glTranslatef(x, y, 0.25);
		glutSolidSphere(0.12, 20, 10);
		glPopMatrix();

		//Parte preta
		glPushMatrix();

		GLfloat mat_ambient1[] = { 0.02, 0.02, 0.02, 1.0 };
		GLfloat mat_diffuse1[] = { 0.01, 0.01, 0.01, 1.0 };
		GLfloat mat_specular1[] = { 0.4, 0.4, 0.4, 1.0 };
		GLfloat mat_shine1 = 0.078125;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient1);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse1);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular1);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine1 * 128);

	}else
	{	//Parte branca
		glPushMatrix();
	
		GLfloat mat_ambient0[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse0[] = { 0.4, 0.4, 0.4, 1.0 };
		GLfloat mat_specular0[] = { 0.774597, 0.774597, 0.774597, 1.0 };
		GLfloat mat_shine0 = 0.6;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient0);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse0);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular0);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine0 * 128);

		glTranslatef(x, y, 0.25);
		glutSolidSphere(0.12, 20, 10);
		glPopMatrix();

		//Parte preta
		glPushMatrix();

		GLfloat mat_ambient1[] = { 0.02, 0.02, 0.02, 1.0 };
		GLfloat mat_diffuse1[] = { 0.01, 0.01, 0.01, 1.0 };
		GLfloat mat_specular1[] = { 0.4, 0.4, 0.4, 1.0 };
		GLfloat mat_shine1 = 0.078125;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient1);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse1);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular1);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine1 * 128);
	}

	glTranslatef(x-0.05, y, 0.3);
	glutSolidSphere(0.08, 20, 10);
	glPopMatrix();

	//Sobrancelha
	eyeBrow(x,y, leftEye, darkSide);
}

void Pacman::draw(bool darkSide)
{
	if(darkSide){

	GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shine = 0.6;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);
	}

	else
	{
	GLfloat mat_ambient[] = { 0.329412, 0.223529, 0.027451, 1.0 };
	GLfloat mat_diffuse[] = { 0.780392, 0.568627, 0.113725, 1.0 };
	GLfloat mat_specular[] = { 0.992157, 0.941176, 0.807843, 1.0 };
	GLfloat mat_shine = 0.21794872;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);
	}

	glPushMatrix();
	glTranslatef(axeX,axeY,0);
	glRotatef(angle, 0, 0, 1);

	GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0 };

	GLfloat position[] = {0, 0, 0.5, 1.0};

	GLfloat direction[] = {-1.0, 0.0, -0.2 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
	
	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25.0f); // 0~180
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0f); // 0~128


	glutSolidSphere(0.45, 20, 10);

	//olho direito
	drawEye(-0.23, 0.25, 0, darkSide);

	//olho esquerdo
	drawEye(-0.23, -0.25, 1, darkSide);

	glPopMatrix();
}


/********************
*   constructor     *
*********************/

Pacman::Pacman(float x, float y)
{
	axeX = x;
	axeY = y;

	angle = 0;

	speed = 0.8;
	lives = 5;
	mover = 0;

	setLeft();
}


/********************
*    destructor     *
*********************/

Pacman::~Pacman()
{}