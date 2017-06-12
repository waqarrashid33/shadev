#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    maze.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    noise.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    disp.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    gBlur.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    img.load("maze.jpg");
    img.resize(ofGetWindowWidth(), ofGetWindowHeight());

    maze.setColor(0.0, 0.0, 1.0);
    gBlur.setRadius(5.0);
    gBlur.setPasses(2);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    maze.update();
    noise.update();
    //disp.update();
    fbo.begin();
    ofBackground(255, 0, 255);
    //maze.draw();
    disp.setTexture(noise.getTexture(), 1);
    disp.setColor(1.0, 1.0, 1.0);
    disp.setXDisplacement(2.0);
    disp.setYDisplacement(2.0);
    disp << maze;
    disp.draw(0,0);
    
    disp.setTexture(noise.getTexture(), 1);
    disp.setColor(0.0, 0.0, 0.0);
    disp.setXDisplacement(-2.0);
    disp.setYDisplacement(-2.0);
    disp << maze;
    disp.draw(0,0);
    
    fbo.end();
    gBlur << fbo.getTexture();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //maze.draw(0, 0);
    //noise.draw(0,0);
    //img.draw(0, 0);

    gBlur.draw(0,0);
    maze.draw(0,0);
    
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
