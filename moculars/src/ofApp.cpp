// ofApp.cpp
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    float radius = 50; // รัศมีของเกลียว
    float distance = 20; // ระยะห่างระหว่างเกลียว
    int numVertices = 30; // จำนวนจุดยอดบนวงกลม

    for (int i = 0; i < numVertices; i++) {
        float angle = TWO_PI * i / numVertices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // เกลียวที่ 1
        mesh.addVertex(ofVec3f(x, y, -distance / 2));
        // เกลียวที่ 2
        mesh.addVertex(ofVec3f(x, y, distance / 2));

        // เชื่อมต่อจุดยอดภายในเกลียวเดียวกัน
        if (i > 0) {
            mesh.addIndex(i * 2 - 2);
            mesh.addIndex(i * 2);
            mesh.addIndex(i * 2 - 1);
            mesh.addIndex(i * 2 - 1);
            mesh.addIndex(i * 2);
            mesh.addIndex(i * 2 + 1);
        }

        // เชื่อมต่อจุดยอดระหว่างเกลียว (สะพาน)
        mesh.addIndex(i * 2);
        mesh.addIndex(i * 2 + 1);
    }

    // เชื่อมต่อจุดสุดท้ายกับจุดแรก
    mesh.addIndex(numVertices * 2 - 2);
    mesh.addIndex(0);
    mesh.addIndex(numVertices * 2 - 1);
    mesh.addIndex(numVertices * 2 - 1);
    mesh.addIndex(0);
    mesh.addIndex(1);

    cam.setDistance(100);
    lastMouseX = ofGetMouseX();
    lastMouseY = ofGetMouseY();
}

//--------------------------------------------------------------
void ofApp::update() {
    float mouseX = ofGetMouseX();
    float mouseY = ofGetMouseY();
    float diffX = mouseX - lastMouseX;
    float diffY = mouseY - lastMouseY;
    lastMouseX = mouseX;
    lastMouseY = mouseY;

    rotationX += diffY * 0.5;
    rotationY += diffX * 0.5;
    currentColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::draw() {
    //ofBackgroundGradient(ofColor::gray, ofColor::darkGray);
    ofBackground(0,0,0);
    cam.begin();

    ofPushMatrix();
    ofRotateX(rotationX);
    ofRotateY(rotationY);
    ofSetColor(currentColor);
    
    mesh.drawWireframe();

    ofPopMatrix();

    cam.end();
}