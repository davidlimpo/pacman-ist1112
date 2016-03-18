#include "StdAfx.h"
#include <GL/glut.h>
#include "Camera.h"


void Camera::camOne(float r, float w, float h)
{
	glViewport(0, 0, w, 700);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(r > 1)
		glOrtho(0.0f*r, 24.0f*r, 0.0f, 24.0f, -24.0f, 24.0f);
	else
		glOrtho(0.0f, 24.0f, 0.0f/r, 24.0f/r, -24.0f, 24.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Camera::camTwo(int x, int y, float w, float h, float r)
{
		glViewport(0, 0, w, 700);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70,r,0.1,35);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

}

Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}
