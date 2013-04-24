#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	//ofSetupOpenGL(&window, 320*3*3, 240*3, OF_FULLSCREEN);			// <-------- setup the GL context
	ofSetupOpenGL(&window, 320*3*3, 240*3, OF_WINDOW);	
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
