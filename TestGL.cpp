#include <stdlib.h>
#include <GL/glut.h>

void keyboard(unsigned char key, int x, int y);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("GLUT Test");
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutKeyboardFunc(&keyboard);
	glutDisplayFunc(&display);
	glutMainLoop();

	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case '\x1B':
			exit(EXIT_SUCCESS);
		break;
	}
}


void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
	  glVertex2f(-0.5f, -0.5f);
	  glVertex2f( 0.5f, -0.5f);
	  glVertex2f( 0.5f,  0.5f);
	  glVertex2f(-0.5f,  0.5f);
	glEnd();

	glFlush();
}