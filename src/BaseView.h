//
//  BaseView.h
//  BasicProject
//
//  Created by Kristofer Forsell on 2011-10-12.
//  Copyright 2011 Your Majesty BV. All rights reserved.
//

#ifndef LeBookDebug_BaseView_h
#define LeBookDebug_BaseView_h

#include "ofMain.h"

class BaseView {
    
public:
    
	BaseView();
    
    virtual void init();
	virtual void update();
	virtual void draw();
    
    virtual void open();
    virtual void close();
    
    bool isOpen;
    
};

#endif
