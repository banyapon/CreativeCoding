#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofEasyCam cam;

		vector<glm::vec3> location_list;
		vector<ofColor> base_color_list;

		glm::vec3 noise_seed;
		vector<vector<glm::vec3>> log_list;
		vector<ofColor> color_list;
		vector<float> life_list;
		vector<glm::vec3> param_list;

		ofMesh face, frame;
};
