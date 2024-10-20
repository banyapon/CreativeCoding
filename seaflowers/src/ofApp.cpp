#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0); // กำหนดพื้นหลังสีดำ

    // สร้าง Particles
    for (int i = 0; i < 300; i++) {
        glm::vec2 pos = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        glm::vec2 vel = glm::vec2(ofRandom(-5, 5), ofRandom(-5, 5));
        float rad = ofRandom(5, 20);
        particles.push_back(Seamonster(pos, vel, rad));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetFrameRate(60);
    for (auto& p : particles) {
        p.update();
        for (auto& other : particles) {
            if (&p != &other) { // ป้องกันการตรวจสอบการชนกับตัวเอง
                p.checkCollision(other);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color1(6, 6, 6); // สี 060606
    ofColor color2(0, 30, 104); // สี 001e68
    ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
    for (auto& p : particles) {
        p.draw();
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
