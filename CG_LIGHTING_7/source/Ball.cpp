#include "Ball.h"

Ball::Ball() {

}

Ball::~Ball() {

}

void Ball::draw() {
	GLUquadric* qobj;
	glPushMatrix();
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
	glPopMatrix();
}