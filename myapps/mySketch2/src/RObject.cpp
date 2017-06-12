//
//  RObject.cpp
//  mySketch1
//
//  Created by Robert Manzke on 25/12/2016.
//
//

#include "RObject.hpp"


void RObject::setup(int index, ofVec2f pos, ofVec2f speed){
    this->pos = pos;
    this->speed = speed;
    this->screen = ofGetWindowSize();
    
}

void RObject::update(){
    pos += speed * speedFactor;
    speed.rotate(ofRandom(angN, angP));
    speedFactor *= speedDecay;
    if(speedFactor<0.1)speedFactor=0.1;
    //cout << speed.x << endl;
    //cout << pos.x << endl;
    if(pos.x>screen.x){
        pos.x = screen.x;
        speed.x *= -1.0;
        speed.rotate(ofRandom(-5.0, 5.0));
    }
    if(pos.x<0){
        pos.x = 0;
        speed.x *= -1.0;
        speed.rotate(ofRandom(-5.0, 5.0));
    }
    if(pos.y>screen.y){
        pos.y = screen.y;
        speed.y *= -1.0;
        speed.rotate(ofRandom(-5.0, 5.0));
    }
    if(pos.y<0){
        pos.y = 0;
        speed.y *= -1.0;
        speed.rotate(ofRandom(-5.0, 5.0));
    }
    
    if(nAmp>1.0){
        nAmp -= blobDecay;
    }else{
        nAmp = 1.0;
    }
    
    
}

void RObject::trig1(int index, float vel){
    nAmp += 1.0 + ofRandom(2);
    if(nAmp > 5)nAmp=5;
    speedFactor = vel / 10.0;
    //speed.rotate(ofRandom(-30.0, 30.0));
    nInt = vel / 85.0;
    this->index = index;
    
    //cout << vel << endl;
}

void RObject::setRandAng(float n, float p){
    angN = n; angP = p;
}

void RObject::draw(){
    ofVec2f vel2 = speed;
    vel2.normalize();

    
    
    ofSetColor(index * 8 + 136, vel2.x * 255.0, vel2.y * 255.0);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofBeginShape();
    for(float a = 0.0; a<=TWO_PI; a+=TWO_PI/resolution){
        float x, y;
        float radBreath = rad + (cos(TWO_PI * t * 0.7)+cos(TWO_PI * t * 0.8)) * 2.0;
        nVal = ofMap(ofNoise(cos(a)*nInt+1, sin(a)*nInt+1, t ), 0.0, 1.0, nAmp, 1.0);
        x = cos(a)*radBreath *nVal;
        y = sin(a)*radBreath *nVal;
        ofVertex(x, y);
    }
    ofEndShape(OF_CLOSE);
    ofPopMatrix();

    t += tChange;
    
}

RObject::RObject(){
    speed = ofVec2f(0.0, 0.0);
    pos = ofVec2f(0.0, 0.0);
    resolution = 150;
    rad = ofRandom(5, 10);
    t = ofRandom(100.0);
    tChange = 0.02;
    nInt = .4;
    nAmp = 1.0;
    blobDecay = 0.1;
    speedDecay = 0.95;
    speedFactor = 1.0;
    index = 0;
    angN = -1.0;
    angP = 1.0;
}
