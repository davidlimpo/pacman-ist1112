#include "StdAfx.h"
#include <GL/glut.h>
#include "Hud.h"
#include "Pacman.h"

void Hud::drawDigit(int point)
{
		if(point == 0 || point == 2 || point == 3 || point == 5 || point == 6 || point == 8 || point == 9) 
			// horizontal baixo
			glBegin(GL_POLYGON);
				glVertex3f (0.0, 0.0, 0.0);
				glVertex3f (1.5, 0.0, 0.0);
				glVertex3f (1.5, 0.35, 0.0);
				glVertex3f (0.0, 0.35, 0.0);
			glEnd();

		if(point == 2 || point == 3 || point == 4 || point == 5 || point == 6 || point == 8 || point == 9) 
			// horizontal centro
			glBegin(GL_POLYGON);
				glVertex3f (0.0, 1.24, 0.0);
				glVertex3f (1.5, 1.24, 0.0);
				glVertex3f (1.5, 1.60, 0.0);
				glVertex3f (0.0, 1.60, 0.0);
			glEnd();
		
		if(point == 0 || point == 2 || point == 3 || point == 5 || point == 6 || point == 7 || point == 8 || point == 9) 
			// horizontal cima
			glBegin(GL_POLYGON);	
				glVertex3f (0.0, 2.5, 0.0);
				glVertex3f (1.5, 2.5, 0.0);
				glVertex3f (1.5, 2.85, 0.0);
				glVertex3f (0.0, 2.85, 0.0);
			glEnd();

		if(point == 0 || point == 2 || point == 6 || point == 8) 
			// vertical esquerda baixo
			glBegin(GL_POLYGON);	
				glVertex3f (0.0, 0.35, 0.0);
				glVertex3f (0.35, 0.35, 0.0);
				glVertex3f (0.35, 1.24, 0.0);
				glVertex3f (0.0, 1.24, 0.0);
			glEnd();

		if(point == 0 || point == 4 || point == 5 || point == 6 || point == 8 || point == 9) 
			// vertical esquerda cima
			glBegin(GL_POLYGON);	
				glVertex3f (0.0, 1.6, 0.0);
				glVertex3f (0.35, 1.6, 0.0);
				glVertex3f (0.35, 2.5, 0.0);
				glVertex3f (0.0, 2.5, 0.0);
			glEnd();

		if(point == 0 || point == 1 || point == 3 || point == 4 || point == 5 || point == 6 || point == 7 || point == 8 || point == 9) 
			// vertical direita baixo
			glBegin(GL_POLYGON);	
				glVertex3f (1.15, 0.35, 0.0);
				glVertex3f (1.5, 0.35, 0.0);
				glVertex3f (1.5, 1.24, 0.0);
				glVertex3f (1.15, 1.24, 0.0);
			glEnd();

		if(point == 0 || point == 1 || point == 2 || point == 3 || point == 4 || point == 7 || point == 8 || point == 9) 
			// vertical direita cima
			glBegin(GL_POLYGON);	
				glVertex3f (1.15, 1.6, 0.0);
				glVertex3f (1.5, 1.6, 0.0);
				glVertex3f (1.5, 2.5, 0.0);
				glVertex3f (1.15, 2.5, 0.0);
			glEnd();
}
void Hud::drawLifes(int i)
{
	int num = 0;

	while(i != 0){
		if(num%3 == 0 && num != 0)
			glTranslatef(-3, -1, 0);

		glTranslatef(1, 0, 0);
		glutSolidSphere(0.45, 20, 10);
		num++;
		
		i--;
	}
}

void Hud::smallBallPoint(void)
{
		if(uni < 8)
			uni = uni + 2;
		else if(uni == 8){
			uni = 0;

			if(dez < 9)
				dez++;
			else
			{
				dez = 0;
				cent++;
			}
		}
		else if(uni == 9){
			uni = 0;
			
			if(dez <= 9)
				dez++;
			else
			{
				dez = 0;
				cent++;
			}
		}
}
void Hud::bigBallPoint(void)
{
		if(dez < 9)
			dez++;
		else if(dez == 9){
			dez = 0;
			cent++;
		}
}
void Hud::ghostPoint(void)
{
	cent++;
}

void Hud::draw(int lifes)
{
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();

		glTranslatef(0.3,0,0);
		drawDigit(cent);
		glTranslatef(2.1,0,0);
		drawDigit(dez);
		glTranslatef(2.4,0,0);
		drawDigit(uni);

		glTranslatef(15.5, 2.5, 0);
		glColor3f(1.0, 1.0, 0.0);
		//drawDigit(lifes);
		drawLifes(lifes);

		glPopMatrix();
}

Hud::Hud(void)
{
	uni = 0;
	cent = 0;
	dez = 0;
}


Hud::~Hud(void)
{
}
