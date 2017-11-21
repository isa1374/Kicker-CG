#pragma once

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


class Field {
	public:
		Field(); 
		~Field(); 

		void draw(); 

		float px = 0;
		float py = 0;
		float radio=2.0;
		float calx;
		float caly;

};
