//Filename: Final_Pierce
//Description: 
//Author: Jenna Pierce
//Date Modified: 12/12/19

#include <iostream>  
using namespace std;
#include "GLUtilities.h"
#include <irrklang.h>

#if defined __APPLE__
    #include <GLUT/glut.h>

#elif defined _WIN32 || defined _WIN64
    #include <GL\glut.h>

#elif defined __linux__
    #include <GL/freeglut.h> 
#endif

#include "Camera.h"
#include "Material.h"

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

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);   
    glutInitWindowPosition(50, 50); 
		
	glutCreateWindow("Slip");    
    glutDisplayFunc(&display); 
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardClick);
    glutSpecialFunc(specialInput);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);
    glutTimerFunc(20, timer, 20);

	ground.load("planets/stars.tga");
	materials[0].load("planets/stars.tga");
	materials[1].load("planets/stars.tga");
	materials[2].load("planets/stars.tga");
	materials[3].load("planets/stars.tga");
	materials[4].load("planets/stars.tga");
	materials[5].load("planets/stars.tga");
	sky.load("planets/stars.tga");

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

	char text[80];
    GLfloat textWidth = 0.0;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear out the color and depth buffer
    glMatrixMode(GL_MODELVIEW);     // Go into model mode
    glEnable(GL_CULL_FACE);        // Won't draw back sides
    
    glLoadIdentity();

	//I try to run but I slip away cube...
    glPushMatrix();
    glRotatef(rotationX, 0.0f, 1.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.4f);
	glTranslatef(0.0f, 0.0f, 36.0f);
	drawTexturedRectangle(materials, 6.0);
    glPopMatrix();

	glColor3f(152.0/255.0f, 118.0/255.0f, 177.0/255.0f); //purple
    glPushMatrix();
	strcpy(text, "I try to run"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 1000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

    glColor3f(83.0/255.0f, 200.0/255.0f, 172.0/255.0f); //blue
    glPushMatrix();
	strcpy(text, "but I slip away..."); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 1000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	//It's hard to remember the things you say cube...
    glPushMatrix();
    glRotatef(rotationX, 0.0f, 1.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.4f);
	glTranslatef(0.0f, 0.0f, 106.0f);
	drawTexturedRectangle(materials, 6.0);
    glPopMatrix();


	glColor3f(251.0/255.0f, 248.0/255.0f, 125.0/255.0f); // yellow    
	glPushMatrix();
	strcpy(text, "It's hard to remember"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 4000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

    glColor3f(252.0/255.0f, 198.0/255.0f, 110.0/255.0f); //orange
	glPushMatrix();
	strcpy(text, "the things you say"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 4000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	//I'm falling faster everydaycube...
    glPushMatrix();
    glRotatef(rotationX, 0.0f, 1.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.4f);
	glTranslatef(0.0f, 0.0f, 216.0f);
	drawTexturedRectangle(materials, 6.0);
    glPopMatrix();

    glColor3f(242.0/255.0f, 152.0/255.0f, 177.0/255.0f); //pink 
	glPushMatrix();
	strcpy(text, "I'm falling faster'"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 8000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

 	glColor3f(170.0/255.0f, 214.0/255.0f, 132.0/255.0f); //green
	glPushMatrix();
	strcpy(text, "everyday"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 8000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

    glColor3f(242.0/255.0f, 152.0/255.0f, 177.0/255.0f); //pink 
	glPushMatrix();
	strcpy(text, "Why"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 12000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	glColor3f(252.0/255.0f, 198.0/255.0f, 110.0/255.0f); //orange
	glPushMatrix();
	strcpy(text, "oh why"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 14000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

    glColor3f(83.0/255.0f, 200.0/255.0f, 172.0/255.0f); //blue
	glPushMatrix();
	strcpy(text, "oh why"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 16000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	glColor3f(152.0/255.0f, 118.0/255.0f, 177.0/255.0f); //purple
	glPushMatrix();
	strcpy(text, "Why"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 18000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	glColor3f(251.0/255.0f, 248.0/255.0f, 125.0/255.0f); // yellow    
	glPushMatrix();
	strcpy(text, "can't I"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 20000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

	//Why's cube...
    glPushMatrix();
    glRotatef(rotationX, 0.0f, 1.0f, 0.0f);
    glScalef(0.4f, 0.4f, 0.4f);
	glTranslatef(0.0f, 0.0f, 516.0f);
	drawTexturedRectangle(materials, 6.0);
    glPopMatrix();

 	glColor3f(170.0/255.0f, 214.0/255.0f, 132.0/255.0f); //green
	glPushMatrix();
	strcpy(text, "your air"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, -250.0f, 22000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();

 	glColor3f(170.0/255.0f, 214.0/255.0f, 132.0/255.0f); //green
	glPushMatrix();
	strcpy(text, "Breath in"); 
    textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
    glScalef(-0.01f, 0.01f, 0.01f);
    glTranslatef(-textWidth*0.5, 200.0f, 22000.0f);
    glLineWidth(1.0f);
    drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
    glPopMatrix();  

	GLfloat groundSize = 1000.0f;
	GLfloat groundLocation = -15.0f;
	GLfloat repeatNum = groundSize / 10.0f;
	
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
	
	avatarPOV.setupCamera(CAM_PROJ_PERSPECTIVE, width, height, 45.0f, 0.01f, 1000.0f);
	gluPerspective(60, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1, 500.0);
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