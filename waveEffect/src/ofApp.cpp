#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Dotted Video Effect");
    ofSetFrameRate(80);
    ofBackground(0);

    // Load video from bin/data/video.mp4
    video.load("video.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();

    threshold1 = 95;
    threshold2 = 120;
}

//--------------------------------------------------------------
void ofApp::update() {
    video.update();

    if (video.isFrameNew()) {
        videoPixels = video.getPixels();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (!video.isFrameNew()) return;

    int videoWidth = video.getWidth();
    int videoHeight = video.getHeight();

    // Get current window size
    int windowWidth = ofGetWidth();
    int windowHeight = ofGetHeight();

    // Calculate video aspect ratio
    float videoAspect = (float)videoWidth / videoHeight;
    float windowAspect = (float)windowWidth / windowHeight;

    // Calculate the draw size while maintaining aspect ratio
    float drawWidth, drawHeight;
    if (windowAspect > videoAspect) {
        drawHeight = windowHeight;
        drawWidth = drawHeight * videoAspect;
    }
    else {
        drawWidth = windowWidth;
        drawHeight = drawWidth / videoAspect;
    }

    // Draw the video centered on the screen while maintaining aspect ratio
    float x = (windowWidth - drawWidth) / 2;
    float y = (windowHeight - drawHeight) / 2;
    video.draw(x, y, drawWidth, drawHeight);

    // Loop through each pixel in the frame
    for (int y = 0; y < videoHeight; y += dotSize) {
        for (int x = 0; x < videoWidth; x += dotSize) {
            // Get pixel brightness
            ofColor color = videoPixels.getColor(x, y);
            int brightness = color.getBrightness();

            // Convert brightness to white, gray, or black based on thresholds
            ofColor newColor;
            if (brightness < threshold1) {
                newColor = ofColor(0); // Black
            }
            else if (brightness < threshold2) {
                newColor = ofColor::fromHex(0x54a1ff); // Specified color
            }
            else {
                newColor = ofColor(255); // White
            }

            // Calculate adjusted positions based on window scaling
            float scaledX = x * (drawWidth / videoWidth) + x;
            float scaledY = y * (drawHeight / videoHeight) + y;

            // Draw a circle at the adjusted position
            ofSetColor(newColor);
            ofDrawCircle(scaledX, scaledY, dotSize / 1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
