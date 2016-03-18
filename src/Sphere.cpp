#include "StdAfx.h"
#include "Sphere.h"
#include <GL/glut.h>



/********************
* draws functions   *
*********************/

void Sphere::draw(float x, float y, float size, GLfloat red, GLfloat green, GLfloat blue, bool darkSide)
{	

	if(darkSide)
	{
	GLfloat mat_ambient[] = { 1, 0.5, 0, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.2, 0, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shine = 0.6;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);

	}

	else
	{
	GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shine = 0.6;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);
	}
	

	glPushMatrix();
	glTranslatef(x,y,0);
	glutSolidSphere(size, 20, 10);
	glFlush();
	glPopMatrix();
}


/********************
*   constructor     *
*********************/

Sphere::Sphere(void)
{
	
}

/********************
*   constructor     *
*********************/

Sphere::~Sphere(void)
{
}
