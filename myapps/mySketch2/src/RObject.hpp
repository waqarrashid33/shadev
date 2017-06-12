//
//  RObject.hpp
//  mySketch1
//
//  Created by Robert Manzke on 25/12/2016.
//
//

#ifndef RObject_hpp
#define RObject_hpp

#include <stdio.h>
#include "ofMain.h"

class RObject {
public:
    void setup(int, ofVec2f, ofVec2f);
    void update();
    void draw();
    void trig1(int index, float vel);
    void setRandAng(float n, float p);
    
    RObject();
    
    
private:
    ofVec2f pos;
    ofVec2f speed;
    ofVec2f screen;
    float resolution;
    float rad;
    float t, tChange;
    float nVal;
    float nInt;
    float nAmp;
    float blobDecay;
    float speedDecay;
    float speedFactor;
    int index;
    float angN, angP;
    
};

#endif /* RObject_hpp */
