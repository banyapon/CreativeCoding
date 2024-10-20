#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(25);
	ofSetWindowTitle("Shape of Things");

	ofBackground(0);
	ofSetLineWidth(0.4);
	ofEnableDepthTest();

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(15);
	ofSeedRandom(95);

	this->face.clear();
	this->frame.clear();

	auto noise_seed = glm::vec3(ofRandom(500), ofRandom(500), ofRandom(500));
	ofColor color;
	this->setCenterPoint(this->face, this->frame, glm::vec3(), 0, 1, 10, 0, 100, noise_seed, ofColor(255));
	for (auto radius = 10; radius < 1000; radius += 5) {

		for (auto deg = 0; deg < 100; deg += 10) {

			color.setHsb(ofMap(deg, 0, 360, 0, 255), 200, 255);
			this->setCenterPoint(this->face, this->frame, glm::vec3(), radius, 1, 10, deg, deg + 2, noise_seed, color);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->camera.begin();

	ofSetColor(0);
	this->face.draw();
	this->frame.drawWireframe();
	this->camera.end();
}

//--------------------------------------------------------------
void ofApp::setCenterPoint(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float radius, float width, float height, int deg_start, int deg_end, glm::vec3 noise_seed, ofColor color)
{
	auto index = frame_target.getNumVertices();

	auto noise_value = glm::vec3(
		ofNoise(noise_seed.x - radius * 0.001 + ofGetFrameNum() * 0.008),
		ofNoise(noise_seed.y - radius * 0.001 + ofGetFrameNum() * 0.008),
		ofNoise(noise_seed.z - radius * 0.001 + ofGetFrameNum() * 0.008));

	auto angle_z = ofMap(noise_value.z, 0, 1, -PI * 2, PI * 2);
	auto rotation_z = glm::rotate(glm::mat4(), angle_z, glm::vec3(0, 0, 1));

	int deg_span = 3;
	for (int deg = deg_start; deg < deg_end; deg += deg_span) {

		auto face_index = face_target.getNumVertices();

		vector<glm::vec3> vertices;
		vertices.push_back(glm::vec3((radius + width * 0.2) * cos(deg * DEG_TO_RAD), (radius + width * 0.2) * sin(deg * DEG_TO_RAD), height * -0.2));
		vertices.push_back(glm::vec3((radius + width * 0.2) * cos((deg + deg_span) * DEG_TO_RAD), (radius + width * 0.2) * sin((deg + deg_span) * DEG_TO_RAD), height * -0.2));
		vertices.push_back(glm::vec3((radius + width * 0.2) * cos((deg + deg_span) * DEG_TO_RAD), (radius + width * 0.2) * sin((deg + deg_span) * DEG_TO_RAD), height * 0.2));
		vertices.push_back(glm::vec3((radius + width * 0.2) * cos(deg * DEG_TO_RAD), (radius + width * 0.2) * sin(deg * DEG_TO_RAD), height * 0.2));

		vertices.push_back(glm::vec3((radius - width * 0.2) * cos(deg * DEG_TO_RAD), (radius - width * 0.2) * sin(deg * DEG_TO_RAD), height * -0.2));
		vertices.push_back(glm::vec3((radius - width * 0.2) * cos((deg + deg_span) * DEG_TO_RAD), (radius - width * 0.2) * sin((deg + deg_span) * DEG_TO_RAD), height * -0.2));
		vertices.push_back(glm::vec3((radius - width * 0.2) * cos((deg + deg_span) * DEG_TO_RAD), (radius - width * 0.2) * sin((deg + deg_span) * DEG_TO_RAD), height * 0.2));
		vertices.push_back(glm::vec3((radius - width * 0.2) * cos(deg * DEG_TO_RAD), (radius - width * 0.2) * sin(deg * DEG_TO_RAD), height * 0.2));

		for (auto& vertex : vertices) {

			vertex = location + glm::vec4(vertex, 0) * rotation_z;
			face_target.addColor(color);
			frame_target.addColor(color);
		}

		face_target.addVertices(vertices);

		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 2);
		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 3);

		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 6);
		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 7);

		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5);
		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 1);

		face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 7); face_target.addIndex(face_index + 6);
		face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 2);

		auto frame_index = frame_target.getNumVertices();

		frame_target.addVertices(vertices);

		frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 1);
		frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 3);
		frame_target.addIndex(frame_index + 4); frame_target.addIndex(frame_index + 5);
		frame_target.addIndex(frame_index + 6); frame_target.addIndex(frame_index + 7);
	}

	if (radius != 0) {

		face_target.addIndex(index + 0); face_target.addIndex(index + 3); face_target.addIndex(index + 7);
		face_target.addIndex(index + 0); face_target.addIndex(index + 7); face_target.addIndex(index + 4);

		frame_target.addIndex(index + 0); frame_target.addIndex(index + 3);
		frame_target.addIndex(index + 0); frame_target.addIndex(index + 4);
		frame_target.addIndex(index + 7); frame_target.addIndex(index + 3);
		frame_target.addIndex(index + 7); frame_target.addIndex(index + 4);

		index = frame_target.getNumVertices() - 8;

		face_target.addIndex(index + 1); face_target.addIndex(index + 2); face_target.addIndex(index + 6);
		face_target.addIndex(index + 1); face_target.addIndex(index + 6); face_target.addIndex(index + 5);

		frame_target.addIndex(index + 1); frame_target.addIndex(index + 2);
		frame_target.addIndex(index + 1); frame_target.addIndex(index + 5);
		frame_target.addIndex(index + 6); frame_target.addIndex(index + 2);
		frame_target.addIndex(index + 6); frame_target.addIndex(index + 5);
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
