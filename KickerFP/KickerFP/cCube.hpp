#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include "cTexture.hpp"

#ifndef __CUBE
#define __CUBE

class Cube
{
public:
    Cube    (    float    side,
             bool    use_mipmaps    );
    ~Cube    (    void                );
    
    void    draw    (    void                );
    
private:
    float    side;
    float    hside;
    float hside2;
    Texture targas[6];
    
    float px = 0;
    float py = 0;
    float radio=2.0;
    float calx;
    float caly;
    
};

#endif __CUBE

