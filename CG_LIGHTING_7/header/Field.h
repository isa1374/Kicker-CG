#pragma once
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

class Field {
	public:
		Field(); 
		~Field(); 

		void draw(); 

		float px = 0;
		float py = 0;
		float radio;
		float calx;
		float caly;

};