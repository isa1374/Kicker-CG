/*
	TC3022. Computer Graphics
	Sergio Ruiz
	
	CG Project - Kicker 

	Isabel García Pérez A01331405 
	Isaac Arzate Soto  A01214624

*/

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>
// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
#include "glm.h"
#include "Ball.h"
Ball* ball; 
/////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define DO_ROTATION_X

GLfloat		rotationY = 0.0f;
GLfloat		rotationX = 0.0f;

GLfloat*	mat0_specular;
GLfloat*	mat0_diffuse;
GLfloat*	mat0_shininess;
GLfloat*	light0_position;
GLfloat*	light1_position; 

GLMmodel*	model;

float px = 0, py = 0, radio = 1.3, calx, caly;



void init(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glClearColor(0.2, 0.2, 0.2, 1.0);
	
	//BALL 
	ball = new Ball(); 
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	//ROBOT
	model = glmReadOBJ("assets/cube.obj");
	glmUnitize(model);
	glmVertexNormals(model, 45.0f, false);
	glmFacetNormals(model);

	// When the model is too big make it fit inside a 1x1x1 cube:
	//glmUnitize(model);
	// You can also scale it later:
	//glmScale(model, 2.0f);

	// When the model doesn't have normals, glm can add them:
	//glmVertexNormals(model, 45.0f, false); // first per vertex
	//glmFacetNormals(model); // and then per face
	
	light0_position = new GLfloat[4];
	light0_position[0] = 0;
	light0_position[1] = -20;
	light0_position[2] = 20;
	light0_position[3] = 1; 

	GLfloat lightColor1[] = { 0.9f, 0.91f, 0.2f, 1.0f };
	light1_position = new GLfloat[4];
	light1_position[0] = 0;
	light1_position[1] = -1;
	light1_position[2] = 0;
	light1_position[3] = 0; 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_position);

	mat0_specular = new GLfloat[4];
	mat0_specular[0] = 1.0f;
	mat0_specular[1] = -1.0f;
	mat0_specular[2] = 1.0f;
	mat0_specular[3] = 1.0f;

	mat0_diffuse = new GLfloat[4];
	mat0_diffuse[0] = 0.8f;
	mat0_diffuse[1] = 0.7f;
	mat0_diffuse[2] = 0.6f;
	mat0_diffuse[3] = 1.0f;

	mat0_shininess = new GLfloat[1];
	mat0_shininess[0] = 100.0f;

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1); 
	
}

void display(void)
{

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat ambientColor[] = { 0.85f, 0.85f, 0.1f, 1.0f }; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);

	/*Model field*/
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(7);
	glBegin(GL_POINTS);
	for (double i = 0.0; i<10; i += 0.001) {
		calx = radio*cos(i) + px;
		caly = radio*sin(i) + py;
		glVertex2f(calx, caly);
	}
	glEnd();

	//    Linea central
	glLineWidth(4);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(0, -4.5, 0);
	glEnd();
	//    Borde cancha
	glBegin(GL_LINES);
		glVertex3f(-6.0, 4.5, 0.0);
		glVertex3f(-6.0, -4.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(6.0, 4.5, 0.0);
		glVertex3f(-6.0, 4.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(6.0, 4.5, 0.0);
		glVertex3f(6.0, -4.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(6.0, -4.5, 0.0);
		glVertex3f(-6.0, -4.5, 0);
	glEnd();
	//  Linea  Porteria izquierda
	glBegin(GL_LINES);
		glVertex3f(-5.0, 1.5, 0.0);
		glVertex3f(-5.0, -1.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-6.0, 1.5, 0.0);
		glVertex3f(-5.0, 1.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-6.0, -1.5, 0.0);
		glVertex3f(-5.0, -1.5, 0);
	glEnd();
	//  Porteria izquierda
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		GLUquadric* qobj;
		glTranslated(-6, 1, 0);
		glRotatef(15, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();


	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(-6, -1, 0);
		glRotatef(15, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(-5.5, 1, 0);
		glRotatef(0, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(-5.5, -1, 0);
		glRotatef(0, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(-5.5, 1, 2);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();
	//  Line  Porteria derecha
	glBegin(GL_LINES);
		glVertex3f(5.0, 1.5, 0.0);
		glVertex3f(5.0, -1.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(6.0, 1.5, 0.0);
		glVertex3f(5.0, 1.5, 0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(6.0, -1.5, 0.0);
		glVertex3f(5.0, -1.5, 0);
	glEnd();
	//  Porteria izquierda
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(6, 1, 0);
		glRotatef(-15, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();


	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(6, -1, 0);
		glRotatef(-15, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(5.5, 1, 0);
		glRotatef(0, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(5.5, -1, 0);
		glRotatef(0, 0.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(5.5, 1, 2);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
	glPopMatrix();
	
	glPushMatrix();
	{
		glColor3f(0.0f, 0.5f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3f(-7.0, 5.0, 0.0);
		glVertex3f(7.0, 5.0, 0.0);
		glVertex3f(7.0, -5.0, 0.0);
		glVertex3f(-7.0, -5.0, 0.0);
		glEnd();
		glFlush();

	}
	glPopMatrix();

	

	// Ball
	ball->draw();
	/*glPushMatrix();
		glColor3f(.52, 0.39, 0.39);
		glTranslated(0, 0, .1);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		qobj = gluNewQuadric();
		gluQuadricNormals(qobj, GLU_SMOOTH);
		gluSphere(qobj, .1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(.196078, 0.6, 0.8);
		glBegin(GL_POLYGON);
		glVertex3f(-7.0, 5.0, 0.0);
		glVertex3f(7.0, 5.0, 0.0);
		glVertex3f(7.0, -5.0, 0.0);
		glVertex3f(-7.0, -5.0, 0.0);
		glEnd();
		glFlush();
	}
	glPopMatrix();*/

	/*Model of robot */
	glPushMatrix();
	{
		glTranslatef(0, 1.5, 0); 
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		glTranslatef(0, .9f, 0);
		glmDraw(model, GLM_SMOOTH);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(1, 1.5, 0);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		glTranslatef(0, .9f, 0);
		glmDraw(model, GLM_SMOOTH);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-1, 3, 0);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		glTranslatef(0, .9f, 0);
		glmDraw(model, GLM_SMOOTH);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-3, 3, 0);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		glTranslatef(0, .9f, 0);
		glmDraw(model, GLM_SMOOTH);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(3, 3, 0);
		glRotatef(90, 90.0f, 1.0f, 0.0f);
		glTranslatef(0, .9f, 0);
		glmDraw(model, GLM_SMOOTH);
	}
	glPopMatrix();


	glutSwapBuffers();
}

void idle (void)
{
	rotationY += 0.08f;
	if (rotationY > 360)
	{
		rotationY = 0;
	}

#ifdef DO_ROTATION_X
	rotationX += 0.08f;
	if (rotationX > 360)
	{
		rotationX = 0;
	}
#endif

	glutPostRedisplay ();	
}

void reshape (int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.5, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, -25.0, 10.0,
		0.0, 5.0, 0.0,
		0.0, 0.5, 0.5);
	display(); 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (800, 800); 
	glutInitWindowPosition (100, 50);
	glutCreateWindow ("Kicker");
	glutReshapeFunc (reshape);
	init ();
	glutDisplayFunc(display); 
	glutIdleFunc (idle);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
