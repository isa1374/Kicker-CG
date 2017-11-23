//
//  Player.h
//  KickerFP
//
//  Created by Karla on 23/11/17.
//  Copyright © 2017 Isa. All rights reserved.
//
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "glm.h"

#ifndef Player_h
#define Player_h
class Player{
public:
    Player(bool gk, float x, float z);
    ~Player();
    
    bool inCollision(Player* other);
    void draw();
    void update(float x, float y, float rot);
    
    GLMmodel* player= glmReadOBJ("/Users/issac/Desktop/Kicker-CG/KickerFP/KickerFP/assets/Cyborg.obj");
    float posx;
    float posy;
    float posz;
    int rot;
    float radius;
    bool goalkeeper;
    float diffuse[3];
};

#endif /* Player_h */
