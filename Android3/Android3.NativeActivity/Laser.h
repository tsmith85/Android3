#pragma once
#include <iostream>
#include "engine.h"
using namespace std;

class Laser
{
private:
	float position_x;
	float position_y;
public:
	Laser();
	~Laser();

	float getPosition_x(float x);
	float getPosition_y(float y);
	void moveLaserEvent(float x, float y);
	void draw(float position[]);
};

