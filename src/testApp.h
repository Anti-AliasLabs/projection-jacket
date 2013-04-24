#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
	
		void bw(ofVideoGrabber vid, ofTexture vidTex);
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		
		ofVideoGrabber 		camera1;
		ofTexture			texture1;
	
		ofVideoGrabber 		camera2;
		ofTexture			texture2;
	
		ofVideoGrabber 		camera3;
		ofTexture			texture3;
	
	
		int 				camWidth;
		int 				camHeight;
};
