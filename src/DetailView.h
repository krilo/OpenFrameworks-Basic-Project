//
//  DetailView.h
//  LeBookDebug
//
//  Created by Kristofer Forsell on 2011-10-14.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LeBookDebug_DetailView_h
#define LeBookDebug_DetailView_h

#include "BaseView.h"
#include "DetailViewButton.h"

class DetailView : public BaseView {
    
public:
    
	DetailView(ofImage _textImg, ofImage _screenImage);
    
    void init();
	void update(ofPoint _handPos, bool _handClosed);
	void draw();
    void hitTest(const ofPoint& pt);
    void grabTest(bool grab);
    void onComplete(float args);
    
    void open();
    void close();

    ofPoint handPos;
    ofPoint center;

private:
    
    ofImage textImg;
    ofImage screenImg;
    
    float contentWidth;
    float contentHeight;
    ofPoint pos;
    ofPoint target;
    ofPoint leftBtnPos;
    ofPoint rightBtnPos;
    float delay;
    float leftPadding;
    
    DetailViewButton* leftProjectButton;
    DetailViewButton* rightProjectButton;
    
    bool handClosed;
    bool isOver;
    bool isDragging;
    
    float startX;
    float startPosX;

    
};

#endif
