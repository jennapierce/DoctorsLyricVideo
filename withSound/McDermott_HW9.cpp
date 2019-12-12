// Filename: McDermott_HW9.cpp
// Description: Solar System
// Author: Scott McDermott
// Date Created: 9/20/2018

#include "GLUtilities.h"
#include "Camera.h"
#include "Material.h"
#include <time.h>

// https://www.ambiera.com/irrklang/docu/index.html
#include "./irrKlang/irrKlang.h"
using namespace irrklang;

#include <iostream>
using namespace std;

//Prototypes...
void resetScene();
void enableLights();
void display(void);
void reshape(GLsizei width, GLsizei height);
void keyboardClick(unsigned char key, int x, int y);
void specialInput(int key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void timer(int millisec);


GLfloat locationX, locationY;	// Current location of the object
GLfloat rotationX, rotationY;	// Current rotation of the object
GLsizei mouseX, mouseY;			// Current mouse location in the window
int orbitRotation;				// Rotation in degrees
bool blEnableLights = true;
bool blMouseLeftDown;			// Current state of the button
bool blMouseMiddleDown;			// Current state of the button
bool blMouseRightDown;			// Current state of the button

GLsizei screenWidth = 640;
GLsizei screenHeight = 480;

Camera avatarPOV;

clock_t previousTime;
clock_t currentTime;
double hoursPerMS = 360;
GLfloat planetScale = 1.0f;
GLfloat sunScale = 0.02;

const int NUMOBJECTS = 12;

// https://nssdc.gsfc.nasa.gov/planetary/factsheet/
struct solarObject {
	char name[20];
	GLfloat radius;		// 10^3 km
	GLint distance;			// 10^3 km
	GLint orbitalPeriod;	// hours
	GLfloat dayLength;		// hours
	int numMoons;
	bool isStar;
	int orbitsAround;
	Material material;
	GLUquadric *q;
	GLfloat currentOrbit;
	GLfloat currentRotation;
};

solarObject solarObjects[NUMOBJECTS] = {
//name,		 radius,   distance,	orbitalPeriod,	dayLength,	numMoons,	isStar,	orbitsAround
//			10^3 km		10^3 km		hours			hours
{"sun",		 696.0f,	      1,		      1,	 648.0f,		0,		true,		0},
{"mercury",	 2.440f,	  57900,		   2112,	4222.6f,		0,		false,		0},
{"venus",	 6.052f,	 108200,		   5393, 	2802.0f,		0,		false,		0},
{"moon",	 1.738f,	    384,		    655,	 708.7f,		0,		false,		4},
{"earth",	 6.378f,	 149600,		   8765,	  24.0f,		1,		false,		0},
{"mars",	 3.396f,	 227900,		  16488,	  24.7f,		2,		false,		0},
{"jupiter",	71.492f,	 778600,		 103944,	   9.9f,		79,		false,		0},
{"saturn",	60.268f,	1433500,		 257928,	  10.7f,		62,		false,		0},
{"uranus",	25.559f,	2872500,		 734136,	  17.2f,		27,		false,		0},
{"neptune",	24.764f,	4495100,		1435200,	 -16.1f,		14,		false,		0},
{"pluto",	 1.185f,	5906400,		2173440,	-153.3f,		5,		false,		0},
{"stars",	2000.0f,	      1,		      1,	   0.0f,		0,		true,		0}

};

int main(int argc, char** argv)
{
	// start the sound engine with default parameters
	ISoundEngine* engine = createIrrKlangDevice();
	if (!engine)
	{
		printf("Could not startup engine\n");
		return 0; // error starting up the engine
	}

	// play some sound stream, looped
	engine->play2D("getout.ogg", true);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);	// Enable double buffer mode
	glutInitWindowSize(screenWidth, screenHeight);	// Set the window's initial width and height
	glutInitWindowPosition(50, 50);	// Position the window's initial top-left corner
	glutCreateWindow("Solar System");

	glutDisplayFunc(&display);			// Callback for display refresh
	glutReshapeFunc(&reshape);			// Callback window resizing
	glutKeyboardFunc(&keyboardClick);	// Callback function for key presses
	glutSpecialFunc(&specialInput);		// Callback function for arrow keys
	glutMouseFunc(&mouseClick);			// Callback function for mouse clicks
	glutMotionFunc(&mouseMotion);		// Callback function for mouse movement
	glutTimerFunc(20, &timer, 20);		// Redraw every 20 ms
	

	srand(time(0));
	char filename[20];
	for (int i = 0; i < NUMOBJECTS; i++)
	{
		sprintf(filename, "planets\\%s.tga", solarObjects[i].name);
		solarObjects[i].material.load(filename);
		solarObjects[i].q = gluNewQuadric();			// Create a new quadric
		gluQuadricNormals(solarObjects[i].q, GL_SMOOTH);	// Generate smooth normals for the quad
		gluQuadricTexture(solarObjects[i].q, GL_TRUE);	// Enable texture coords for the quad
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);	// Setup sphere mapping
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
		solarObjects[i].currentOrbit = 1 + rand() % 360;
		solarObjects[i].currentRotation = 1 + rand() % 360;
	}
	
	resetScene();
	glutMainLoop();
	return EXIT_SUCCESS;
}

