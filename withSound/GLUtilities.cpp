// Filename: GLUtilities.cpp
// Description: See structural file for details
// Author: Scott McDermott
// Date Created: 11/13/2018


#include "GLUtilities.h"


void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	char *c;
	for (c=text; *c; c++)
	{
		//glColor3f(rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX);
		//glColor3f((*c)/255.0, (*c)/255.0, (*c)/255.0);
		glutStrokeCharacter(font, *c);
	}
	glPopMatrix();
// GLUT_STROKE_ROMAN
// GLUT_STROKE_MONO_ROMAN
}

GLfloat getStrokeTextWidth(char *text, void *font)
{
	GLfloat w = 0.0f;
	char *c;
	for (c=text; *c; c++)
	{
		w += (GLfloat)glutStrokeWidth(font, *c);
	}
	return w;
}

void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y)
{
	glPushMatrix();
	glRasterPos2f(x, y);
	char *c;
	for (c=text; *c; c++)
	{
		//glColor3f(rand()/(float)RAND_MAX, rand()/(float)RAND_MAX, rand()/(float)RAND_MAX);
		//glColor3f((*c)/255.0, (*c)/255.0, (*c)/255.0);
		glutBitmapCharacter(font, *c);
	}
	glPopMatrix();
// GLUT_BITMAP_8_BY_13
// GLUT_BITMAP_9_BY_15
// GLUT_BITMAP_TIMES_ROMAN_10
// GLUT_BITMAP_TIMES_ROMAN_24
// GLUT_BITMAP_HELVETICA_10
// GLUT_BITMAP_HELVETICA_12
// GLUT_BITMAP_HELVETICA_18

}

GLfloat getBitmapTextWidth(char *text, void *font)
{
	GLfloat w = 0.0f;
	char *c;
	for (c=text; *c; c++)
	{
		w += (GLfloat)glutBitmapWidth(font, *c);
	}
	return w;
}


void drawTexturedCube(Material mats[], float w)
{
	// The list of vertices
	float vertices[8][3] = {{  w,  w,  w },		//v0
							{ -w,  w,  w },		//v1
							{ -w, -w,  w },		//v2
							{  w, -w,  w },		//v3
							{  w, -w, -w },		//v4
							{  w,  w, -w },		//v5
							{ -w,  w, -w },		//v6
							{ -w, -w, -w }};	//v7
	
	// Next, the order in which the vertices are linked
	static int faces[6][4] = {{0, 1, 2, 3},		// Front
							  {0, 3, 4, 5},		// Right
							  {0, 5, 6, 1},		// Up
							  {4, 7, 6, 5},		// Back
							  {1, 6, 7, 2},		// Left
							  {2, 7, 4, 3}};	// Bottom
							  
	// Now we can draw each of the quads
	for (int f=0; f<6; f++)
	{
		glPushMatrix();
		mats[f].setupMaterial();
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(vertices[faces[f][0]][0], vertices[faces[f][0]][1], vertices[faces[f][0]][2]);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(vertices[faces[f][1]][0], vertices[faces[f][1]][1], vertices[faces[f][1]][2]);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[faces[f][2]][0], vertices[faces[f][2]][1], vertices[faces[f][2]][2]);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(vertices[faces[f][3]][0], vertices[faces[f][3]][1], vertices[faces[f][3]][2]);
		glEnd();
		mats[f].stopMaterial();
		glPopMatrix();
	}
}


void drawCube()
{	
	glBegin(GL_QUADS);
	  // Top face (y = 1.0f)
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f( 1.0f,  1.0f,  1.0f);  // A
	  glVertex3f( 1.0f,  1.0f, -1.0f);  // F
	  glVertex3f(-1.0f,  1.0f, -1.0f);  // E
	  glVertex3f(-1.0f,  1.0f,  1.0f);  // B	

	  // Bottom face (y = -1.0f)
	  glColor3f(1.0f, 1.0f, 0.0f);
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // C
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // H
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // G
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // D
	  
	  // Front face (z = 1.0f)
	  glColor3f(0.0f, 1.0f, 0.0f);
	  glVertex3f( 1.0f,  1.0f,  1.0f);  // A
	  glVertex3f(-1.0f,  1.0f,  1.0f);  // B
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // C
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // D

	  // Back face (z = -1.0f)
	  glColor3f(0.0f, 1.0f, 1.0f);
	  glVertex3f(-1.0f,  1.0f, -1.0f);  // E
	  glVertex3f( 1.0f,  1.0f, -1.0f);  // F
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // G
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // H
	  
	  // Right face (z = 1.0f)
	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex3f( 1.0f,  1.0f,  1.0f);  // A
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // D
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // G
	  glVertex3f( 1.0f,  1.0f, -1.0f);  // F
	  
	  // Left face (z = -1.0f)
	  glColor3f(0.8f, 0.8f, 0.9f);
	  glVertex3f(-1.0f,  1.0f,  1.0f);  // B
	  glVertex3f(-1.0f,  1.0f, -1.0f);  // E
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // H
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // C
	glEnd();	
}

void drawPyramid()
{
	glBegin(GL_TRIANGLES);
	  // Left face
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f( 0.0f,  1.0f,  0.0f);  // A
	  glColor3f(0.0f, 1.0f, 1.0f);
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // E
	  glColor3f(0.0f, 1.0f, 0.0f);
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // B

	  // Right face
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f( 0.0f,  1.0f,  0.0f);  // A
	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // C
	  glColor3f(1.0f, 1.0f, 0.0f);
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // D

	  // Front face
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f( 0.0f,  1.0f,  0.0f);  // A
	  glColor3f(0.0f, 1.0f, 0.0f);
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // B
	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // C

	  // Back face
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f( 0.0f,  1.0f,  0.0f);  // A
	  glColor3f(1.0f, 1.0f, 0.0f);
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // D
	  glColor3f(0.0f, 1.0f, 1.0f);
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // E
	glEnd();
	
	glBegin(GL_QUADS);
	  // Bottom face (y = -1.0f)
	  glColor3f(0.75f, 0.85f, 0.75f);
//	  glColor3f(0.0f, 1.0f, 0.0f);
	  glVertex3f(-1.0f, -1.0f,  1.0f);  // B
//	  glColor3f(0.0f, 1.0f, 1.0f);
	  glVertex3f(-1.0f, -1.0f, -1.0f);  // E
//	  glColor3f(1.0f, 1.0f, 0.0f);
	  glVertex3f( 1.0f, -1.0f, -1.0f);  // D
//	  glColor3f(0.0f, 0.0f, 1.0f);
	  glVertex3f( 1.0f, -1.0f,  1.0f);  // C
	glEnd();	
}

