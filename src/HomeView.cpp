//
//  HomeView.cpp
//  BasicProject
//
//  Created by Kristofer Forsell on 2011-10-12.
//  Copyright 2011 Your Majesty BV. All rights reserved.
//

#include "HomeView.h"

//--------------------------------------------------------------
HomeView::HomeView() {
    isOpen = false;
}

//--------------------------------------------------------------
void HomeView::init() {
       
}

//--------------------------------------------------------------
void HomeView::update() {
    if (isOpen == true) {
        
    }
}

//--------------------------------------------------------------
void HomeView::draw() {
    if (isOpen == true) {
                
    }
}

//--------------------------------------------------------------
void HomeView::open() {
    isOpen = true;
}

//--------------------------------------------------------------
void HomeView::close() {
    isOpen = false;
}
