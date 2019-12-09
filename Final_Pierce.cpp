//Filename: HW8_Pierce
//Description: Textures wrapped on 3D objects and 2D backgrounds
//Author: Jenna Pierce
//Date Modified: 12/08/19

#include "GLUtilities.h"
#include <irrKlang.h>

#if defined __APPLE__
    #include <GLUT/glut.h>

#elif defined _WIN32 || defined _WIN64
    #include <GL\glut.h>

#elif defined __linux__
    #include <GL/freeglut.h> 
#endif

#include "Camera.h"
#include "Material.h"

using namespace irrklang;

void display(void);
void reshape(GLsizei width, GLsizei height);
void resetScene();
void keyboardClick(unsigned char key, int x, int y);
void specialInput(int key2, int x, int y);
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void enableLights();
void timer(int millisec);

bool blEnableLights = false;
GLfloat locationX, locationY;
GLfloat rotationX, rotationY;
int orbitRotation; 
GLsizei prevMouseX, prevMouseY;
bool blMouseLeftDown;
bool blMouseCenterDown;
bool blMouseRightDown;
GLsizei screenWidth = 670;
GLsizei screenHeight = 640;
Camera avatarPOV;

Material ground;
Material materials [6];
Material sky;
GLUquadric *q;

ISoundEngine *SoundEngine = createIrrKlangDevice();

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);   
    glutInitWindowPosition(50, 50); 

	glutCreateWindow("Textures");    
    glutDisplayFunc(&display); 
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardClick);
    glutSpecialFunc(specialInput);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);
    glutTimerFunc(20, timer, 20);

	ground.load("Textures/f2.tga");
	materials[0].load("Textures/f1.tga");
	materials[1].load("Textures/Marble4.tga");
	materials[2].load("Textures/Marble4.tga");
	materials[3].load("Textures/Marble4.tga");
	materials[4].load("Textures/Marble4.tga");
	materials[5].load("Textures/Marble4.tga");
	sky.load("Textures/f4.tga");

	q = gluNewQuadric();
	gluQuadricNormals(q, GL_SMOOTH);
	gluQuadricTexture(q, GL_TRUE);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);	
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

    resetScene();
    glutMainLoop();

    return EXIT_SUCCESS; 

}

