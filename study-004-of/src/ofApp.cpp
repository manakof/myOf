#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

  sc_value = 0.0;
  sc_sin = 0.0;
  sc_saw = 0.0;
  sc_noise = 0.0;
  receiver.setup(PORT);
  ::ofSetWindowPosition(0, 0);
  ::ofSetWindowShape(300, 300);
  shader.load("shader/shader");
  shader_w = ofGetWidth();
  shader_h = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update() {
  shader.load("shader/shader");

  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;
    receiver.getNextMessage(m);
    if (m.getAddress() == "/sc/my_sin") {
      for (int i = 0; i < m.getNumArgs(); i++) {
        sc_sin = m.getArgAsFloat(i);
        std::cout << "my_sin : " << m.getArgAsFloat(i) << std::endl;
      }
    } else if (m.getAddress() == "/sc/my_saw") {
      for (int i = 0; i < m.getNumArgs(); i++) {
        sc_saw = m.getArgAsFloat(i);
        std::cout << "my_saw : " << m.getArgAsFloat(i) << std::endl;
      }
    } else if (m.getAddress() == "/sc/my_noise") {
      for (int i = 0; i < m.getNumArgs(); i++) {
        sc_noise = m.getArgAsFloat(i);
        std::cout << "my_noise : " << m.getArgAsFloat(i) << std::endl;
      }
    }
  }
}
//--------------------------------------------------------------
void ofApp::draw() {
  shader.begin();
  shader.setUniform1f("u_tim", ofGetElapsedTimef());
  shader.setUniform2f("u_mouse", mouseX, mouseY);
  shader.setUniform2f("u_resolution", shader_w, shader_h);
  shader.setUniform1f("sc_sin", sc_sin);
  shader.setUniform1f("sc_saw", sc_saw);
  shader.setUniform1f("sc_noise", sc_noise);
  ofDrawRectangle(0, 0, shader_w, shader_h);
  shader.end();
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
void ofApp::windowResized(int w, int h) {
  shader_w = ofGetWidth();
  shader_h = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
