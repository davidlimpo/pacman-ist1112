#include "StdAfx.h"
#include "SP.h"
#include <GL/glut.h>

void SP::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	randomR = r;
	randomG = g;
	randomB = b;
}

void SP::setRandX(float r)
{
	randX = r;
}

float SP::getRandX(void)
{
	return randX;
}

void SP::setRandY(float r)
{
	randY = r;
}

float SP::getRandY(void)
{
	return randY;
}

void SP::setRandZ(float r)
{
	randZ = r;
}

float SP::getRandZ(void)
{
	return randZ;
}

void SP::setX(float x)
{
	axeX = x;
}

void SP::setY(float y)
{
	axeY = y;
}

void SP::setZ(float z)
{
	axeZ = z;
}

void SP::addX(float x)
{
	axeX += x;
}

void SP::addY(float y)
{
	axeY += y;
}

void SP::addZ(float z)
{
	axeZ += z;
}

float SP::getZ(void)
{
	return axeZ;
}


void SP::draw(void)
{
	glPushMatrix();
	
	GLfloat mat_ambient[] = { randomR, randomG, randomB, 1.0 };
	GLfloat mat_diffuse[] = { randomR, randomG, randomB, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shine = 0.6;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);

	glTranslatef(axeX, axeY, axeZ);
	glutSolidSphere(0.15, 10, 10);
	
	glPopMatrix();
}

SP::SP(void)
{
	axeX = 0;
	axeY = 0;
	axeZ = 0.45;
}

SP::~SP(void)
{
}
