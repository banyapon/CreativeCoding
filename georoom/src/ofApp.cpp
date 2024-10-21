#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(25);
	ofSetWindowTitle("Geometry Room");

	ofBackground(0);
	ofSetLineWidth(3);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSeedRandom(29);
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.72);

	ofColor color;
	for (int i = 0; i < 20; i++) {

		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		color.setHsb(ofMap(i, 0, 20, 0, 255), 255, 200);

		for (int k = 0; k < 50; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200));

			ofSetColor(color, ofMap(k, 0, 50, 0, 255));

			// วาดวงกลมแทนเส้น
			float radius = ofMap(k, 0, 50, 10, 1); // ปรับขนาดวงกลมตามค่า k
			ofDrawCircle(location, radius);
		}
	}

	ofSetColor(255); // เปลี่ยนสีของกล่องเป็นสีขาว
	ofDrawBox(350);

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
