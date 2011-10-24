#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(1, 1, 1);
	ofSetFrameRate(60);
    
    // Setup our ViewController
    ViewController::init();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Update Views
    ViewController::update();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Draw Views
    ViewController::draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key){
		case '0':
			ViewController::switchView(0);
			break;
        case '1':
			ViewController::switchView(1);
			break;
        case '2':
			ViewController::switchView(2);
			break;
        case '3':
			ViewController::switchView(3);
			break;
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