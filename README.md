# CreativeCoding

openFrameworks on Visual Studio 2022: A Computer Graphics Playground
Introduction

This repository provides a foundational setup for using openFrameworks with Visual Studio 2022. 
It's designed to serve as a starting point for those keen on exploring interactive graphics and computer vision.

Why openFrameworks for Computer Graphics?
- **Flexibility:** Customize and extend to fit your specific needs.
- **Community:** Benefit from a large and active community of developers.
- **Real-time performance:** Ideal for interactive applications.
- **Cross-platform:** Develop once, deploy on various platforms.
- **Comprehensive:** Handles graphics, sound, input, and more.

## Getting Started
**Install Prerequisites:**
openFrameworks: Download and install the latest version from https://openframeworks.cc/download/.
Visual Studio 2022: Download and install the Community edition or higher.
- Create a new openFrameworks project:
- Launch Visual Studio 2022.
- Create a new C++ project and select the openFrameworks template.
- Configure your project settings according to the openFrameworks documentation.

## Project Structure
1 src: Contains the main source code for your application.
2 bin: Stores compiled executables.
3 data: Holds assets like images, fonts, and sounds.
4 addons: Custom addons or third-party libraries.

## Basic Example
**main.cpp**: The entry point of your application.
ofApp.h: Declares the class that handles your application's logic.
ofApp.cpp: Implements the methods of the ofApp class.
C++
```
// ofApp.h
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
};
```
Use code with caution.

C++
```
// ofApp.cpp
void ofApp::setup(){
    ofBackground(255);
}

void ofApp::update(){
}

void ofApp::draw(){
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 50);
}
```
Use code with caution.

## Computer Graphics Concepts
### Use openFrameworks to explore:
1 2D and 3D graphics
2 Transformations (translation, rotation, scale)
3 Cameras and projections
4 Lighting and shading
5 Textures and materials
6 Animation and interactions
And more...

**Additional Resources**
openFrameworks Website: https://openframeworks.cc/
Visual Studio Documentation: https://learn.microsoft.com/en-us/visualstudio/windows/?view=vs-2022
Online Tutorials and Forums: Search for tutorials and join communities to learn from others.

**License**
MIT LICENSE

Remember to replace the placeholder content with your specific project details.

For more advanced topics, consider exploring:
1 **Kinect integration**: For real-time motion capture.
2 **OpenGL shaders**: For custom visual effects.
3 **Sound synthesis**: Create interactive audio experiences.
4 **Networking**: Develop multiplayer games or distributed applications.
Happy coding!

**Asst. Prof. Banyapon Poolsawas**
**College of Creative Design and Entertainment Technology**, Dhurakij Pundit University, Thailand.
 
