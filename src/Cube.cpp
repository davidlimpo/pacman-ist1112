#include "StdAfx.h"
#include "Cube.h"
#include <GL/glut.h>




/********************
* draws functions   *
*********************/

void Cube::draw(float x, float y, float size, GLfloat red, GLfloat green, GLfloat blue)
{

	GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.7, 0.6, 0.6, 1.0 };
	GLfloat mat_shine = 0.25;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128.0);


	glPushMatrix();
	glTranslatef(x,y,0);
	glutSolidCube(size);
	glFlush();
	glPopMatrix();
	glEnd();

}

/********************
*   constructor     *
*********************/

Cube::Cube(void)
{

}

/********************
*   constructor     *
*********************/

Cube::~Cube(void)
{
}
