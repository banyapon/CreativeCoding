#pragma once
#include "ofMain.h"
class circle
{
public:
	circle();
	void setup(ofVec2f initialPosition, ofVec2f initialVelocity, float r);
	void update();
	void draw();

	ofVec2f position;
	ofVec2f velocity;
	float radius;
};

