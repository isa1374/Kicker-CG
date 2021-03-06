#include "Field.h"
#include <stdio.h>
#include <math.h>

Field::Field() {
	float px = 0;
	float py = 0; 
	float radio = 2.0;
}

Field::~Field() {

}

void Field::draw() {
	
    GLUquadric* qobj;
	glPointSize(7);
    glBegin(GL_POINTS);{
        for (double i = 0.0; i<10; i += 0.001) {
            calx = radio*cos(i) + px;
            caly = radio*sin(i) + py;
            glVertex2f(calx, caly);
        }
    }
	glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();{
        //    Linea central
        glLineWidth(4);
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(0.0, 4.5, 0.0);
            glVertex3f(0, -4.5, 0);
        }
        glEnd();

        //    Borde cancha
    
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-6.0, 4.5, 0.0);
            glVertex3f(-6.0, -4.5, 0);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(6.0, 4.5, 0.0);
            glVertex3f(-6.0, 4.5, 0);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(6.0, 4.5, 0.0);
            glVertex3f(6.0, -4.5, 0);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(6.0, -4.5, 0.0);
            glVertex3f(-6.0, -4.5, 0);
        }
        glEnd();

        //  Linea  Porteria izquierda
    
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-5.0, 1.5, 0.0);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-6.0, 1.5, 0.0);
            glVertex3f(-5.0, 1.5, 0);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-6.0, -1.5, 0.0);
            glVertex3f(-5.0, -1.5, 0);
        }
        glEnd();
    }
    glPopMatrix();
    glPushMatrix();{
        //  Porteria izquierda
        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(-6, 1, 0);
            glRotatef(15, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();


        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(-6, -1, 0);
            glRotatef(15, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(-5.5, 1, 0);
            glRotatef(0, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(-5.5, -1, 0);
            glRotatef(0, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(-5.5, 1, 2);
            glRotatef(90, 90.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();
    }
    glPopMatrix();
    glPushMatrix();{
        //  Line  Porteria derecha
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(5.0, 1.5, 0.2);
            glVertex3f(5.0, -1.5, 0.2);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(6.0, 1.5, 0.2);
            glVertex3f(5.0, 1.5, 0.2);
        }
        glEnd();
        glBegin(GL_LINES);{
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(6.0, -1.5, 0.2);
            glVertex3f(5.0, -1.5, 0.2);
        }
        glEnd();
    }
    glPopMatrix();
    glPushMatrix();{
        //  Porteria izquierda
        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(6, 1, 0);
            glRotatef(-15, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();


        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(6, -1, 0);
            glRotatef(-15, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(5.5, 1, 0);
            glRotatef(0, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(5.5, -1, 0);
            glRotatef(0, 0.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1.0, 1.0, 1.0);
            glTranslated(5.5, 1, 2);
            glRotatef(90, 90.0f, 1.0f, 0.0f);
            qobj = gluNewQuadric();
            gluQuadricNormals(qobj, GLU_SMOOTH);
            gluCylinder(qobj, 0.05, 0.05, 2, 20, 20);
        }
        glPopMatrix();
    }
    glPopMatrix();

	glPushMatrix();
	{
        glBegin(GL_POLYGON);{
            glColor3f(0.0f, 0.5f, 0.0f);
            glVertex3f(-7.0, 5.0, 0.0);
            glVertex3f(7.0, 5.0, 0.0);
            glVertex3f(7.0, -5.0, 0.0);
            glVertex3f(-7.0, -5.0, 0.0);
        }
        glEnd();
        glFlush();
	}
	glPopMatrix();
}
