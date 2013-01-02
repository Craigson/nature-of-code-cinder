/*
 *  Car.cpp
 *  Exercise1
 *
 *  Created by Nathan Koch on 1/1/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Car.h"

// namespaces
using namespace ci;


Car::Car( ) {
}

Car::Car(Colorf color, Vec2f location, float speed) {
    mColor = color;
    mLocation = location;
    mVelocity = Vec2f(speed, 0);
}


void Car::move( ) {
    mLocation += mVelocity;
    
    if (mLocation.x < 0 || mLocation.x > app::getWindowWidth())
        mVelocity.x *= -1;
    
    if (mLocation.y < 0 || mLocation.y > app::getWindowHeight())
        mVelocity.y *= -1;
}


void Car::display( ) {
    gl::color(mColor);
    Rectf box = Rectf(0, 0, 40, 20);
    box.offsetCenterTo(mLocation);
    gl::drawSolidRoundedRect(box, 5);
    
    gl::color(0, 0, 0);
    gl::drawStrokedRoundedRect(box, 5);
    
    gl::color(0, 0, 0);
	
}