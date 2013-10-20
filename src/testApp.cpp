#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ps3eye.initGrabber(320, 240);
	thres.allocate(320, 240, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void testApp::update(){
	ps3eye.update();
	if(ps3eye.isFrameNew()){

		thres.setFromPixels(ps3eye.getPixels(), 320, 240, OF_IMAGE_COLOR);

		ofxCv::convertColor(ps3eye, thres, CV_RGB2GRAY);
		float thresholdValue = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
		ofxCv::threshold(thres, thresholdValue);
		thres.update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ps3eye.draw(0, 0);
	thres.draw(320, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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