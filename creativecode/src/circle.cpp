#include "circle.h"

circle :: circle() {

}

void circle::setup(ofVec2f initialPosition, ofVec2f initialVelocity, float r) {
	position = initialPosition;
	velocity = initialVelocity;
	radius = r;
}

void circle::update() {
	position += velocity;
	if ((position.x > ofGetWidth()) || (position.x < 0)) {
		velocity.x *= -1;
	}
	if ((position.y > ofGetHeight()) || (position.y < 0)) {
		velocity.y *= -1;
	}
}

void circle::draw() {
	ofDrawCircle(position.x, position.y, radius);
}