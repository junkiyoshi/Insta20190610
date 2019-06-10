#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto span = 180;
	auto len = 150;
	auto width = 5;
	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			int n = ofRandom(3, 8);
			for (int i = 0; i < n; i++) {

				auto param_start = (int)(ofRandom(50) + ofGetFrameNum() * ofRandom(0.5, 1)) % 100;
				vector<glm::vec2> vertices, sub_vertices;;
				for (int param = param_start; param <= param_start + width; param++) {

					vertices.push_back(this->make_point(len, param));
				}

				param_start = param_start + 50;
				for (int param = param_start; param <= param_start + width; param++) {

					sub_vertices.push_back(this->make_point(len, param));
				}

				reverse(sub_vertices.begin(), sub_vertices.end());

				auto color_value = ofRandom(39, 239);

				ofFill();
				ofSetColor(color_value);
				ofBeginShape();
				ofVertices(vertices);
				ofVertices(sub_vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(ofMap(color_value, 39, 239, 239, 39));
				ofBeginShape();
				ofVertices(vertices);
				ofVertices(sub_vertices);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}