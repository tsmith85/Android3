#include "Cube.h"
#include "engine.h" 
#include <iostream>
using namespace std;

Cube::Cube()
{
}

Cube::~Cube()
{
}

float Cube::getAngle_x()
{
	return angle_x;
}

float Cube::getAngle_y()
{
	return angle_y;
}

void Cube::rotateCubeEvent(float x, float y)
{
	Cube::angle_x = x + 1.01f;
	Cube::angle_y = y + 1.01f;
}

void Cube::draw(GLfloat colors[][4], float position[3])
{
/*	GLint vertices[][3] =
	{
		{ -0x10000, -0x10000, -0x10000 },
	{ 0x10000, -0x10000, -0x10000 },
	{ 0x10000,  0x10000, -0x10000 },
	{ -0x10000,  0x10000, -0x10000 },
	{ -0x10000, -0x10000,  0x10000 },
	{ 0x10000, -0x10000,  0x10000 },
	{ 0x10000,  0x10000,  0x10000 },
	{ -0x10000,  0x10000,  0x10000 }
	};*/
	
	/*GLubyte indices[] = {
		0, 4, 5,    0, 5, 1,
		1, 5, 6,    1, 6, 2,
		2, 6, 7,    2, 7, 3,
		3, 7, 4,    3, 4, 0,
		4, 7, 6,    4, 6, 5,
		3, 0, 1,    3, 1, 2
	};*/

	GLfloat vertices[][3] = {
		{ 1.000000f, -1.000000f, -1.000000f },
	{ 1.000000f, -1.000000f, 1.000000f },
	{ -1.000000f, -1.000000f, 1.000000f },
	{ -1.000000f, -1.000000f, -1.000000f },
	{ 1.000000f, 1.000000f, -0.999999f },
	{ 0.999999f, 1.000000f, 1.000001f },
	{ -1.000000f, 1.000000f, 1.000000f },
	{ -1.000000f, 1.000000f, -1.000000f }
	};

	/*GLubyte indices[] = {
		2, 4, 1,     
		8, 6, 5,
		5, 2, 1,
		6, 3, 2,
		3, 8, 4,
		1, 8, 5,
		2, 3, 4,
		8, 7, 6,
		5, 6, 2,
		6, 7, 3,
		3, 7, 8,
		1, 4, 8
	};*/

	GLubyte indices[] = {
		1, 3, 0,	1, 2, 3,    // f1
		7, 5, 4,	7, 6, 5,	// f2
		4, 1, 0,    4, 5, 1,    // f3
		5, 2, 1,	5, 6, 2,    // f4
		2, 7, 3,	2, 6, 7,    // f5
		0, 7, 4,	0, 3, 7		// f6
	}; // when copying values from blender opbject reduce each by 1

	GLuint buffers[2]; // sets a buffer for vertices and indices, in this example we are just doing a vbo (vertex buffer object)

	glGenBuffers(2, buffers); // preparing the vbo 

	int vbo = buffers[0]; // set the first buffer for vertex
	int ibo = buffers[1]; // set the second buffer for index

	// Transfer vertex data to VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 24, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Transfer index data to IBO
	glBindBuffer(GL_ARRAY_BUFFER, ibo);
	glBufferData(GL_ARRAY_BUFFER, 36, indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glPushMatrix();
	glTranslatef(position[0], position[1], position[2]);
	glRotatef(angle_x * 0.25f, 1, 0, 0);  // X
	glRotatef(angle_y, 0, 1, 0);          // Y

	glScalef(-0.8f, -0.8f, 1.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glFrontFace(GL_CCW); // Counter-Clockwise works when bringing in object from Blender
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(4, GL_FLOAT, 0, colors);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
	glPopMatrix();
}