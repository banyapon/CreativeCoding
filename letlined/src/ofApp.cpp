#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("LotedLined");

	ofBackground(29);
	ofSetLineWidth(10);
	ofNoFill();
	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(49);
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	ofColor color;
	for (int i = 0; i < 4000; i++) {

		color.setHsb(ofMap(i, 0, 4000, 0, 255), ofRandom(100, 255), ofRandom(100, 255));
		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));

		for (int k = 0; k < 30; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.05), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.0005), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k) * 0.05), 0, 1, -1000, 1000));
			auto next = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + 1) * 0.05), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + 1) * 0.0005), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k + 1) * 0.05), 0, 1, -1000, 1000));

			if (location.x > 800) { location.x = 800; }
			if (location.x < -800) { location.x = -800; }
			if (next.x > 800) { next.x = 800; }
			if (next.x < -800) { next.x = -800; }

			if (location.y > 800) { location.y = 800; }
			if (location.y < -800) { location.y = -800; }
			if (next.y > 800) { next.y = 800; }
			if (next.y < -800) { next.y = -800; }

			if (location.z > 800) { location.z = 800; }
			if (location.z < -800) { location.z = -800; }
			if (next.z > 800) { next.z = 800; }
			if (next.z < -800) { next.z = -800; }

			if (location.y > 0 && location.y < 1000) { location.y = 1000; }
			if (location.y < 0 && location.y > -1000) { location.y = -1000; }
			if (next.y > 0 && next.y < 1000) { next.y = 1000; }
			if (next.y < 0 && next.y > -1000) { next.y = -1000; }

			auto alpha = ofMap(k, 0, 30, 0, 255);
			ofSetColor(color, alpha);
			ofDrawLine(location, next);
		}


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
