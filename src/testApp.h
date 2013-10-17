#pragma once

#include "ofMain.h"
#include "ofxMacamPs3Eye.h"
#include "ofxSyphon.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
	vector<ofxMacamPs3Eye*> cameras;
    ofxSyphonServer individualTextureSyphonServer1;
    ofTexture tex1;
    
    ofxSyphonServer individualTextureSyphonServer2;
    ofTexture tex2;
    
    ofxSyphonServer individualTextureSyphonServer3;
    ofTexture tex3;
};
