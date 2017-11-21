//
//  main.cpp
//  KickerFP
//
//  Created by Karla on 20/11/17.
//  Copyright © 2017 Isa. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>

#include "glm.h"
#include "Ball.h"
#include "Field.h"
#include "Plane.h"

Plane* plane;
Field* field;
Ball* ball;
/////////////////////////////////////////////////////
float posx;
float posy;
float posz;
float rotation;

GLfloat*    mat0_specular;
GLfloat*    mat0_diffuse;
GLfloat*    mat0_shininess;
GLfloat*    light0_position;
GLfloat*    light1_position;



GLMmodel*    P1;
GLMmodel*    P2;
GLMmodel*    P3;

GLMmodel*    AI1;
GLMmodel*    AI2;
GLMmodel*    AI3;


void init(void)
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glClearColor(0.2, 0.2, 0.2, 3.0);
    
    posx= 0.0;
    posy=20.0;
    posz = 10;
    
    rotation = 0.0f;
    
    plane = new Plane(2048, 2048);
    

    //FIELD
    field = new Field();
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    
    //BALL
    ball = new Ball();
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //ROBOT
    P1 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(P1);
    glmVertexNormals(P1, 45.0f, false);
    glmFacetNormals(P1);
    P2 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(P2);
    glmVertexNormals(P2, 45.0f, false);
    glmFacetNormals(P2);
    P3 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(P3);
    glmVertexNormals(P3, 45.0f, false);
    glmFacetNormals(P3);
    
    AI1 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(AI1);
    glmVertexNormals(AI1, 45.0f, false);
    glmFacetNormals(AI1);
    AI2 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(AI2);
    glmVertexNormals(AI2, 45.0f, false);
    glmFacetNormals(AI2);
    AI3 = glmReadOBJ("/Users/karla/Documents/Isa/GC/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    glmUnitize(AI3);
    glmVertexNormals(AI3, 45.0f, false);
    glmFacetNormals(AI3);
    
    // When the model is too big make it fit inside a 1x1x1 cube:
    //glmUnitize(model);
    // You can also scale it later:
    //glmScale(model, 2.0f);
    
    // When the model doesn't have normals, glm can add them:
    //glmVertexNormals(model, 45.0f, false); // first per vertex
    //glmFacetNormals(model); // and then per face
    
    GLfloat lightColor0[] = { 1,1,1,1.0f};
    light0_position = new GLfloat[4];
    light0_position[0] = 3;
    light0_position[1] = 40;
    light0_position[2] = 0;
    light0_position[3] = 1;
    
    GLfloat lightColor1[] = { 0.74f, 0.84f, 0.84f, 1.0f };
    light1_position = new GLfloat[4];
    light1_position[0] = 0;
    light1_position[1] = 50;
    light1_position[2] = 100;
    light1_position[3] = 1;
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightColor0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    
    
    mat0_specular = new GLfloat[4];
    mat0_specular[0] = .329412f;
    mat0_specular[1] = .329412f;
    mat0_specular[2] = .3294120f;
    mat0_specular[3] = 1.0f;
    
    mat0_diffuse = new GLfloat[4];
    mat0_diffuse[0] = 0.65f;
    mat0_diffuse[1] = 0.65f;
    mat0_diffuse[2] = 0.65f;
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
    
    float colorMat[]= {228/255.0, 35/255.0, 0/255.0};
    //plane->display(30, colorMat);
    
    /*Model field*/
    
    glPushMatrix();{
        glRotatef(90, -15.0f, .2f, 0.0f);
        field->draw();
    }
    glPopMatrix();
   
    
    // Ball
    //ball->draw();
    
    /*Model of TEAMS  */
    
    //TEAM A
    glPushMatrix();{
        glPushMatrix();
        {
            // in position
            glRotatef(90, 0.0f, -1.0f, 0.0f);
            glTranslatef(2.0, .9f, -1.0);
            glmDraw(P1, GLM_SMOOTH);
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position
            glRotatef(90, 0.0f, -1.0f, 0.0f);
            glTranslatef(-2.0, .9f, -1.0);
            glmDraw(P2, GLM_SMOOTH);
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position GoalKeeper
            glTranslatef(5, .9f, 0);
            glRotatef(90, 0.0f, -1.0f, 0.0f);
            glmDraw(P3, GLM_SMOOTH);
        }
        glPopMatrix();
        
    }
    glPopMatrix();
    
    //TEAM B
    glPushMatrix();{
        glPushMatrix();
        {
            //in position
            glTranslatef(-1.0, .9f, 2.0);
            glRotatef(90, 0.0f, 1.0f, 0.0f);
            glmDraw(AI1, GLM_SMOOTH);
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position
            glTranslatef(-1.0, .9f, -2.0);
            glRotatef(90, 0.0f, 1.0f, 0.0f);
            glmDraw(AI2, GLM_SMOOTH);
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position GoalKeeper
            glTranslatef(-5.0, .9f, 0);
            glRotatef(90, 0.0f, 1.0f, 0.0f);
            glmDraw(AI3, GLM_SMOOTH);
        }
        glPopMatrix();
    }
    glPopMatrix();
    
    
    glutSwapBuffers();
}

void idle (void)
{

    rotation += 0.5f;
    
   
    glutPostRedisplay ();
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'w':
            posy += 3.0f;
            break;
        case 's':
            posy -= 3.0f;
            break;
        case 'a':
            posx -= 3.0f;
            break;
        case 'd':
            posx += 3.0f;
            break;
        case 'z':
            posz -= 3.0f;
            break;
        case 'x':
            posz+= 3.0f;
            break;
    }
    glutPostRedisplay();
}


void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.5, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posx, posy, posz,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}

