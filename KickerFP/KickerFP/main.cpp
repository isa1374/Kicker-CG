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
#include "Player.h"


void displayText(int x, int y, char *txt);
Field* field;
Ball* ball;
Player* player;
/////////////////////////////////////////////////////
float posx;
float posy;
float posz;

float speed;

bool start = false;
bool reiniciar = false;

//P1
float positionX=-1.0;
float positionY=2.0;
int rotB=90;
//P2
float positionX2 = -1.0;
float positionY2 = -2.0;
int rotA=90;

//AI1
float posAI1x=2.0;
float posAI1Y = -2.0;
int rotAI1 = 90;
//AI2
float posAI2x=2.0;
float posAI2Y=2.0;
int rotAI2 = 90;
//GKAI1
float posGK1x=5.0;
float posGK1y=0.0;
float rotGP1=90;
//GKAI2
float posGK2x=-5.0;
float posGK2y=0.0;
float rotGP2=90;

bool end = false;

float positionXbola=0.0;
float positionYbola=0.0;

int goalA =0;
int goalB =0;
int timer = 500;
char A[15];
char B[15];
char fin[20];
char msn[20];
char st[20];

bool moving = false;


GLfloat*    mat0_specular;
GLfloat*    mat0_diffuse;
GLfloat*    mat0_shininess;
GLfloat*    light0_position;
GLfloat*    light1_position;

Player*    P1;
Player*    P2;
Player*    P3;
Player*    AI1;
Player*    AI2;
Player*    AI3;

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
    
    speed = 5.0;

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
    P1 = new Player(false, posAI1x, posAI1Y);
    P2 = new Player(false, posAI2x, posAI2Y);
    P3 = new Player(true, posGK1x, posGK1y);
    AI1 = new Player(false,positionX, positionY);
    AI2 = new Player(false, positionX2, positionY2);
    AI3 = new Player(true, posGK2x, posGK2y);
    
    GLfloat lightColor0[] = { 1,1,1,1.0f};
    light0_position = new GLfloat[4];
    light0_position[0] = 3;
    light0_position[1] = 40;
    light0_position[2] = 0;
    light0_position[3] = 1;
    
    GLfloat lightColor1[] = { 0.74f, 0.84f, 0.84f, 1.0f };
    light1_position = new GLfloat[4];
    light1_position[0] = 0;
    light1_position[1] = 20;
    light1_position[2] = 10;
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
    
    
    sprintf(A, "Team A : %d", goalA);
    sprintf(B, "Team B : %d", goalB);
    displayText(100, 40, A);
    displayText(600, 40, B);
    displayText(350, 40, fin);
    displayText(320, 750, msn);
    displayText(320,700, st);
    
  
    
    /*Model field*/
    glPushMatrix();{
        glRotatef(90, -15.0f, .2f, 0.0f);
        field->draw();
    }
    glPopMatrix();
   
   
    /*Model of TEAMS  */
    //TEAM A
    glPushMatrix();{
        glPushMatrix();{
            glTranslatef(posAI1x, 0.9, posAI1Y);
            glRotatef(rotAI1, 0.0, -1.0, 0.0);
            P1->draw();
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(posAI2x, 0.9, posAI2Y);
            glRotatef(rotAI2, 0.0, -1.0, 0.0);
            P2->draw();
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(posGK1x, 0.9, posGK1y);
            glRotatef(rotGP1, 0.0, -1.0, 0.0);
            P3->draw();
        }
        glPopMatrix();
    }
    glPopMatrix();
   
    //TEAM B
    glPushMatrix();{
        glPushMatrix();
        {
            //in position
            glTranslatef(positionX, .9f, positionY);
            glRotatef(rotB, 0.0f, 1.0f, 0.0f);
            AI1->draw();
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position
            glTranslatef(positionX2, .9f, positionY2);
            glRotatef(rotA, 0.0f, 1.0f, 0.0f);
            AI2->draw();
        }
        glPopMatrix();
        glPushMatrix();
        {
            //in position GoalKeeper
            glTranslatef(posGK2x, .9f, posGK2y);
            glRotatef(rotGP2, 0.0f, 1.0f, 0.0f);
            AI3->draw();
        }
        glPopMatrix();
    }
    glPopMatrix();
    glPushMatrix();{
        glTranslated(positionXbola , .1, positionYbola);
        glScalef(.4, .4, .4);
        ball->draw();
        ball->inMotion(100.0, 20.0);
    }
    glPopMatrix();
    
    glutSwapBuffers();
}

void updateAI(){
    float distance1 = sqrt(((positionXbola - posAI1x)* (positionXbola - posAI1x)) + ((positionYbola- posAI1Y)* (positionYbola- posAI1Y)));
    float distance2 = sqrt(((positionXbola - posAI2x)* (positionXbola - posAI2x)) + ((positionYbola- posAI2Y)* (positionYbola- posAI2Y)));

        if(distance1<5.0 && distance1>0.5){
            if(positionXbola>posAI1x){
                posAI1x += .0100f;
            }else{
                posAI1x -= .0100f;
            }
            if(positionYbola>posAI1Y){
                posAI1Y+= .0100f;
            }else{
                posAI1Y -= .0100f;
            }
        }
        if(distance2<5.0 && distance2>1.0){
            if(positionXbola>posAI2x){
                posAI2x += .0100f;
                
            }else{
                posAI2x -= .0100f;
            }
            
            if(positionYbola>posAI2Y){
                posAI2Y+= .0100f;
            }else{
                posAI2Y -= .0100f;
            }
        }
}

