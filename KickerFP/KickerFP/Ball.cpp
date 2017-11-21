#include "Ball.h"

Ball::Ball() {
    isMoving = false;
    posx=0.0;
    posy=0.9;
    posz=0.0;
    
    oldposx = posx;
    oldposy = posy;
    oldposz = posz;
}

Ball::~Ball() {

}

void Ball::inMotion(float vi, float dv){
    isMoving=true;
    initialVel = vi;
    decreaseVel = dv;
}
void Ball::stopMotion(){
    isMoving=false;
}

void Ball::reset(){
    isMoving=false;
    posx=0.0;
    posy=0.9;
    posz=0.0;
}

void Ball::update(float x, float z){
    posx = x;
    posz = z;
}

void Ball::draw() {
    glColor3f(1.0,1.0,0.0);
    glPushMatrix();{
        glTranslatef(posx, posy, posz);
        glRotatef(30,1,0,0);
        glRotatef(30, 0, 1, 0);
        glRotatef(30, 0, 0, 1);
        glColor3f(1, 1, 1);
        glutSolidSphere(.37, 12, 12);
        glColor3f(0, 0, 0);
        glutWireSphere(.4, 12, 12);
    }
    glPopMatrix();
    
}
