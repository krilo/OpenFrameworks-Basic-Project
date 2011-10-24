//
//  ViewController.cpp
//  BasicProject
//
//  Created by Kristofer Forsell on 2011-10-12.
//  Copyright 2011 Your Majesty BV. All rights reserved.
//

#include "ViewController.h"

ViewController* ViewController::__instance = 0;

ViewController* ViewController::Instance() {
	if (__instance == 0) {
		__instance = new ViewController();
	}
	return __instance;
}

//--------------------------------------------------------------
void ViewController::init() {
    
    Instance();
    
    // Create and Push Views
    __instance->viewsVector.push_back( new HomeView() );
    
    for (int i=0; i< __instance->viewsVector.size(); i++) {
        __instance->viewsVector[i]->init();
    }
    
    __instance->currentView = -1;
    __instance->switchView(0);
}

//--------------------------------------------------------------
void ViewController::update() {
    
    
    for (int i=0; i< __instance->viewsVector.size(); i++) {
        __instance->viewsVector[i]->update();
    }
    
    
}

//--------------------------------------------------------------
void ViewController::draw() {
    
    for (int i=0; i<__instance->viewsVector.size(); i++) {
        __instance->viewsVector[i]->draw();
    }
    
}

//--------------------------------------------------------------
int ViewController::getCurrentView() {
    
    return __instance->currentView;
    
}

//--------------------------------------------------------------
void ViewController::switchView(int newView) {
    
    if (__instance->currentView != -1) {
        __instance->viewsVector[__instance->currentView]->close();
        ofLog(OF_LOG_VERBOSE, ofToString("closeOldView: "));
        ofLog(OF_LOG_VERBOSE, ofToString(__instance->currentView));
    }
    
    __instance->viewsVector[newView]->open();
    __instance->currentView = newView;
    
    ofLog(OF_LOG_VERBOSE, ofToString("switchView: "));
    ofLog(OF_LOG_VERBOSE, ofToString(newView));
    
}