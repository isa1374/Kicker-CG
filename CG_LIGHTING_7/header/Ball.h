#pragma once
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#else
	#include "freeglut.h"
#endif

class Ball {
	public:
		Ball(); 
		~Ball(); 

		void draw(); 
};