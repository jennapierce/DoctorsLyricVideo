// Filename: GLUtilities.h
// Description: Tools for OpelGL
// Author: Scott McDermott
// Date Created: 11/13/2018

#include <GL/glut.h>
#include "Material.h"

#pragma once
#if !defined (_GL_UTILITIES_H_)
#define _GL_UTILITIES_H_

void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z);
GLfloat getStrokeTextWidth(char *text, void *font);

void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y);
GLfloat getBitmapTextWidth(char *text, void *font);

void drawTexturedCube(Material mats[], float w = 0.5);
void drawCube();
void drawPyramid();

#endif //_GL_UTILITIES_H_
