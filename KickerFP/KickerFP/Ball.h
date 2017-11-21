#pragma once
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


class Ball {
	public:
		Ball();
		~Ball();
    
        bool isMoving;
        float initialVel;
        float decreaseVel;
        float posx;
        float posy;
        float posz;
    
		void draw();
        void inMotion(float vi, float dv);
        void stopMotion();
        void reset();
};
