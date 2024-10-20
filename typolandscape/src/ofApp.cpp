#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(20);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);


	this->font.loadFont("fonts/upheavtt.ttf", 30, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 0; x < ofGetWidth(); x += 30) {

		for (int y = 30; y <= ofGetHeight(); y += 30) {

			char noise_value = ofMap(ofNoise(x * 0.008, y * 0.008, ofGetFrameNum() * 0.003), 0, 1, 45, 110);
			if (noise_value >= '0' && noise_value <= 'Z') {
				ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
				this->font.drawString({ noise_value }, x, y);
			}
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
