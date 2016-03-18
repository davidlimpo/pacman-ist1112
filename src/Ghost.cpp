#include "StdAfx.h"
#include <GL/glut.h>
#include "Ghost.h"

float Ghost::getAxisX(void)
{
	return axeX;
}

float Ghost::getAxisY(void)
{
	return axeY;
}

float Ghost::getSpeed(void)
{
	return speed;
}

float Ghost::getAngle(void)
{
	return angle;
}

void Ghost::setAngle(float a)
{
	angle = a;
}

void Ghost::setUp(void)
{
	up = true;
	down = false;
	left = false;
	right = false;
}

void Ghost::setDown(void)
{
	up = false;
	down = true;
	left = false;
	right = false;
}

void Ghost::setRight(void)
{
	up = false;
	down = false;
	left = false;
	right = true;
}

void Ghost::setLeft(void)
{
	up = false;
	down = false;
	left = true;
	right = false;
}

int Ghost::getDir(void)
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

void Ghost::setAxisX(float n)
{
	axeX += n;
}

void Ghost::setAxisY(float n)
{
	axeY += n;

}

void Ghost::newAxisX(float n)
{
	axeX = n;
}

void Ghost::newAxisY(float n)
{
	axeY = n;
}


void CalculateVectorNormal(float Vert1[], float Vert2[], float Vert3[], float *normalX, float *normalY, float *normalZ)
{
	float Ax, Ay, Az, Bx, By, Bz;

	Ax = Vert2[0] - Vert1[0];
	Ay = Vert2[1] - Vert1[1];
	Az = Vert2[2] - Vert1[2];
	Bx = Vert3[0] - Vert1[0];
	By = Vert3[1] - Vert1[1];
	Bz = Vert3[2] - Vert1[2];

   	*normalX = By*Az - Bz*Ay;
	*normalY = Bz*Ax - Bx*Az;
	*normalZ = Bx*Ay - By*Ax;
}


void Ghost::drawEye(float x, float y, bool effect){

	glPushMatrix();

	if(effect)
	{	//Parte branca
		GLfloat mat_ambient0[] = { 0.7, 0.0, 0.7, 1.0 };
		GLfloat mat_diffuse0[] = { 0.5, 0.0, 0.5, 1.0 };
		GLfloat mat_specular0[] = { 0.7, 0.0, 0.7, 1.0 };
		GLfloat mat_shine0 = 0.25;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient0);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse0);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular0);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine0 * 128);

	}else
	{	//Parte branca
		GLfloat mat_ambient0[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse0[] = { 0.4, 0.4, 0.4, 1.0 };
		GLfloat mat_specular0[] = { 0.774597, 0.774597, 0.774597, 1.0 };
		GLfloat mat_shine0 = 0.6;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient0);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse0);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular0);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine0 * 128);
	}

	glTranslatef(x, y, 0.8);
	glutSolidSphere(0.2, 20, 10);

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
	
	glTranslatef(x, y - 0.15, 0.8);
	glutSolidSphere(0.1, 20, 10);

	glPopMatrix();

}

