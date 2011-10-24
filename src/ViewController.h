//
//  ViewController.h
//  BasicProject
//
//  Created by Kristofer Forsell on 2011-10-12.
//  Copyright 2011 Your Majesty BV. All rights reserved.
//

#ifndef LeBookDebug_ViewController_h
#define LeBookDebug_ViewController_h

#include "ofMain.h"
#include "BaseView.h"
#include "HomeView.h"

class ViewController {
    
public:
    
	static ViewController* Instance();
    
    static void init();
	static void update();
	static void draw();
    static int getCurrentView();
    static void switchView(int newView);

protected:
    
    ViewController(){};
    
private:
    
    static ViewController* __instance;
    int currentView;
    vector<BaseView*> viewsVector;

    
};

#endif
