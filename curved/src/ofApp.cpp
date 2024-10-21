#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(10);
	ofSetWindowTitle("Curved");

	ofBackground(0);
	ofEnableDepthTest();
	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(59);
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	ofColor color;
	for (int i = 0; i < 32; i++) {

		auto hue = (int)ofRandom(200, 280) % 255;
		color.setHsb(hue, 150, 200);
		ofSetColor(color);

		ofPushMatrix();
		ofRotateZ(ofRandom(-5, 5));
		ofRotateY(ofRandom(-5, 5));
		ofRotateX(ofRandom(-5, 5));

		auto radius = ofRandom(150, 850);
		auto deg_start = ofRandom(360, 720) + ofGetFrameNum() * (int)ofRandom(2, 6);
		auto sphere_location = glm::vec3(radius * cos((deg_start - 5) * DEG_TO_RAD), radius * sin((deg_start - 5) * DEG_TO_RAD), 0);

		for (int deg = deg_start; deg < deg_start + 350; deg++) {

			auto location_1 = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
			auto location_2 = glm::vec3(radius * cos((deg + 1) * DEG_TO_RAD), radius * sin((deg + 1) * DEG_TO_RAD), 0);
			auto distance = glm::distance(sphere_location, location_1);

			ofSetLineWidth(ofMap(distance, 0, radius * 2, 3, 0));
			ofSetColor(ofColor(color, ofMap(distance, 0, radius * 2, 255, 0)));
			ofDrawLine(location_1, location_2);
		}

		ofFill();
		ofSetColor(color);
		ofDrawSphere(sphere_location, ofMap(radius, 150, 850, 2, 5));

		ofPopMatrix();
	}

	this->cam.end();
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
