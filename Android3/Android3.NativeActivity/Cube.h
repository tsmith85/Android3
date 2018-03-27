#pragma once
#include <iostream>
#include "engine.h"
using namespace std;

class Cube
{
private:
	float angle_x = 0;
	float angle_y = 0;

public:
	Cube();
	~Cube();

	float getAngle_x();
	float getAngle_y();
	void rotateCubeEvent(float x, float y);
	void draw(GLfloat colors[][4], float position[3]);
};

