#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "listening for osc messages on port " << PORT << "\n";
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    oscReceiver.setup(PORT);
    for(int i=0;i<16;i++){
        RObject ro;
        ro.setup(i, ofVec2f(ofRandom(0, width), ofRandom(0, height)), ofVec2f(ofRandom(0.1, 1.0), ofRandom(0.1, 1.0)));
        vec_ro.push_back(ro);
    }
    
    screenBuffer.allocate(width, height, GL_RGBA32F_ARB);
    glow.allocate(width, height);
    glow.setRadius(2.0);
    chroma.allocate(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // parse osc messages
    while(oscReceiver.hasWaitingMessages()){
        ofxOscMessage m;
        oscReceiver.getNextMessage(m);
        
        cout << m.getAddress() << endl;
        for(int i=0; i<m.getNumArgs();i++){
            cout << "Arg " << i << " " << m.getArgAsFloat(i) << endl;
        }
        
        if(m.getAddress() == "/OSC_Send_Group1"){
            if((int)m.getArgAsFloat(3) == 1){
                int index = (int)m.getArgAsFloat(2) - 1;
                float vel = m.getArgAsFloat(0);
                vec_ro[index].trig1(index, vel);
            }
        }
    }
    float nang = cos(TWO_PI*ofGetElapsedTimeMicros()/1000.0 * 0.2)*20.0;
    float pang = sin(TWO_PI*ofGetElapsedTimeMicros()/1000.0 * 0.2)*20.0;
    for(auto &&i : vec_ro){
        //i.setRandAng(nang, pang);
        i.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    screenBuffer.begin();
    ofClear(0);
    for(auto &&i: vec_ro){
        i.draw();
    }
    screenBuffer.end();
    //glow.clear();
    glow << screenBuffer;

    glow.update();
    
    glow.draw(0, 0);
    
    //chroma.clear();
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    chroma << screenBuffer;
    //chroma.draw(0,0);
    screenBuffer.draw(0,0);
    
    
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
