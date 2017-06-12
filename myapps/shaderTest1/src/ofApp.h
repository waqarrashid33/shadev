#pragma once

#include "ofMain.h"
#include "ofxMaze.h"
#include "ofxNoise2.h"
#include "ofxDisplacePixels2.h"
#include "ofxGaussianBlur.h"

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
private:
    ofxMaze maze;
    ofxNoise2 noise;
    ofxDisplacePixels2 disp;
    ofImage img;
    ofxGaussianBlur gBlur;
    ofFbo fbo;
};
