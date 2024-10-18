#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pos.x = ofRandom(0, ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(5);
    indexColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    pos += velocity;
    if ((pos.x > ofGetWidth()) || (pos.x < 0)) {
        velocity.x *= -1;
    }
    if ((pos.y > ofGetHeight()) || (pos.y < 0)) {
        velocity.y *= -1;
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(indexColor);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            ofDrawCircle(i * 50, j * 50, 25);
            ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        }
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
