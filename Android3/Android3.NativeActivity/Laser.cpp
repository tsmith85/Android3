#include "Laser.h"
#include <iostream>
#include "engine.h"
using namespace std;

Laser::Laser()
{
}

Laser::~Laser()
{
}

float Laser::getPosition_x(float x)
{
	return position_x;
}

float Laser::getPosition_y(float y)
{
	return position_y;
}

void Laser::moveLaserEvent(float x, float y)
{
	Laser::position_x = x + 1.01f;
	Laser::position_y = y + 1.01f;
}

void Laser::draw(float position[])
{
	GLfloat line[] = {
		0,0,0,
		100,100,0
	}; // vertices for a line on screen

	GLfloat colors[] = {
		255, 187, 122, 50,
		255, 150, 123, 230,
		124, 150, 87, 220
	}; // sets the color of each vertex

	GLuint buffers[1]; // sets a buffer for vertices and indices, in this example we are just doing a vbo (vertex buffer object)

	glGenBuffers(1, buffers); // preparing the vbo 

	int vbo = buffers[0]; // set the first buffer for vertex

	// Transfer vertex data to VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6, line, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// draw object
	glVertexPointer(3, GL_FLOAT, 0, line);
	glTranslatef(0.0f, 0.0f, -3.0f);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glDrawArrays(GL_LINES, 0, 2);

}
