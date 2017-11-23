#pragma once
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


class Ball {
	public:
		Ball();
		~Ball();

        float initialVel;
        float decreaseVel;
        float posx;
        float posy;
        float posz;
        float oldposx;
        float oldposy;
        float oldposz;
        float radius;
    
		void draw();
        void inMotion(float vi, float dv);
        void stopMotion();
        void update(float posx, float posz);
        bool inCollision(float x, float y, float r);
        void reset();
};
