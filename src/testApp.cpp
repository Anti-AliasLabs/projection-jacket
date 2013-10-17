#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	vector<ofxMacamPs3EyeDeviceInfo*> deviceList = ofxMacamPs3Eye::getDeviceList();
	
	for (int i = 0; i < deviceList.size(); i++) {
		ofxMacamPs3Eye * camera = new ofxMacamPs3Eye();
		camera->setDeviceID(deviceList[i]->id);
		camera->setDesiredFrameRate(180);
		camera->initGrabber(320, 240);
		cameras.push_back(camera);
	}
	
	if(cameras.size() > 0){
		ofSetWindowShape(320 * cameras.size(), 240);
	}
    
    
	individualTextureSyphonServer1.setName("Camera 1");
    tex1.allocate(320, 240, GL_RGBA);
    tex1 = cameras[0]->getTextureReference();
    
    individualTextureSyphonServer2.setName("Camera 2");
    tex2.allocate(320, 240, GL_RGBA);
    tex2 = cameras[1]->getTextureReference();
    
    individualTextureSyphonServer3.setName("Camera 3");
    tex3.allocate(320, 240, GL_RGBA);
    tex3 = cameras[2]->getTextureReference();
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < cameras.size(); i++) {
		cameras[i]->update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < cameras.size(); i++) {
		cameras[i]->draw(i * cameras[i]->getWidth(),0);
		ofDrawBitmapString(ofToString(cameras[i]->getRealFrameRate()), i * cameras[i]->getWidth() + 20, 20);
	}
	
	if(cameras.size() == 0){
		ofDrawBitmapString("No PS3Eye found. :(", 20, 20);
	}
    
    individualTextureSyphonServer1.publishTexture(&tex1);
    individualTextureSyphonServer2.publishTexture(&tex2);
    individualTextureSyphonServer3.publishTexture(&tex3);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
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