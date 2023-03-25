#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {

  sc_value = 0.0;
  receiver.setup(PORT);
  ::ofSetWindowPosition(0, 0);
  ::ofSetWindowShape(400, 400);
  shader.load("shader/shader");
  shader_w = 300;
  shader_h = 300;
}

//--------------------------------------------------------------
void ofApp::update() {
  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;
    receiver.getNextMessage(m);
    //   if (m.getAddress() == "/sc/test") {
    for (int i = 0; i < m.getNumArgs(); i++) {
      std::cout << m.getArgAsFloat(i) << std::endl;
      sc_value = m.getArgAsFloat(i);
    }

    // }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  shader.begin();
  shader.setUniform1f("u_tim", ofGetElapsedTimef());
  shader.setUniform2f("u_mouse", mouseX, mouseY);
  shader.setUniform2f("u_resolution", shader_w, shader_h);

  shader.setUniform1f("sc_msg", sc_value);
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
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