void resetScene()
{
	avatarPOV.setLocation(0.0f, 3.0f, -85.0f);
	avatarPOV.setRotation(0.0f, 0.0f, 1.0f);
	locationX = 0.0f;
	locationY = 0.0f;
	rotationX = 0.0f;
	rotationY = 0.0f;
	orbitRotation = 0;
	mouseX = 0;
	mouseY = 0;
	blMouseLeftDown = false;
	blMouseMiddleDown = false;
	blMouseRightDown = false;
	blEnableLights = false;
	screenWidth = 640;
	screenHeight = 480;
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// Set the background color to black and opaque
	glClearDepth(1.0f);						// Set the background to farthest away
	glEnable(GL_DEPTH_TEST);				// Enable depth test for z-culling
	glDepthFunc(GL_LEQUAL);					// Set the depth to be in front of the background
	glShadeModel(GL_SMOOTH);				// Set to smooth shading (or flat!)
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Use best perspective correction
	enableLights();
	reshape(screenWidth, screenHeight);

	previousTime = clock();
	hoursPerMS = 360;
	planetScale = 1.0f;
	sunScale = 0.02;

	glutPostRedisplay();	
}

void enableLights()
{
	if (blEnableLights)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);	// Make it not grey...
		
		GLfloat lightKa[] = {0.2f, 0.2f, 0.2f, 1.0f};	// ambient light
		GLfloat lightKd[] = {0.7f, 0.7f, 0.7f, 1.0f};	// diffuse light
		GLfloat lightKs[] = {1.0f, 1.0f, 1.0f, 1.0f};	// specular light
		
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);
		
		// Position the light
		GLfloat lightPos[] = {0.0f, 0.0f, -20.0f, 1.0f};		// positional light
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
		
		glEnable(GL_LIGHT0);
	}
	else
		glDisable(GL_LIGHTING);
}

void reshape(GLsizei width, GLsizei height)
{
	if (height <= 0) height = 1;	// Sanity
	if (width <= 0) width = 1;		// Sanity
	screenWidth = width;
	screenHeight = height;

	avatarPOV.setupCamera(CAM_PROJ_PERSPECTIVE, width, height, 45.0f, 0.01f, 5000.0f);
	
	// Set the viewport to cover the new window size
	glViewport(0, 0, width, height);
}

void display()
{
	reshape(screenWidth, screenHeight);
//	avatarPOV.setLocation(0.0f, 0.0f, orbitRotation);
	avatarPOV.runCamera();
	
	enableLights();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear out the color and depth buffers	
	glMatrixMode(GL_MODELVIEW);			// Go into model mode
	glLoadIdentity();					// Reset stuff in current mode	
	glEnable(GL_CULL_FACE);

	currentTime = clock();
	double timeDifference = (double)(currentTime - previousTime);
//	cout << "time diff (" << (double)timeDifference << " seconds)" << endl;

	// Draw the planets
	int i;
	GLfloat objectScale = 1;
	GLfloat disanceScale = 0.001;

	for (i = 0; i < NUMOBJECTS-1; i++)
	{
		objectScale = planetScale;
		if (solarObjects[i].orbitsAround != 0)
		{ // draw the moons
			int orbiting = solarObjects[i].orbitsAround;
			glPushMatrix();
			gluQuadricOrientation(solarObjects[i].q, GLU_OUTSIDE);
			solarObjects[i].material.setupMaterial();
			glRotatef(solarObjects[orbiting].currentOrbit, 0.0f, 1.0f, 0.0f);
			glTranslatef((GLfloat)solarObjects[orbiting].distance * disanceScale, 0.0, 0.0);
			//glRotatef(solarObjects[orbiting].currentRotation, 0.0f, 1.0f, 0.0f);
			glRotatef(solarObjects[i].currentOrbit, 0.0, 1.0, 0.0);
			glTranslatef((GLfloat)solarObjects[i].distance * disanceScale * 50.0, 0.0, 0.0);
			glRotatef(solarObjects[i].currentRotation, 0.0f, 1.0f, 0.0f);
			glRotatef(270, 1.0f, 0.0f, 0.0f);
			gluSphere(solarObjects[i].q, solarObjects[i].radius * objectScale, 30, 30);
			solarObjects[i].material.stopMaterial();
			glPopMatrix();

		}
		else
		{
			if (!strcmp(solarObjects[i].name, "sun")) objectScale = sunScale;
			glPushMatrix();
			gluQuadricOrientation(solarObjects[i].q, GLU_OUTSIDE);
			solarObjects[i].material.setupMaterial();
			if (strcmp(solarObjects[i].name, "sun")) 
				glRotatef(solarObjects[i].currentOrbit, 0.0, 1.0, 0.0);
			glTranslatef((GLfloat)solarObjects[i].distance * disanceScale, 0.0, 0.0);
			glRotatef(solarObjects[i].currentRotation, 0.0f, 1.0f, 0.0f);
			glRotatef(270, 1.0f, 0.0f, 0.0f);
			gluSphere(solarObjects[i].q, solarObjects[i].radius * objectScale, 30, 30);
			solarObjects[i].material.stopMaterial();
			glPopMatrix();

		}
		// Update the location...
		solarObjects[i].currentOrbit += timeDifference * hoursPerMS / (GLfloat)solarObjects[i].orbitalPeriod;
		if (solarObjects[i].currentOrbit > 360.0) solarObjects[i].currentOrbit =- 360.0;
		solarObjects[i].currentRotation += timeDifference * hoursPerMS / (GLfloat)solarObjects[i].dayLength;
		if (solarObjects[i].currentRotation > 360.0) solarObjects[i].currentRotation =- 360.0;
	}

	// draw the stars last
	glPushMatrix();
	gluQuadricOrientation(solarObjects[i].q, GLU_INSIDE);
	solarObjects[i].material.setupMaterial();
	gluSphere(solarObjects[i].q, solarObjects[i].radius, 30, 30);
	solarObjects[i].material.stopMaterial();

	glPopMatrix();

	previousTime = clock();
	glutSwapBuffers();
}

