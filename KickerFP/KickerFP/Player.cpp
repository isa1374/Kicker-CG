//
//  Player.cpp
//  KickerFP
//
//  Created by Karla on 23/11/17.
//  Copyright © 2017 Isa. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "glm.h"
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
    
}

Player::~Player(){
    
}

bool Player::inCollision(Player* other){
    
    return false;
}

void Player::draw(){
        //glTranslatef(posx, posy, posz);
        glmDraw(player, GL_SMOOTH);
}



void Player::update(float x, float y, float rt){
    posx = x;
    posz = y;
    rot = rt;
}