void display(void) {
   
	reshape(screenWidth, screenHeight);
	avatarPOV.runCamera();
	enableLights();
    
	SoundEngine->play2D("Doctors  -Slip.mp3", GL_TRUE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear out the color and depth buffer
    glMatrixMode(GL_MODELVIEW);     // Go into model mode
    glDisable(GL_CULL_FACE);        // Won't draw back sides
    
    glLoadIdentity();

    glPushMatrix();
    glRotatef(orbitRotation, 0.0f, 1.0f, 0.0f);
    glScalef(2.6f, 2.6f, 2.6f);
    buildPyramid();
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationX, 0.0f, 0.0f, 3.0f);
    glRotatef(orbitRotation, 0.0f, 1.0f, 1.0f);
    glTranslatef(9.0f, 0.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    glRotatef(orbitRotation, 1.0f, 1.0f, 0.0f);
    drawTexturedCube(materials, 2.0);
    glPopMatrix();    

	GLfloat groundSize = 1000.0f;
	GLfloat groundLocation = -15.0f;
	GLfloat repeatNum = groundSize / 10.0f;
	glPushMatrix();
	ground.setupMaterial();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, repeatNum);
	glVertex3f(-groundSize /2.0f, groundLocation,  groundSize /2.0);
	glTexCoord2f(repeatNum, repeatNum);
	glVertex3f( groundSize /2.0f, groundLocation,  groundSize /2.0);
	glTexCoord2f(repeatNum, 0.0f);
	glVertex3f( groundSize /2.0f, groundLocation, -groundSize /2.0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-groundSize /2.0f, groundLocation, -groundSize /2.0);
	glEnd();
	ground.stopMaterial();
	glPopMatrix();
	
	glPushMatrix(); gluQuadricOrientation(q, GLU_INSIDE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	sky.setupMaterial();
	gluSphere(q, groundSize, 10, 5);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	sky.stopMaterial();
	glPopMatrix();
    
    glutSwapBuffers();  
}

void reshape(GLsizei width, GLsizei height) {

	if (height == 0) height = 1;
	screenWidth = width;
	screenHeight = height;
	
	avatarPOV.setupCamera(CAM_PROJ_PERSPECTIVE, width, height, 45.0f, 0.01f, 2000.0f);
	
	glViewport(0, 0, width, height);
	
}

void resetScene() {
    
	avatarPOV.setLocation(0.0, 0.0, -7.0f);
	avatarPOV.setRotation(0.0f, 0.0f, 1.0f);
	prevMouseX = 0;
	prevMouseY = 0;
    locationX = 0.0f;
    locationY = 0.0f;
    rotationX = 0.0f;
    rotationY = 0.0f;
    orbitRotation = 0;
  
    blMouseLeftDown= false;
    blMouseRightDown = false;
    blMouseCenterDown = false; 
  
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                   // Set the background color to black and opaque
    glClearDepth(1.0f);                                     // Set the background to farthest away
    glEnable(GL_DEPTH_TEST);                                // Enable depth test for z-culling
    glDepthFunc(GL_LEQUAL);                                 // Set the depth to be in front of a background
    glShadeModel(GL_SMOOTH);                                // Set to sooth shading (or flat!)
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // Use best perspective correction
  
    reshape(screenWidth, screenHeight);
	
	glutPostRedisplay();

}

void keyboardClick(unsigned char key, int x, int y) {
    
    switch (key) {
        
		case 27: case 'q':  
			exit(EXIT_SUCCESS);
			break;
		case 'L':
			blEnableLights = !blEnableLights;
			break;
		case 'r':
			resetScene();
			break;
		case 'w':
			avatarPOV.moveForward(0.1f);
			break;
		case 's':
			avatarPOV.moveBackward(0.1f);
			break;
		case 'a':
			avatarPOV.strafeRight(0.1f);
			break;
		case 'd':
			avatarPOV.strafeLeft(0.1f);
			break;
		case 'i':
			avatarPOV.moveForward(20.0f);
			break;
		case 'k':
			avatarPOV.moveBackward(20.0f);
			break;
		case 'j':
			avatarPOV.turnRight(0.5f);
			break;
		case 'l':
			avatarPOV.turnLeft(0.5f);
			break;
	}
		glutPostRedisplay();

}

void specialInput(int key2, int x, int y) {
	
    switch (key2) {
		
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

void mouseClick(int button, int state, int x, int y) {
	
    prevMouseX = x;
	prevMouseY = y;
	
	if(button == GLUT_LEFT_BUTTON) {
		
        if(state == GLUT_DOWN)
			blMouseLeftDown = true;
		else if (state == GLUT_UP)
			blMouseLeftDown = false;
	}
	
	if(button == GLUT_MIDDLE_BUTTON) {
		
        if(state == GLUT_DOWN)
			blMouseCenterDown = true;
		else if (state == GLUT_UP)
			blMouseCenterDown = false;
	}
	
	if(button == GLUT_RIGHT_BUTTON) {

		if(state == GLUT_DOWN)
			blMouseRightDown = true;
		else if (state == GLUT_UP)
			blMouseRightDown = false;
	}	

}

void mouseMotion(int x, int y) {
   
	if (blMouseLeftDown) {
		
        if (prevMouseX > x) avatarPOV.turnRight(0.3f);
		if (prevMouseX < x) avatarPOV.turnLeft(0.3f);
		if (prevMouseX > y) avatarPOV.lookUp(0.3f);
		if (prevMouseX < y) avatarPOV.lookDown(0.3f);
		rotationX += (x - prevMouseX);
		rotationY += (y - prevMouseY);
		prevMouseX = x;
		prevMouseY = y;
		
        glutPostRedisplay();
	}
	
	if (blMouseRightDown){

		if (prevMouseX > x) avatarPOV.strafeRight(0.3f);
		if (prevMouseX < x) avatarPOV.strafeLeft(0.3f);
		if (prevMouseX > y) avatarPOV.moveForward(0.3f);
		if (prevMouseX < y) avatarPOV.moveBackward(0.3f);
		locationX += 10.0 * (x - prevMouseX) / screenWidth;
		locationY -= 10.0 * (y - prevMouseY) / screenHeight;
		prevMouseX = x;
		prevMouseY = y;
		
        glutPostRedisplay();
	}

}

void enableLights() {

    if (blEnableLights) {

        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);

        GLfloat lightKa[] = {0.4f, 0.4f, 0.4f, 1.0f}; //ambient light
        GLfloat lightKd[] = {0.7f, 0.7f, 0.7f, 1.0f}; //diffuse light
        GLfloat lightKs[] = {1.0f, 1.0f, 1.0f, 1.0f}; //specular light

        glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

        GLfloat lightPos[] = {0.0f, 0.0f, -15.0f, 1.0f};

        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        glEnable(GL_LIGHT0);

    }
    else glDisable(GL_LIGHTING);

}

void timer(int millisec) {

    orbitRotation++;
    if (orbitRotation >= 360) orbitRotation = 0;
    glutTimerFunc(20, &timer, 20);
    glutPostRedisplay();

}
