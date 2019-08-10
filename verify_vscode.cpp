// Filename: McDermott_HW1.cpp
// Description: A beginning OpenGL program using C++ and GLUT
// Author: Scott McDermott
// Date Modified: 8/30/2018

#ifdef __APPLE__
#include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include <GL\glut.h>
#endif 

#include <iostream>
using namespace std;

//Prototypes...
void display(void);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);	// Set the window's initial width and height
	glutInitWindowPosition(50, 50);	// Position the window's initial top-left corner
	glutCreateWindow("Hello GL!");
		
	glutDisplayFunc(&display);

	glutMainLoop();
	return EXIT_SUCCESS;
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex2f(-0.5f, -0.5f);
	  glColor3f(0.0f, 1.0f, 0.0f);
	  glVertex2f( 0.5f, -0.5f);
	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex2f( 0.5f,  0.5f);
	  glColor3f(0.2f, 0.1f, 0.3f);
	  glVertex2f(-0.5f,  0.5f);	
	glEnd();
	
	glutSwapBuffers();
}