void Ghost::draw(bool effect, bool spotlight){

	float vertice1[3];
	float vertice2[3];
	float vertice3[3];
	float normalX, normalY, normalZ;

	if(effect)
	{
		GLfloat mat_ambient[] = { 0.9, 0.9, 0.9, 1.0 };
		GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
		GLfloat mat_shine = 0.078125;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);

	} else
	{
		if(!spotlight){
			GLfloat mat_ambient[] = { red, green, blue, 1.0 };
			GLfloat mat_diffuse[] = { 0.4, 0.2, 0, 1.0 };
			GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
			GLfloat mat_shine = 0.6;

			glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);

		}else
		{
			GLfloat mat_ambient[] = { 0, 0, 0, 1.0 };
			GLfloat mat_diffuse[] = { 0.4, 0.2, 0, 1.0 };
			GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
			GLfloat mat_shine = 0.6;

			glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);
		}

	}

	glPushMatrix();
	glTranslatef(axeX, axeY, 0);
	glRotatef(angle, 0, 0, 1);

	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (-0.25, 0.5, 1.0);	//1º

		glVertex3f (-0.5, 0.25, 1.0);	//2º

		glVertex3f (-0.5, -0.25, 1.0);	//3º

		glVertex3f (-0.25, -0.5, 1.0);	//4º

		glVertex3f (0.25, -0.5, 1.0);	//5º

		glVertex3f (0.5, -0.25, 1.0);	//6º

		glVertex3f (0.5, 0.25, 1.0);	//7º

		glVertex3f (0.25, 0.5, 1.0);	//8º
		
	glEnd();


	//1º - 2º
	glBegin(GL_POLYGON);
		vertice1[0] = -0.25;
		vertice2[0] = -0.25;
		vertice3[0] = -0.5;

		vertice1[1] = 0.5;
		vertice2[1] = 0.5;
		vertice3[1] = 0.25;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (-0.25, 0.5, 1.0);	//1º
		glVertex3f (-0.25, 0.5, 0.0);
		glVertex3f (-0.5, 0.25, 0.0);
		glVertex3f (-0.5, 0.25, 1.0);	//2º

	glEnd();


	//2º - 3º
	glBegin(GL_POLYGON);
		vertice1[0] = -0.5;
		vertice2[0] = -0.5;
		vertice3[0] = -0.5;

		vertice1[1] = 0.25;
		vertice2[1] = 0.25;
		vertice3[1] = -0.25;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;
	
		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (-0.5, 0.25, 1.0);	//2º
		glVertex3f (-0.5, 0.25, 0.0);
		glVertex3f (-0.5, -0.25, 0.0);
		glVertex3f (-0.5, -0.25, 1.0);	//3º
	glEnd();

	//3º - 4º
	glBegin(GL_POLYGON);
		vertice1[0] = -0.5;
		vertice2[0] = -0.5;
		vertice3[0] = -0.25;

		vertice1[1] = -0.25;
		vertice2[1] = -0.25;
		vertice3[1] = -0.5;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;
	
		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (-0.5, -0.25, 1.0);	//3º
		glVertex3f (-0.5, -0.25, 0.0);
		glVertex3f (-0.25, -0.5, 0.0);
		glVertex3f (-0.25, -0.5, 1.0);	//4º
	glEnd();

	//4º - 5º
	glBegin(GL_POLYGON);
		vertice1[0] = -0.25;
		vertice2[0] = -0.25;
		vertice3[0] = 0.25;

		vertice1[1] = -0.5;
		vertice2[1] = -0.5;
		vertice3[1] = -0.5;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (-0.25, -0.5, 1.0);	//4º
		glVertex3f (-0.25, -0.5, 0.0);
		glVertex3f (0.25, -0.5, 0.0);
		glVertex3f (0.25, -0.5, 1.0);	//5º
	glEnd();

	//5º - 6º
	glBegin(GL_POLYGON);
		vertice1[0] = 0.25;
		vertice2[0] = 0.25;
		vertice3[0] = 0.5;

		vertice1[1] = -0.5;
		vertice2[1] = -0.5;
		vertice3[1] = -0.25;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (0.25, -0.5, 1.0);	//5º
		glVertex3f (0.25, -0.5, 0.0);
		glVertex3f (0.5, -0.25, 0.0);
		glVertex3f (0.5, -0.25, 1.0);	//6º
	glEnd();

	//6º - 7º
	glBegin(GL_POLYGON);
		vertice1[0] = 0.5;
		vertice2[0] = 0.5;
		vertice3[0] = 0.5;

		vertice1[1] = -0.25;
		vertice2[1] = -0.25;
		vertice3[1] = 0.25;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (0.5, -0.25, 1.0);	//6º
		glVertex3f (0.5, -0.25, 0.0);
		glVertex3f (0.5, 0.25, 0.0);
		glVertex3f (0.5, 0.25, 1.0);	//7º
	glEnd();

	//7º - 8º
	glBegin(GL_POLYGON);
		vertice1[0] = 0.5;
		vertice2[0] = 0.5;
		vertice3[0] = 0.25;

		vertice1[1] = 0.25;
		vertice2[1] = 0.25;
		vertice3[1] = 0.5;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (0.5, 0.25, 1.0);	//7º
		glVertex3f (0.5, 0.25, 0.0);
		glVertex3f (0.25, 0.5, 0.0);
		glVertex3f (0.25, 0.5, 1.0);	//8º
	glEnd();
	

	//8º - 1º
	glBegin(GL_POLYGON);
		vertice1[0] = 0.25;
		vertice2[0] = 0.25;
		vertice3[0] = -0.25;

		vertice1[1] = 0.5;
		vertice2[1] = 0.5;
		vertice3[1] = 0.5;

		vertice1[2] = 0.0;
		vertice2[2] = 1.0;
		vertice3[2] = 0.0;

		CalculateVectorNormal(vertice1, vertice2, vertice3, &normalX, &normalY, &normalZ);

		glNormal3d(normalX, normalY, normalZ);

		glVertex3f (0.25, 0.5, 1.0);	//8º
		glVertex3f (0.25, 0.5, 0.0);
		glVertex3f (-0.25, 0.5, 0.0);
		glVertex3f (-0.25, 0.5, 1.0);	//1º
	glEnd();


	drawEye(-0.2, -0.4, effect);
	drawEye(0.2, -0.4, effect);

	glPopMatrix();
}

void Ghost::move(void){

	if(up)
		setAxisY(1 - getSpeed());

	else if(down)
		setAxisY(-1 + getSpeed());

	else if(left)
		setAxisX(-1 + getSpeed());

	else if(right)
		setAxisX(1 - getSpeed());
}

Ghost::Ghost(GLfloat red, GLfloat green, GLfloat blue, float x, float y)
{
	this->red = red;
	this->green = green;
	this->blue = blue;

	axeX = x;
	axeY = y;

	speed = 0.80;

	setLeft();

	angle = 0;
}


Ghost::~Ghost(void)
{
}