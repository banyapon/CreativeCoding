#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0); // Set background color to black

    // Create particles
    float numParticles = 500; // Number of particles
    float maxRadius = 15; // Maximum radius of particles
    float minDistance = 1; // Minimum distance from the center
    float maxDistance = 2000; // Maximum distance from the center

    for (int i = 0; i < numParticles; i++) {
        float angle = ofMap(i, 0, numParticles, 0, TWO_PI * 10); // Adjust the number of rotations here
        float distance = ofMap(i, 0, numParticles, minDistance, maxDistance);
        float radius = ofRandom(2, maxRadius); // Randomize particle size
        particles.push_back(Particle(radius, angle, distance));
    }
}

void ofApp::update() {
    ofSetFrameRate(60);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();

        // Increase distance from the center to expand
        particles[i].distance += 0.1; // Adjust the expansion speed here

        // Rotate particle
        particles[i].angle += 0.01; // Adjust the rotation speed here

        // Randomize minDistance, maxDistance
        if (ofRandom(1) < 0.01) { // Adjust the randomization frequency here
            float minDistance = ofRandom(50, 150); // Adjust the range of minDistance here
            float maxDistance = ofRandom(200, 400); // Adjust the range of maxDistance here
            particles[i].distance = ofMap(i, 0, particles.size(), minDistance, maxDistance);
        }
    }
}

void ofApp::draw() {
    // No need to draw trail here again

    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}