#include "GLUtilities.h" 


void drawTexturedCube(Material mats[], float w) {

	float vertices [8] [3] = {{  w,  w,  w}, //V0
							  { -w,  w,  w}, //V1
							  { -w, -w,  w}, //V2
	                          {  w, -w,  w}, //V3
							  {  w, -w, -w}, //V4
                              {  w,  w, -w}, //V5
							  { -w,  w, -w}, //V6
							  { -w, -w, -w}};//V7

	static int links [6][4] = {{0, 1, 2, 3}, //Front
							   {0, 3, 4, 5}, //Right
							   {0, 5, 6, 1}, //Up
							   {7, 6, 5, 4}, //Back
							   {7, 2, 1, 6}, //Left
							   {7, 4, 3, 2}}; //Down
							   
							   
	for (int f = 0; f < 6; f++)
	{
		glPushMatrix();
		mats[f].setupMaterial();
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(vertices[links[f][0]][0], vertices[links[f][0]][1], vertices[links[f][0]][2]);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(vertices[links[f][1]][0], vertices[links[f][1]][1], vertices[links[f][1]][2]);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[links[f][2]][0], vertices[links[f][2]][1], vertices[links[f][2]][2]);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(vertices[links[f][3]][0], vertices[links[f][3]][1], vertices[links[f][3]][2]);
		
		
		glEnd();
		mats[f].stopMaterial();
		glPopMatrix();
	}
}

void drawTexturedRectangle(Material mats[], float w) {

	float vertices [8] [3] = {{  w*2,  w,  w}, //V0
							  { -w*2,  w,  w}, //V1
							  { -w*2, -w,  w}, //V2
	                          {  w*2, -w,  w}, //V3
							  {  w*2, -w, -w}, //V4
                              {  w*2,  w, -w}, //V5
							  { -w*2,  w, -w}, //V6
							  { -w*2, -w, -w}};//V7

	static int links [6][4] = {{0, 1, 2, 3}, //Front
							   {0, 3, 4, 5}, //Right
							   {0, 5, 6, 1}, //Up
							   {7, 6, 5, 4}, //Back
							   {7, 2, 1, 6}, //Left
							   {7, 4, 3, 2}}; //Down
							   
							   
	for (int f = 0; f < 6; f++)
	{
		glPushMatrix();
		mats[f].setupMaterial();
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(vertices[links[f][0]][0], vertices[links[f][0]][1], vertices[links[f][0]][2]);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(vertices[links[f][1]][0], vertices[links[f][1]][1], vertices[links[f][1]][2]);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(vertices[links[f][2]][0], vertices[links[f][2]][1], vertices[links[f][2]][2]);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(vertices[links[f][3]][0], vertices[links[f][3]][1], vertices[links[f][3]][2]);
		
		
		glEnd();
		mats[f].stopMaterial();
		glPopMatrix();
	}
}

void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z) {

    glPushMatrix();
    glTranslatef(x, y, z);
    char *c;
    
    for (c = text; *c; c++) {

        glutStrokeCharacter(font, *c);
    }

    glPopMatrix();
}

GLfloat getStrokeTextWidth(char *text, void *font){

    GLfloat w = 0.0f; 
    char *c;
    
    for (c = text; *c; c++) {

        w += glutStrokeWidth(font, *c);
    }
    return w;
}

void drawBitmapText(char *text, void *font, int x, int y) {
  
    glPushMatrix();
    glRasterPos2f(x, y);

    char *c;
    
    for (c = text; *c; c++)  {

        glutBitmapCharacter(font, *c);
    }

    glPopMatrix();

}

GLfloat getBitmapTextWidth(char *text, void *font) {

    float w = 0.0;
	
    char *c;
	for (c = text; *c; c++)
		w += glutBitmapWidth(font, *c);
	
    return w;
}

