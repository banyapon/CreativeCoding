#include "ofApp.h"

//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
    for (int i = 0; i < 200; i++) {
        circleClass[i].setup(
            ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), // Random initial positions
            ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5)),  // Increased velocity range
            ofRandom(10, 50)
        );
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i = 0; i < 200; i++) {
        circleClass[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetBackgroundColor(54,2,99);
    for (int i = 0; i < 200; i++) {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255)); // Random color for each circle
        circleClass[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

