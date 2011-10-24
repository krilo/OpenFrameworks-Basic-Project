//
//  DetailView.cpp
//  LeBookDebug
//
//  Created by Kristofer Forsell on 2011-10-14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "DetailView.h"

//--------------------------------------------------------------
DetailView::DetailView(ofImage _textImg, ofImage _screenImage) {
    
    isOpen = false;
    textImg = _textImg;
    screenImg = _screenImage;
    
}

//--------------------------------------------------------------
void DetailView::init() {
    
    contentWidth = textImg.width + 5 + screenImg.width;
    contentHeight = textImg.height;
    
    //pos.x = floor((ofGetWindowWidth() -textImg.width)/2);
    pos.x = floor(ofClamp((ofGetWindowWidth() -textImg.width)/2, (-screenImg.width + 1330 - textImg.width - leftPadding), leftPadding + 28));
    pos.y = floor((ofGetWindowHeight() - contentHeight)/2);
    delay = 0.5;
    target = pos;
    
    ofImage leftProjectButtonImageOut;
    leftProjectButtonImageOut.loadImage("nav_assets/nav_left_arrow.png");
    ofImage leftProjectButtonImageOver;
    leftProjectButtonImageOver.loadImage("nav_assets/nav_left_work.png");
    leftProjectButton = new DetailViewButton(leftProjectButtonImageOut, leftProjectButtonImageOver);
    leftProjectButton->init();
    
    ofImage rightProjectButtonImageOut;
    rightProjectButtonImageOut.loadImage("nav_assets/nav_right_arrow.png");
    ofImage rightProjectButtonImageOver;
    rightProjectButtonImageOver.loadImage("nav_assets/nav_right_work.png");
    rightProjectButton = new DetailViewButton(rightProjectButtonImageOut, rightProjectButtonImageOver);
    rightProjectButton->init();
    rightProjectButton->rightAlign();
    
}

//--------------------------------------------------------------
void DetailView::update(ofPoint _handPos, bool _handClosed) {
    if (isOpen == true) {
        ofLog(OF_LOG_VERBOSE, ofToString(_handClosed));
        handPos = _handPos;
        handClosed = _handClosed;
        
        leftPadding = floor((ofGetWindowWidth() -textImg.width)/2) +28 ;
        contentWidth = textImg.width + 5 + screenImg.width;
        
        if((handPos.x > pos.x) && (handPos.x < pos.x + contentWidth) && (handPos.y > pos.y) && (handPos.y < pos.y + contentHeight)){  
            isOver = true;
        }else {
            isOver = false;
        }
        
        if (handPos.x < 250){
            target.x = pos.x + 100;
        }else if(handPos.x > (ofGetWindowWidth()-250)){
            target.x = pos.x - 100;
        }
        
        pos.x = floor(ofClamp(pos.x + (target.x - pos.x) * delay, (-screenImg.width + 1330 - textImg.width - leftPadding), leftPadding + 28));
        
        leftBtnPos.x = pos.x - leftPadding;
        leftBtnPos.y = ofGetWindowHeight()/2;
        leftProjectButton->update(leftBtnPos, handPos, handClosed);
        
        //rightBtnPos.x = pos.x + screenImg.width + textImg.width -184 + leftPadding;
        //rightBtnPos.y = ofGetWindowHeight()/2;
        //rightProjectButton->update(rightBtnPos, handPos, handClosed);
    
        
    }
}

//--------------------------------------------------------------
void DetailView::draw() {
    if (isOpen == true) {
        
        // Draw Header
        ofSetHexColor(0xFFFFFF);
        proximaNova.drawString("DetailView", 20, 50);
        
        ofEnableAlphaBlending();        
        textImg.draw(pos.x,pos.y);
        screenImg.draw(textImg.width + pos.x + 5, pos.y - 20);
        
        leftProjectButton->draw();
        //rightProjectButton->draw();
        
        ofDisableAlphaBlending();
        
    }
}

//--------------------------------------------------------------
void DetailView::hitTest(const ofPoint& pt) {
    if (isOpen == true) {
        
        // Store pos
        handPos = pt;
        
    }
}


//--------------------------------------------------------------
void DetailView::grabTest(bool grab) {
    if (isOpen == true) {
        handClosed = grab;
    }
}

//--------------------------------------------------------------
void DetailView::onComplete(float args) {
    Tweenzor::removeAllTweens();
}

//--------------------------------------------------------------
void DetailView::open() {
    isOpen = true;
    leftProjectButton->openButton();
    //rightProjectButton->openButton();
}

//--------------------------------------------------------------
void DetailView::close() {
    isOpen = false;
    
    pos.x = floor((ofGetWindowWidth() -textImg.width)/2);
    pos.y = floor((ofGetWindowHeight() - contentHeight)/2);
    target = pos;

}
