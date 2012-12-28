/*
 *  Walker.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 12/22/12
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Walker.h"
#include "cinder/Rand.h"

// namespaces
using namespace ci;


Walker::Walker( ) {
    Vec2f center = app::getWindowCenter();
    x_ = center.x;
    y_ = center.y;
}


void Walker::step( ) {
	int choice = randInt(0, 4);
    
    if (choice == 0) {
        x_++;
    } else if (choice == 1) {
        x_--;
    } else if (choice == 2) {
        y_++;
    } else if (choice == 3) {
        y_--;
    }
}


void Walker::display( ) {
    gl::color(0, 0, 0);
    gl::drawSolidCircle( Vec2f(x_, y_), 1);
}