void buildCube() {

    glBegin(GL_QUADS); 
    //top face y = 1
    glColor3f(94.0/255.0f, 100.0/255.0f, 114.0/255.0f); //cadet
    glVertex3f(1.0f, 1.0f, 1.0f); //a 
    glVertex3f(1.0f, 1.0f, -1.0f); //f    
    glVertex3f(-1.0f, 1.0f, -1.0f); //e 
    glVertex3f(-1.0f, 1.0f, 1.0f); //b 

    //Front face where z = 1
    glColor3f(255.0/255.0f, 166.0/255.0f, 158.0/255.0f); //redish
    glVertex3f(1.0f, 1.0f, 1.0f); //a
    glVertex3f(-1.0f, 1.0f, 1.0f); //b
    glVertex3f(-1.0f, -1.0f, 1.0f); //c
    glVertex3f(1.0f, -1.0f, 1.0f); //d
        
    //Back face z = -1
    glColor3f(174.0/255.0f, 217.0/255.0f, 224.0/255.0f); //blue
    glVertex3f(-1.0f, 1.0f, -1.0f); //e       
    glVertex3f(1.0f, 1.0f, -1.0f); //f
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(-1.0f, -1.0f, -1.0f); //g

    //Bottom face y = -1
    glColor3f(94.0/255.0f, 100.0/255.0f, 114.0/255.0f); //cadet
    glVertex3f(-1.0f, -1.0f, 1.0f); //c
    glVertex3f(-1.0f, -1.0f, -1.0f); //g
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(1.0f, -1.0f, 1.0f); //d

    //Left face x = -1
    glColor3f(184.0/255.0f, 242.0/255.0f, 230.0/255.0f); //turquoise
    glVertex3f(-1.0f, 1.0f, 1.0f); //b 
    glVertex3f(-1.0f, 1.0f, -1.0f); //e 
    glVertex3f(-1.0f, -1.0f, -1.0f); //g 
    glVertex3f(-1.0f, -1.0f, 1.0f); //c 

    //Right face z = -1
    glColor3f(250.0/255.0f, 243.0/255.0f, 221.0/255.0f); //beige
    glVertex3f(1.0f, 1.0f, 1.0f); //a
    glVertex3f(1.0f, -1.0f, 1.0f); //d
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(1.0f, 1.0f, -1.0f); //f
    glEnd();

}

void buildPyramid() {

    glBegin(GL_POLYGON);
    //Bottom face y = -1
    glColor3f(250.0/255.0f, 243.0/255.0f, 221.0/255.0f); //beige
    glVertex3f(-1.0f, -1.0f, 1.0f); //c
    glVertex3f(-1.0f, -1.0f, -1.0f); //g
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(1.0f, -1.0f, 1.0f); //d   
    glEnd();

    glBegin(GL_TRIANGLES);
    //Front face 
    glColor3f(94.0/255.0f, 100.0/255.0f, 114.0/255.0f); //cadet
    glVertex3f(-1.0f, -1.0f, 1.0f); //c
    glVertex3f(1.0f, -1.0f, 1.0f); //d
    glVertex3f(0.0f, 1.0f, 0.0f); //i

    glColor3f(184.0/255.0f, 242.0/255.0f, 230.0/255.0f); //turquoise
    glVertex3f(1.0f, -1.0f, 1.0f); //d
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(0.0f, 1.0f, 0.0f); //i

    glColor3f(174.0/255.0f, 217.0/255.0f, 224.0/255.0f); //blue
    glVertex3f(1.0f, -1.0f, -1.0f); //h
    glVertex3f(-1.0f, -1.0f, -1.0f); //g
    glVertex3f(0.0f, 1.0f, 0.0f); //i

    glColor3f(255.0/255.0f, 166.0/255.0f, 158.0/255.0f); //redish
    glVertex3f(-1.0f, -1.0f, -1.0f); //g
    glVertex3f(-1.0f, -1.0f, 1.0f); //c
    glVertex3f(0.0f, 1.0f, 0.0f); //i
    glEnd();
}