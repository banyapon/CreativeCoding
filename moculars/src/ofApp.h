// ofApp.h
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    ofMesh mesh;
    ofEasyCam cam;
    float lastMouseX, lastMouseY;
    float rotationX = 0;
    float rotationY = 0;
    ofColor currentColor;
};