void updateGoalKeeperAI(){
    float distance1 = sqrt(((positionXbola - posGK1x)* (positionXbola - posGK1x)) + ((positionYbola- posGK1y)* (positionYbola- posGK1y)));
    float distance2 = sqrt(((positionXbola - posGK2x)* (positionXbola - posGK2x)) + ((positionYbola- posGK2y)* (positionYbola- posGK2y)));
    
        if(distance1>1.0 && distance1<10.0){
            if(posGK1y==1.0){
                posGK1y -= .005f;
            }
            if( posGK1y==-1.0){
                posGK1y += 0.005f;
            }
        }
        if(distance2>1.0 && distance2<10.0){
            if(posGK2y==-1.0 ){
                 posGK2y += 0.005f;
            }else if( posGK2y==1.0){
                posGK2y -= .005f;
            }
        }

}

void movingBall(){
    if(ball->inCollision(positionX, positionY, .05)){
        moving = true;
        ball->update(positionX+1, positionY+1);
        
    }else
    if(ball->inCollision(positionX2, positionY2, .05)){
        moving = true;
        ball->update(positionX2+1, positionY2+1);
        
    }
}


void reinit(){
    goalA = 0;
    goalB = 0;
    timer = 100;
    ball->reset();
    start = false;
    reiniciar = false;
    end = false;
    //P1
    positionX=-1.0;
    positionY=2.0;
    rotB=90;
    //P2
    positionX2 = -1.0;
    positionY2 = -2.0;
    rotA=90;
    
    //AI1
    posAI1x=2.0;
    posAI1Y = -1.0;
    rotAI1 = 90;
    //AI2
    posAI2x=-2.0;
    posAI2Y=-1.0;
    rotAI2 = 90;
    //GKAI1
    posGK1x=5.0;
    posGK1y=0.0;
    rotGP1=90;
    //GKAI2
    posGK2x=-5.0;
    posGK2y=0.0;
    rotGP2=90;
    
    positionXbola=0.0;
    positionYbola=0.0;
    
}

void idle (void)
{
    if(start){
        updateAI();
        updateGoalKeeperAI();
        movingBall();
        if(timer<0){
            timer =0;
            if(goalA == goalB){
                sprintf(msn, "EMPATE");
                end = true;
            }else if(goalA>goalB){
                sprintf(msn, "El ganador es el equipo A");
                end = true;
            }else if(goalB>goalA){
                sprintf(msn, "El ganador es el equipo B");
                end = true;
            }
        }else{
            sprintf(st, "Presiona M para pausa");
            sprintf(fin, "Timer  %d", timer);
            timer -= 1;
        }
    }else{
        sprintf(st, "Presiona P para iniciar");
    }
    if(end){
        sprintf(st, "Presiona R para reiniciar");
    }
    glutPostRedisplay ();
    
    if(reiniciar){
        sprintf(msn, "");
        reinit();
    }
}

void specialkeys(int key, int x, int y){
    glutIgnoreKeyRepeat(key);
    switch (key) {
        case GLUT_KEY_UP:
            positionY2 -= 0.100f;
            rotA=180;
            break;
        case GLUT_KEY_DOWN:
            positionY2 += 0.100f;
            rotA=0;
            break;
        case GLUT_KEY_LEFT:
            positionX2 -= 0.100f;
            rotA=270;
            break;
        case GLUT_KEY_RIGHT:
            positionX2 += 0.100f;
            rotA=90;
            break;
    }
    glutPostRedisplay();
}

void keys(unsigned char key, int x, int y){
    glutIgnoreKeyRepeat(key);
    switch(key){
        case'w': case 'W':
                positionY -= 0.100f;
                rotB=180;
            break;
        case 's': case'S':
                positionY += 0.100f;
                rotB=0;
            break;
        case 'a': case 'A':
                positionX -= 0.100f;
                rotB=270;
            break;
        case 'd': case 'D':
                positionX += 0.100f;
                rotB=90;
            break;
        case 'p': case 'P':
            start = true;
            break;
        case 'm': case 'M':
            start = false;
            break;
        case 'r': case 'R':
            reiniciar = true;
            break;
    }
            
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
    glutSpecialFunc(specialkeys);
    glutKeyboardFunc(keys);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}

void displayText(int x, int y, char *txt){
    GLboolean lightning;
    GLint viewportCoods[4];
    glColor3f(1.0, 0.0, 0.0);
    glGetBooleanv(GL_LIGHTING, &lightning);
    glGetIntegerv(GL_VIEWPORT, viewportCoods);
    if(lightning) glDisable(GL_LIGHTING);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, viewportCoods[2], 0.0, viewportCoods[3]);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glRasterPos2i(x, viewportCoods[3]-y);
    
    while(*txt){glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *txt); txt++;}
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    
    if(lightning) glEnable(GL_LIGHTING);
}
