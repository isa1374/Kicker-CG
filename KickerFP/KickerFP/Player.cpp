//
//  Player.cpp
//  KickerFP
//
//  Created by Karla on 23/11/17.
//  Copyright © 2017 Isa. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include "Player.h"

Player::Player(bool gk, float x, float z){
    rot = 90;
    radius = .5;
    posx =0;
    posy=0.9;
    posz=0;
    goalkeeper = gk;
    glmUnitize(player);
    glmVertexNormals(player, 45.0f, false);
    glmFacetNormals(player);
    
    diffuse[0] = 0.8f*((float)rand() / (float)RAND_MAX);
    diffuse[1] = ((float)rand() / (float)RAND_MAX);
    diffuse[2] = ((float)rand() / (float)RAND_MAX);
    

}

Player::~Player(){
    
}

bool Player::inCollision(Player* other){
    
    return false;
}

void Player::draw(){
    
    if(goalkeeper){
        diffuse[0]= .81;
        diffuse[1]=.71;
        diffuse[2] =.23;
    }
    
    glEnable(GL_COLOR_MATERIAL);
    glColor3fv(diffuse);
    glmDraw(player, GL_SMOOTH);
}



void Player::update(float x, float y, float rt){
    posx = x;
    posz = y;
    rot = rt;
}


