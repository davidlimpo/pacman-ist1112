// proj.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Maze.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Camera.h"
#include "Floor.h"
#include "Hud.h"
#include <math.h>
#include "SP.h"
#define PI 3.14159265

Camera * cam;
Maze * map;
Pacman * pac;
Ghost * g1;
Ghost * g2;
Ghost * g3;
Floor * ground;
Hud * hud;

SP * particle[60];

int camera = 1;
int contEffect = 0;
bool effect = false;
bool dark = false;
bool spotlight = false;
float r;
float height;
float width;
int kpress = 0;

float particleX;
float particleY;
float particleZ = 0.45;

bool canMove = false;

bool g1canMove = false;
bool g2canMove = false;
bool g3canMove = false;

bool pacExplosion = false;
bool initExplosion = true;

int init_ghosts_moves = 0;
int init_ghost1_move = 200;
int init_ghost2_move = 200;
int init_ghost3_move = 200;

int g1mv = 2;
int g2mv = 2;
int g3mv = 2;

int explCont = 0;
float incrZ = 0;
bool sobe = true;

float amb[4] = {0.1f, 0.1f, 0.1f, 1.0f};

/********************
*  ROUND FUNCTION   *
*********************/

bool isInteger(float value)
{
	if(value/1.00 == (int)value)
		return true;
	else
		return false;
}

/********************
*  init function    *
*********************/

void initGame(void)
{

	map = new Maze();
	pac = new Pacman (12.5, 9.5);
	g1 = new Ghost(1, 0, 1, 14.5 , 12.5);
	g2 = new Ghost(0, 1, 0, 12.5, 11.5);
	g3 = new Ghost(0, 0.3, 1, 9.5, 11.5);
	cam = new Camera();
	ground = new Floor();
	hud = new Hud();

	for(int i = 0; i < 60; i++)
		particle[i] = new SP();

	int dir = pac->getDir();
}

void gameOver()
{
	pac->setLive();

	if(pac->getLives() >= 0){

		g1->newAxisX(14.5);
		g1->newAxisY(12.5);
		g2->newAxisX(12.5);
		g2->newAxisY(11.5);
		g3->newAxisX(9.5);
		g3->newAxisY(11.5);
		pac->newAxisX(12.5);
		pac->newAxisY(9.5);

		g1mv = 2;
		g2mv = 2;
		g3mv = 2;

		map->setMaze(11,9,0);
		map->setMaze(12,9,0);
		init_ghosts_moves = 0;

		pacExplosion = false;
		explCont = 0;
		incrZ = 0;

		sobe = true;
		initExplosion = true;
	}

	else
		printf(" GAME OVER");
}

void explosao()
{
	if(initExplosion){
			for(int i = 0; i < 60; i++){

				float randomX = (float)rand()/(float)RAND_MAX - 0.5;
				float randomY = (float)rand()/(float)RAND_MAX - 0.5;

				float randomR = (float)rand()/(float)RAND_MAX;
				float randomG = (float)rand()/(float)RAND_MAX;
				float randomB = (float)rand()/(float)RAND_MAX;

				particle[i]->setColor(randomR, randomG, randomB);

				particle[i]->setX(pac->getAxisX());
				particle[i]->setY(pac->getAxisY());
				particle[i]->setZ(0.45);
				particle[i]->setRandX(randomX);
				particle[i]->setRandY(randomY);
			}

			initExplosion = false;
	}

	for(int i = 0; i < 60; i++){
			particle[i]->addX(particle[i]->getRandX());
			particle[i]->addY(particle[i]->getRandY());
			particle[i]->addZ(incrZ);
			
			if(particle[i]->getZ() >= 0)
				particle[i]->draw();
	}		
		
			if(incrZ <= 0.5 && sobe)
			{
				incrZ += 0.1;

				if(incrZ > 0.5)
				sobe = false;
			}
			else
				incrZ -= 0.15;
}

void calculaAngulo(Ghost * g){

	if((pac->getAxisX() - g->getAxisX()) > 0)
		g->setAngle(90 + 180/PI * atan(( (pac->getAxisY() - g->getAxisY()) / (pac->getAxisX() - g->getAxisX()) )) );

	else if(((pac->getAxisX() - g->getAxisX()) == 0) && (pac->getAxisY() > g->getAxisY())) // |
		g->setAngle(180);																   // | Para nao dividir
	else if(((pac->getAxisX() - g->getAxisX()) == 0) && (pac->getAxisY() < g->getAxisY())) // |  por 0
		g->setAngle(0);																	   // |

	else
		g->setAngle(-90 + 180/PI * atan(( (pac->getAxisY() - g->getAxisY()) / (pac->getAxisX() - g->getAxisX()) )) );
}


/********************
*    reshape        *
*********************/