void keyboardClick(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: case 'q': case 'Q':
			exit(EXIT_SUCCESS);
			break;
		case 'L':
			blEnableLights = !blEnableLights;
			break;
		case 'r': case 'R':
			resetScene();
			break;
		case 'w':
			avatarPOV.moveForward(0.1f);
			break;
		case 's':
			avatarPOV.moveBackward(0.1f);
			break;
		case 'a':
			avatarPOV.strafeLeft(-0.1f);
			break;
		case 'd':
			avatarPOV.strafeRight(-0.1f);
			break;
		case 'i':
			avatarPOV.moveForward(20.0f);
			break;
		case 'k':
			avatarPOV.moveBackward(20.0f);
			break;
		case 'j':
			avatarPOV.turnLeft(-0.1f);
			break;
		case 'l':
			avatarPOV.turnRight(-0.1f);
			break;
		case '[':
			avatarPOV.moveUp(-10.0f);
			break;
		case ']':
			avatarPOV.moveDown(-10.0f);
			break;
		case '(':
			planetScale -= 0.5f;
			break;
		case ')':
			planetScale += 0.5f;
			break;
		case '+':
			hoursPerMS += 10.0f;
			break;
		case '-':
			hoursPerMS -= 10.0f;
			break;
		case 't':
			avatarPOV.setLocation(0.0f, 500.0f, 0.0f);
			avatarPOV.setRotation(0.0f, -90.0f, 0.0f);
			break;

	}
	glutPostRedisplay();
}

void specialInput(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			avatarPOV.moveForward();
			break;
		case GLUT_KEY_DOWN:
			avatarPOV.moveBackward();
			break;
		case GLUT_KEY_RIGHT:
			avatarPOV.strafeLeft();
			break;
		case GLUT_KEY_LEFT:
			avatarPOV.strafeRight();
			break;
	}
	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y)
{
	mouseX = x;
	mouseY = y;
//	cout << "button=" << button << ", state= " << state << endl;
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN) blMouseLeftDown = true;
		else blMouseLeftDown = false;
	}
	if (button == GLUT_MIDDLE_BUTTON)
	{
		if (state == GLUT_DOWN) blMouseMiddleDown = true;
		else blMouseMiddleDown = false;
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) blMouseRightDown = true;
		else blMouseRightDown = false;
	}
}

void mouseMotion(int x, int y)
{
	if (blMouseLeftDown)
	{
		if (mouseX > x) avatarPOV.turnRight(0.3f);
		if (mouseX < x) avatarPOV.turnLeft(0.3f);
		if (mouseY < y) avatarPOV.lookUp(0.3f);
		if (mouseY > y) avatarPOV.lookDown(0.3f);
		rotationX += (x - mouseX);
		rotationY -= (y - mouseY);
	}
	if (blMouseRightDown)
	{
		if (mouseX > x) avatarPOV.strafeRight(0.3f);
		if (mouseX < x) avatarPOV.strafeLeft(0.3f);
		if (mouseY < y) avatarPOV.moveForward(0.3f);
		if (mouseY > y) avatarPOV.moveBackward(0.3f);
		locationX += 10.0 * (x - mouseX) / screenWidth;
		locationY -= 10.0 * (y - mouseY) / screenHeight;
	}
	mouseX = x;
	mouseY = y;
	glutPostRedisplay();
}

void timer(int millisec)
{
	orbitRotation++;
//	if (orbitRotation >= 360) orbitRotation = 0;
	glutTimerFunc(millisec, &timer, millisec);		// Redraw every millisec ms
	glutPostRedisplay();
}



