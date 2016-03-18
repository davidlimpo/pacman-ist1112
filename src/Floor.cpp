#include "StdAfx.h"
#include <GL/glut.h>
#include "Floor.h"

GLubyte *raw_bitmap ;

#define stripeImageWidth 32
GLubyte stripeImage[4*stripeImageWidth];
static GLuint texName;
void makeStripeImage(void)
{
	int j;
	
	for (j = 0; j < stripeImageWidth; j++)
	{
		stripeImage[4*j] = (GLubyte) ((j<=4) ? 255 : 0);
		stripeImage[4*j+1] = (GLubyte) ((j>4) ? 255 : 0);
		stripeImage[4*j+2] = (GLubyte) 0;stripeImage[4*j+3] = (GLubyte) 255;
	}
}

static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};
static GLfloat *currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;

void Floor::draw(void){

	glPushMatrix();

	GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.3, 0.01, 0.2, 1.0 };
	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_shine = 0.25;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine * 128);


	// TEXTURA

	glShadeModel(GL_SMOOTH);
	makeStripeImage();
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	currentCoeff = xequalzero;
	currentGenMode = GL_OBJECT_LINEAR;
	currentPlane = GL_OBJECT_PLANE;
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
	glTexGenfv(GL_S, currentPlane, currentCoeff);
	glEnable(GL_TEXTURE_GEN_S);

	glEnable(GL_TEXTURE_1D);




	// ******************************** TOP ABOVE 19 ************************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);

		glVertex3f (23, 23, -1.0);
		glVertex3f (23, 19, -1.0);
		glVertex3f (19, 19, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 23, -1.0);
		glVertex3f (19, 23, -1.0);
		glVertex3f (19, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 23, -1.0);
		glVertex3f (15, 23, -1.0);
		glVertex3f (19, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 23, -1.0);
		glVertex3f (15, 19, -1.0);
		glVertex3f (19, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 23, -1.0);
		glVertex3f (15, 23, -1.0);
		glVertex3f (15, 19, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 23, -1.0);
		glVertex3f (11, 19, -1.0);
		glVertex3f (15, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 23, -1.0);
		glVertex3f (11, 23, -1.0);
		glVertex3f (11, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 23, -1.0);
		glVertex3f (7, 19, -1.0);
		glVertex3f (11, 19, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 23, -1.0);
		glVertex3f (7, 23, -1.0);
		glVertex3f (7, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 23, -1.0);
		glVertex3f (3, 19, -1.0);
		glVertex3f (7, 19, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 23, -1.0);
		glVertex3f (3, 23, -1.0);
		glVertex3f (3, 19, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 23, -1.0);
		glVertex3f (0, 19, -1.0);
		glVertex3f (3, 19, -1.0);

	glEnd();

// ************************************************************************ //

// ***************** CENTER TOP BETWEEN 15 - 19 *************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 19, -1.0);
		glVertex3f (23, 15, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 19, -1.0);
		glVertex3f (19, 19, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 19, -1.0);
		glVertex3f (15, 19, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 19, -1.0);
		glVertex3f (15, 15, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 19, -1.0);
		glVertex3f (15, 19, -1.0);
		glVertex3f (15, 15, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 19, -1.0);
		glVertex3f (11, 15, -1.0);
		glVertex3f (15, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 19, -1.0);
		glVertex3f (11, 19, -1.0);
		glVertex3f (11, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 19, -1.0);
		glVertex3f (7, 15, -1.0);
		glVertex3f (11, 15, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 19, -1.0);
		glVertex3f (7, 19, -1.0);
		glVertex3f (7, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 19, -1.0);
		glVertex3f (3, 15, -1.0);
		glVertex3f (7, 15, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 19, -1.0);
		glVertex3f (3, 19, -1.0);
		glVertex3f (3, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 19, -1.0);
		glVertex3f (0, 15, -1.0);
		glVertex3f (3, 15, -1.0);

	glEnd();

// **************************************************************** //

// ***************** CENTER BETWEEN 11 - 15 *************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 15, -1.0);
		glVertex3f (23, 11, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 11, -1.0);
		glVertex3f (19, 11, -1.0);
		glVertex3f (19, 15, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 15, -1.0);
		glVertex3f (15, 15, -1.0);
		glVertex3f (19, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 15, -1.0);
		glVertex3f (15, 11, -1.0);
		glVertex3f (19, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 15, -1.0);
		glVertex3f (15, 15, -1.0);
		glVertex3f (15, 11, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 15, -1.0);
		glVertex3f (11, 11, -1.0);
		glVertex3f (15, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 15, -1.0);
		glVertex3f (11, 15, -1.0);
		glVertex3f (11, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 15, -1.0);
		glVertex3f (7, 11, -1.0);
		glVertex3f (11, 11, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 15, -1.0);
		glVertex3f (7, 15, -1.0);
		glVertex3f (7, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 15, -1.0);
		glVertex3f (3, 11, -1.0);
		glVertex3f (7, 11, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 15, -1.0);
		glVertex3f (3, 15, -1.0);
		glVertex3f (3, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 15, -1.0);
		glVertex3f (0, 11, -1.0);
		glVertex3f (3, 11, -1.0);

	glEnd();

