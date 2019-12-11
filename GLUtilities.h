//Filename: GLUtilities.h
//Description: 
//Author: Jenna Pierce
//Date Modified: 11/05/19

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "Material.h"

#pragma once
#if !defined(_GL_UTILITIES_H_)
#define _GL_UTILITIES_H_

void drawTexturedCube(Material mats[], float w = 0.5);
void drawTexturedRectangle(Material mats[], float w = 0.5);
void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z); 
GLfloat getStrokeTextWidth(char *text, void *font);
void drawBitmapText(char *text, void *font, int x, int y);
GLfloat getBitmapTextWidth(char *text, void *font);

void buildCube();
void buildPyramid();

#endif