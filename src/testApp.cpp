#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	vector<ofxMacamPs3EyeDeviceInfo*> deviceList = ofxMacamPs3Eye::getDeviceList();
	
	for (int i = 0; i < deviceList.size(); i++) {
		// set up camera
        ofxMacamPs3Eye * camera = new ofxMacamPs3Eye();
		camera->setDeviceID(deviceList[i]->id);
		camera->setDesiredFrameRate(180);
		camera->initGrabber(320, 240);
		cameras.push_back(camera);
       
        // set up texture for Syphon server
        ofTexture* bwTex = new ofTexture();
        bwTex->allocate(320, 240, GL_RGB);
        bwTextures.push_back(bwTex);
        
        // set up spyhon server
        /*ofxSyphonServer* sServer = new ofxSyphonServer();
        sServer->setName("Camera");
        syphonServers.push_back(sServer);
         */
	}
    //combinedTexture = new ofTexture();
    //combinedTexture->allocate(320*cameras.size(), 240, GL_RGB);
    
    syphonServer.setName("Cameras");
	
	if(cameras.size() > 0){
		ofSetWindowShape(320 * cameras.size(), 240);
	}
}

//--------------------------------------------------------------
void testApp::update(){
    int nChannels = 3;
    int camWidth = 320;
    int camHeight = 240;
    
	for (int i = 0; i < cameras.size(); i++) {
		cameras[i]->update();
	
    
        // create array for holding processed image
        unsigned char * grayArray = new unsigned char[320*camHeight*nChannels];
    
    
        if( cameras[i]->isFrameNew() ){
            unsigned char* pixels = cameras[i]->getPixels();
        
            // let's move through the "RGB" char array
            for (int j = 0; j < 3*camWidth*camHeight-nChannels; j+=nChannels){
                unsigned char b = pixels[j];
                unsigned char g = pixels[j+1];
                unsigned char r = pixels[j+2];
                float val = 0.3*(float)r + 0.59*(float)g + 0.11*(float)b;
                //float val = 0.3*(float)r + 0.*(float)g + 0.*(float)b;
            
                grayArray[j] = val;
                grayArray[j + 1] = val;
                grayArray[j + 2] = val;
            }
            bwTextures[i]->loadData(grayArray, camWidth,camHeight, GL_RGB);
        }
        delete[] grayArray;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
	for (int i = 0; i < cameras.size(); i++) {
		//cameras[i]->draw(i * cameras[i]->getWidth(),0);
		//ofDrawBitmapString(ofToString(cameras[i]->getRealFrameRate()), i * cameras[i]->getWidth() + 20, 20);
        
        bwTextures[i]->draw(i * bwTextures[i]->getWidth(), 0);
        
        //syphonServers[i]->publishTexture(bwTextures[i]);
	}
    //combinedTexture->loadScreenData(0, 240, 320 * cameras.size(), 240);
    //syphonServer.publishTexture(combinedTexture);
	syphonServer.publishScreen();
    
	if(cameras.size() == 0){
		ofDrawBitmapString("No PS3Eye found. :(", 20, 20);
	}
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