// **************************************************************** //

// ***************** CENTER BETWEEN 7 - 11 *************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 11, -1.0);
		glVertex3f (23, 7, -1.0);
		glVertex3f (19, 11, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 7, -1.0);
		glVertex3f (19, 11, -1.0);
		glVertex3f (19, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 11, -1.0);
		glVertex3f (15, 11, -1.0);
		glVertex3f (19, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);


		glNormal3f(0,0,1);
		glVertex3f (15, 11, -1.0);
		glVertex3f (15, 7, -1.0);
		glVertex3f (19, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 11, -1.0);
		glVertex3f (15, 11, -1.0);
		glVertex3f (15, 7, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 11, -1.0);
		glVertex3f (11, 7, -1.0);
		glVertex3f (15, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 11, -1.0);
		glVertex3f (11, 7, -1.0);
		glVertex3f (7, 11, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 11, -1.0);
		glVertex3f (7, 7, -1.0);
		glVertex3f (11, 7, -1.0);

	glEnd();

	 //SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 11, -1.0);
		glVertex3f (7, 11, -1.0);
		glVertex3f (7, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 11, -1.0);
		glVertex3f (3, 7, -1.0);
		glVertex3f (7, 7, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 11, -1.0);
		glVertex3f (3, 11, -1.0);
		glVertex3f (3, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 11, -1.0);
		glVertex3f (0, 7, -1.0);
		glVertex3f (3, 7, -1.0);

	glEnd();

// **************************************************************** //

// ***************** DOWN LEFT BETWEEN 3 - 7 *************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 7, -1.0);
		glVertex3f (23, 3, -1.0);
		glVertex3f (19, 7, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 3, -1.0);
		glVertex3f (19, 7, -1.0);
		glVertex3f (19, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 7, -1.0);
		glVertex3f (15, 7, -1.0);
		glVertex3f (19, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 7, -1.0);
		glVertex3f (15, 3, -1.0);
		glVertex3f (19, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 7, -1.0);
		glVertex3f (7, 11, -1.0);
		glVertex3f (15, 3, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 7, -1.0);
		glVertex3f (11, 3, -1.0);
		glVertex3f (15, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 7, -1.0);
		glVertex3f (11, 3, -1.0);
		glVertex3f (7, 7, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 7, -1.0);
		glVertex3f (7, 3, -1.0);
		glVertex3f (11, 3, -1.0);

	glEnd();

	 //SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 7, -1.0);
		glVertex3f (7, 3, -1.0);
		glVertex3f (7, 7, -1.0);

	glEnd();


//	 SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 7, -1.0);
		glVertex3f (3, 3, -1.0);
		glVertex3f (7, 3, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 7, -1.0);
		glVertex3f (3, 7, -1.0);
		glVertex3f (3, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 7, -1.0);
		glVertex3f (0, 3, -1.0);
		glVertex3f (3, 3, -1.0);

	glEnd();

// **************************************************************** //

// ***************** DOWN BELOW 3  *************************** //

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 3, -1.0);
		glVertex3f (23, 0, -1.0);
		glVertex3f (19, 3, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (23, 0, -1.0);
		glVertex3f (19, 3, -1.0);
		glVertex3f (19, 0, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (19, 3, -1.0);
		glVertex3f (15, 3, -1.0);
		glVertex3f (19, 0, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 3, -1.0);
		glVertex3f (15, 0, -1.0);
		glVertex3f (19, 0, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (15, 3, -1.0);
		glVertex3f (11, 3, -1.0);
		glVertex3f (15, 0, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP LEFT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 3, -1.0);
		glVertex3f (11, 0, -1.0);
		glVertex3f (15, 0, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (11, 3, -1.0);
		glVertex3f (11, 0, -1.0);
		glVertex3f (7, 3, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 1º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (7, 3, -1.0);
		glVertex3f (7, 0, -1.0);
		glVertex3f (11, 0, -1.0);

	glEnd();

	 //SMAL TRIANGLE TOP RIGHT 2º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 3, -1.0);
		glVertex3f (7, 0, -1.0);
		glVertex3f (7, 3, -1.0);

	glEnd();


//	 SMAL TRIANGLE TOP RIGHT 2º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (3, 3, -1.0);
		glVertex3f (3, 0, -1.0);
		glVertex3f (7, 0, -1.0);

	glEnd();

	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE A
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 3, -1.0);
		glVertex3f (3, 3, -1.0);
		glVertex3f (3, 0, -1.0);

	glEnd();


	// SMAL TRIANGLE TOP RIGHT 3º QUADRANTE B
	glBegin(GL_POLYGON);

		glNormal3f(0,0,1);
		glVertex3f (0, 3, -1.0);
		glVertex3f (0, 0, -1.0);
		glVertex3f (3, 0, -1.0);

	glEnd();

	glDisable(GL_TEXTURE_1D);

// **************************************************************** //

	glPopMatrix();
	glPopMatrix();
}

Floor::Floor(void)
{
}


Floor::~Floor(void)
{
}