void myReshape(GLsizei w, GLsizei h) {

	height = h;
	width = w;
	r = (float)w / (float)h;
}

/********************
*    display        *
*********************/

void myDisplay(void) {
	
	GLfloat direction[] = { 1, 0.0, 1, 0};
	glLightfv(GL_LIGHT0, GL_POSITION, direction);

	if(camera == 1)
		cam->camOne(r, width, height);
	
	else if(camera == 2){
		cam->camTwo(pac->getAxisX(), pac->getAxisY(), width, height, r);	
		gluLookAt(pac->getAxisX(), pac->getAxisY()-2,10, pac->getAxisX(),pac->getAxisY(),2, 0,0,1);
	}

	else if(camera == 3){
		cam->camTwo(pac->getAxisX(), pac->getAxisY(), width, height, r);	
		gluLookAt(pac->getAxisX(), pac->getAxisY()-20,2, pac->getAxisX(),pac->getAxisY(),2, 0,0,1);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	calculaAngulo(g1);
	calculaAngulo(g2);
	calculaAngulo(g3);

	map->draw(dark);
	
	if(pacExplosion)
		explosao();
	else
		pac->draw(dark);

	g1->draw(effect, spotlight);
	g2->draw(effect, spotlight);
	g3->draw(effect, spotlight);
	ground->draw();


	glViewport(0, 700, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(0.0f, 24.0f, 0.0f, 24.0f, -24.0f, 24.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_DEPTH_BUFFER_BIT);


	glDisable(GL_LIGHTING);
	hud->draw(pac->getLives());
	glEnable(GL_LIGHTING);

	glutSwapBuffers();
}

void light (void){

	//fonte luz branca
	GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void g1_eated() {

	if(init_ghost1_move < 15)
		g1mv = -1;

	else
		g1mv = 2;

	init_ghost1_move++;

}

void g2_eated() {

	if(init_ghost2_move < 30)
		g2mv = -2;

	else
		g2mv = 2;

	init_ghost2_move++;
}

void g3_eated() {

	if(init_ghost3_move < 15)
		g3mv = 1;

	else
		g3mv = 2;


	init_ghost3_move++;
}

void openGate() {

	map->setMaze(11,9,0);
	map->setMaze(12,9,0);
}

void closeGate() {

	map->setMaze(11,9,4);
	map->setMaze(12,9,4);
}

void mov_inic() {

	if(init_ghosts_moves < 15){
		g1mv = -1;
		g3mv = 1;

	}else{

		g1mv = 2;
		g3mv = 2;
	}

	init_ghosts_moves++;
}

void move(float x, float y, float dir, int obj, int kp)
{
	if(isInteger(x) && isInteger(y)){

		x = (floor(x) + 0.5);
		y = (floor(y) + 0.5);
		
		if(!pacExplosion)
			if((kp == -2) && map->getMaze(x, y + 1) != 1 && map->getMaze(x, y + 1) != 4){
				if(obj == 3)
					pac->setDown();
				else if(obj == 4)
					g1->setDown();
				else if(obj == 5)
					g2->setDown();
				else if(obj == 6)
					g3->setDown();
			}

			else if((kp == 2) && map->getMaze(x, y - 1) != 1  && map->getMaze(x, y - 1) != 4){
				if(obj == 3)
					pac->setUp();
				else if(obj == 4)
					g1->setUp();
				else if(obj == 5)
					g2->setUp();
				else if(obj == 6)
					g3->setUp();
			}

			else if((kp == -1) && map->getMaze(x - 1, y) != 1  && map->getMaze(x - 1, y) != 4){
				if(obj == 3)
					pac->setLeft();
				else if(obj == 4)
					g1->setLeft();
				else if(obj == 5)
					g2->setLeft();
				else if(obj == 6)
					g3->setLeft();
			}

			else if((kp == 1) && map->getMaze(x + 1, y) != 1 && map->getMaze(x + 1, y) != 4){
				if(obj == 3)
					pac->setRight();
				else if(obj == 4)
					g1->setRight();
				else if(obj == 5)
					g2->setRight();
				else if(obj == 6)
					g3->setRight();
			}

			if((dir == 2) && map->getMaze(x, y - 1) != 1  && map->getMaze(x, y - 1) != 4){

				if(obj == 3)
					canMove = true;
				else if(obj == 4)
					g1canMove = true;
				else if(obj == 5)
					g2canMove = true;
				else if(obj == 6)
					g3canMove = true;
			}

			else if((dir == -2) && map->getMaze(x, y + 1) != 1 && map->getMaze(x, y + 1) != 4){

				if(obj == 3)
					canMove = true;
				else if(obj == 4)
					g1canMove = true;
				else if(obj == 5)
					g2canMove = true;
				else if(obj == 6)
					g3canMove = true;
			}

			else if((dir == -1) && map->getMaze(x - 1, y) != 1 && map->getMaze(x - 1, y) != 4){

				if(obj == 3)
					canMove = true;
				else if(obj == 4)
					g1canMove = true;
				else if(obj == 5)
					g2canMove = true;
				else if(obj == 6)
					g3canMove = true;

			} else if((dir == 1) && map->getMaze(x + 1, y) != 1 && map->getMaze(x + 1, y) != 4) {

				if(obj == 3)
					canMove = true;
				else if(obj == 4)
					g1canMove = true;
				else if(obj == 5)
					g2canMove = true;
				else if(obj == 6)
					g3canMove = true;
			}

			else {

				if(obj == 3)
					canMove = false;
				else if(obj == 4)
					g1canMove = false;
				else if(obj == 5)
					g2canMove = false;
				else if(obj == 6)
					g3canMove = false;
			}

	} else {
			if(obj == 3)
				canMove = true;
			else if(obj == 4)
				g1canMove = true;
			else if(obj == 5)
				g2canMove = true;
			else if(obj == 6)
				g3canMove = true;
		}
}

int AI_0(float x, float y, int dir, float angle, int type)
{

	bool g_can_move;
	int na = rand() % 100;

	if(type == 4)
		g_can_move = g1canMove;
	else if(type == 5)
		g_can_move = g2canMove;
	else
		g_can_move = g3canMove;

	if(dir == -1 || dir == 1)
	{
		if(angle >= 0 && angle < 90 || angle >= -90 && angle < 0)
			if(map->getMaze(x, y + 1) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return -2;
			}
			else
				return dir;

		else if(angle >= 90 && angle <= 180 || angle >= -180 && angle <= -90)
			if(map->getMaze(x, y - 1) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return 2;
			}

			else
				return dir;

		else
			return dir;
	}
	
	else if(dir == -2 || dir == 2)
	{
		if(angle >= 0 && angle <= 180)
			if(map->getMaze(x +	1, y) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return 1;
			}
	
			else
				return dir;

		else if(angle >= -180 && angle <= 0)
			if(map->getMaze(x - 1, y) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return -1;
			}

			else
				return dir;

		else
			return dir;
	}

	else
		return -dir;
}

int AI_1(float x, float y, int dir, float angle, int type)
{

	bool g_can_move;
	int na = rand() % 100;

	if(type == 4)
		g_can_move = g1canMove;
	else if(type == 5)
		g_can_move = g2canMove;
	else
		g_can_move = g3canMove;

	if(dir == -1 || dir == 1)
	{
		if(angle >= 0 && angle < 90 || angle >= -90 && angle < 0)
			if(map->getMaze(x, y - 1) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return 2;
			}
			else
				return dir;

		else if(angle >= 90 && angle <= 180 || angle >= -180 && angle <= -90)
			if(map->getMaze(x, y + 1) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return -2;
			}

			else
				return dir; 
	}
	
	else if(dir == -2 || dir == 2)
	{
		if(angle >= 0 && angle <= 180)
			if(map->getMaze(x -	1, y) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return -1;
			}
	
			else
				return dir;

		else if(angle >= -180 && angle <= 0)
			if(map->getMaze(x + 1, y) != 1)
			{
				if(na >= 75)
					return dir;
				else
					return 1;
			}

			else
				return dir;
	}

	else
		return -dir;
}

void Timer(int value)
{
	// INICIALIZAÇAO DE VARIAVEIS LOCAIS

	int pacdir = pac->getDir();
	float pacX = (floorf(pac->getAxisX() * 100 + 0.5) / 100) - 0.5 ;
	float pacY = (floorf((24 - pac->getAxisY()) * 100 + 0.5) / 100) - 0.5;

	int g1_dir = g1->getDir();
	float g1X = (floorf(g1->getAxisX() * 100 + 0.5) / 100) - 0.5 ;
	float g1Y = (floorf((24 - g1->getAxisY()) * 100 + 0.5) / 100) - 0.5;
	float angle_g1 = g1->getAngle();


	int g2_dir = g2->getDir();
	float g2X = (floorf(g2->getAxisX() * 100 + 0.5) / 100) - 0.5 ;
	float g2Y = (floorf((24 - g2->getAxisY()) * 100 + 0.5) / 100) - 0.5;
	float angle_g2 = g2->getAngle();

	int g3_dir = g3->getDir();
	float g3X = (floorf(g3->getAxisX() * 100 + 0.5) / 100) - 0.5 ;
	float g3Y = (floorf((24 - g3->getAxisY()) * 100 + 0.5) / 100) - 0.5;
	float angle_g3 = g3->getAngle();


	// ACTIVA A FLAG DO MOV DO PACMAN
	move(pacX, pacY, pacdir, 3, kpress);

	if(init_ghosts_moves < 30)
	{
		mov_inic();
		openGate();
	}

	else if(init_ghosts_moves == 30)
	{
		closeGate();
		init_ghosts_moves++;
	}

	else if(init_ghost1_move < 50)
	{
		g1_eated();
		openGate();
	}

	else if(init_ghost1_move == 50)
	{
		closeGate();
		init_ghost1_move++;
	}

	else if(init_ghost2_move < 50)
	{
		g2_eated();
		openGate();
	}

	else if(init_ghost2_move == 50)
	{
	
		closeGate();
		init_ghost2_move++;
	}

	else if(init_ghost3_move < 50)
	{
		g3_eated();
		openGate();
	}

	else if(init_ghost3_move == 50)
	{
		closeGate();
		init_ghost3_move++;
	}

	else
	{
		if(!effect)
		{
			g1mv = AI_0(g1X, g1Y, g1_dir, angle_g1, 4);
			g2mv = AI_0(g2X, g2Y, g2_dir, angle_g2, 5);
			g3mv = AI_0(g3X, g3Y, g3_dir, angle_g3, 6);
		}
		else
		{
			g1mv = AI_1(g1X, g1Y, g1_dir, angle_g1, 4);
			g2mv = AI_1(g2X, g2Y, g2_dir, angle_g2, 5);
			g3mv = AI_1(g3X, g3Y, g3_dir, angle_g3, 6);		
		}
	}

	move(g1X, g1Y, g1_dir, 4, g1mv);

	move(g2X, g2Y, g2_dir, 5, g2mv);

	move(g3X, g3Y, g3_dir, 6, g3mv);


	// VERIFICA SE O PACMAN E OS FANTASMAS PODEM ANDAR, SE SIM, ENTÃO QUE ANDEM!!!;
	if(canMove)
		pac->move();

	if(g1canMove)
		g1->move();

	if(g2canMove)
		g2->move();

	if(g3canMove)
		g3->move();

	
	// COME BOLAS

	if(map->getMaze(pacX, pacY) == 2){
		map->setMaze(pacX, pacY, 0);
		hud->smallBallPoint();
	}

	if(map->getMaze(pacX, pacY) == 3)
	{
		map->setMaze(pacX, pacY, 0);
		effect = true;
		hud->bigBallPoint();
	}

	if(contEffect == 272){
		effect = false;
		contEffect = 0;
	}
	
	if(effect){
		contEffect++;
	}

	if(g1X == pacX && g1Y == pacY || g2X == pacX && g2Y == pacY || g3X == pacX && g3Y == pacY)
		if(!effect)
			pacExplosion = true;

		else{
			if(g1X == pacX && g1Y == pacY) {
				g1->newAxisX(14.5);
				g1->newAxisY(12.5);
				g1mv = 2;
				init_ghost1_move = 0;
			}
			else if(g2X == pacX && g2Y == pacY)
			{
				g2->newAxisX(12.5);
				g2->newAxisY(11.5);
				g2mv = 2;
				init_ghost2_move = 0;
			}
			else if(g3X == pacX && g3Y == pacY)
			{
				g3->newAxisX(9.5);
				g3->newAxisY(11.5);
				g3mv = 2;
				init_ghost3_move = 0;
			}

		map->setMaze(11,9,0);
		map->setMaze(12,9,0);
		init_ghosts_moves = 0;

		hud->ghostPoint();

		}

		if(pacExplosion)
			if(explCont <= 40)
				explCont++;
			else{
				pacExplosion = false;
				gameOver();
			}

	if(!spotlight){
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
	}else{
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
	}

	glutPostRedisplay();
	glutTimerFunc(50,Timer, 1);
}



/********************
*     keyboard      *
*********************/

void keyPressed (unsigned char key, int x, int y) {

	// Esquerda : a || A
	if(key == 97 || key == 65)
			kpress = -1;

	// Direita : d || D
	if(key == 100 || key == 68)
			kpress = 1;

	// Cima : w || W
	if(key == 119 || key == 87)
			kpress = 2;

	// Baixo : s || S
	if(key == 83 || key == 115)
			kpress = -2;

	// Cam1 : 1
	if(key == 49)
			camera = 1;

	// Cam2 : 2
	if(key == 50)
			camera = 2;

	// Cam2 : 3
	if(key == 51)
			camera = 3;

	//DarkSide Pacman : 0
	if(key == 48)
		if(!dark)
			dark = true;
		else
			dark = false;

	// Spotlight : 5
	if(key == 53)
		if(!spotlight)
			spotlight = true;
		else
			spotlight = false;

	glutPostRedisplay();
}


/********************
*    	main        *
*********************/
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (-1, -1); 
	glutCreateWindow("PacMan"); 
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // CLEAR BUFFER
	glEnable(GL_DEPTH_TEST);
	initGame();
	light();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutTimerFunc(33,Timer, 1);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
}