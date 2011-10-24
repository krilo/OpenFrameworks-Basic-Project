//
//  HomeView.h
//  BasicProject
//
//  Created by Kristofer Forsell on 2011-10-12.
//  Copyright 2011 Your Majesty BV. All rights reserved.
//

#ifndef LeBookDebug_HomeView_h
#define LeBookDebug_HomeView_h

#include "BaseView.h"

class HomeView : public BaseView {
    
public:
    
	HomeView();
    
    void init();
	void update();
	void draw();
    
    void open();
    void close();
    
};

#endif
