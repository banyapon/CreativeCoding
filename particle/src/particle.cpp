#include "particle.h"

Particle::Particle(float radius, float angle, float distance) {
    this->radius = radius;
    this->angle = angle;
    this->distance = distance;
    color = ofColor::black; // Set particle color to black
}

void Particle::update() {
    // Calculate the position of the particle based on angle and distance from the center
    pos.x = ofGetWidth() / 2 + cos(angle) * distance;
    pos.y = ofGetHeight() / 2 + sin(angle) * distance;
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    // Add the current position to the trail
    trail.addVertex(pos.x, pos.y);
    if (trail.size() > 50) { // Limit the length of the trail
        trail.getVertices().erase(trail.getVertices().begin());
    }
}

void Particle::draw() {
    ofSetColor(color);

    ofDrawCircle(pos, radius);

    // Draw the trail
    ofSetColor(ofRandom(0, 255), 80); // Set color and transparency of the trail
    ofSetLineWidth(5);
    trail.draw();
}