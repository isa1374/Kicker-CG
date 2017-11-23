#include "Ball.h"
#include <iostream>
#include <sstream>
#include <math.h>

Ball::Ball() {
    posx=0.0;
    posy=0.9;
    posz=0.0;
    
    oldposx = posx;
    oldposy = posy;
    oldposz = posz;
    
    radius = .4;
}

Ball::~Ball() {

}

void Ball::inMotion(float vi, float dv){
    initialVel = vi;
    decreaseVel = dv;
}
void Ball::stopMotion(){
    initialVel = 0;
    decreaseVel = 0;
}

void Ball::reset(){
    posx=0.0;
    posy=0.9;
    posz=0.0;
}

bool Ball::inCollision(float x, float y, float r){
    
    float r1 = radius;
    float r2 = r;
    float x1 = posx;
    float x2 = x;
    float z1 = posz;
    float z2 = y;
    
    float dx2 = (x2 - x1)*(x2 - x1);
    float dz2 = (z2 - z1)*(z2 - z1);
    
    float dist = sqrt(dx2 + dz2);
    float sumR2 = (r1 + r2);
    
    
    if (dist < sumR2) {
        return true;
    }
    return false;
}

void Ball::draw() {
    glColor3f(1.0,1.0,0.0);
    glPushMatrix();{
        glTranslatef(posx, posy, posz);
        glRotatef(30,1,0,0);
        glRotatef(30, 0, 1, 0);
        glRotatef(30, 0, 0, 1);
        glColor3f(1, 1, 1);
        glutSolidSphere(radius-.01, 12, 12);
        glColor3f(0, 0, 0);
        glutWireSphere(radius, 12, 12);
    }
    glPopMatrix();
    
}
