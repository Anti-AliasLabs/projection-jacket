#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	camWidth = 320*3;
	camHeight = 240*3;
	
	camera1.setVerbose(true);
	camera1.setDeviceID(6);
	camera1.setDesiredFrameRate(60);
	camera1.initGrabber(camWidth,camHeight);
	
	camera2.setVerbose(true);
	camera2.setDeviceID(7);
	camera2.setDesiredFrameRate(60);
	camera2.initGrabber(camWidth,camHeight);
	
	camera3.setVerbose(true);
	camera3.setDeviceID(8);
	camera3.setDesiredFrameRate(60);
	camera3.initGrabber(camWidth,camHeight);
	
	
	texture1.allocate(camWidth,camHeight, GL_RGB);
	texture2.allocate(camWidth,camHeight, GL_RGB);
	texture3.allocate(camWidth,camHeight, GL_RGB);
	ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void testApp::update(){
	
	ofBackground(100,100,100);
	
	camera1.update();
	camera2.update();
	camera3.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetHexColor(0xFFFFFF);
	
	bw( camera1, texture1 );
	bw( camera2, texture2 );
	bw( camera3, texture3 );
	//vidGrabber.draw(0, 0);
	
	texture1.draw(0, 0);
	texture2.draw(camWidth, 0);
	texture3.draw(camWidth*2, 0);
}


//--------------------------------------------------------------
void testApp::bw(ofVideoGrabber vid, ofTexture vidTex){
	unsigned char * pixels = vid.getPixels();
    
    int nChannels = vid.getPixelsRef().getNumChannels();
	unsigned char * grayArray = new unsigned char[camWidth*camHeight*3];
    
	if (vid.isFrameNew() ) {
		// let's move through the "RGB(A)" char array
		for (int i = 0; i < 3*camWidth*camHeight-nChannels; i+=nChannels){
            unsigned char b = pixels[i];
			unsigned char g = pixels[i+1];
			unsigned char r = pixels[i+2];
			float val = 0.3*(float)r + 0.59*(float)g + 0.11*(float)b;
			//float val = 0.3*(float)r + 0.*(float)g + 0.*(float)b;
			
			grayArray[i] = val;
			grayArray[i + 1] = val;
			grayArray[i + 2] = val;
		}
		vidTex.loadData(grayArray, camWidth,camHeight, GL_RGB);
	}
	delete[] grayArray;
}
//--------------------------------------------------------------


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...
	
	// Video settings no longer works in 10.7
	// You'll need to compile with the 10.6 SDK for this
    // For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
    // http://forum.openframeworks.cc/index.php?topic=10343        
	if (key == 's' || key == 'S'){
		camera1.videoSettings();
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
