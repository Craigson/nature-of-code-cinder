/*
 *  Walker.cpp
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Walker.h"

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    mLocation = app::getWindowCenter();
    mRadius = 4;
}

Walker::Walker(float x, float y) {
    mLocation = Vec2f(x, y);
    mRadius = 4;
}

void Walker::update() {
    float r = randFloat();
    if (r < 0.4)
        mLocation.x++;
    else if (r < 0.6)
        mLocation.x--;
    else if (r < 0.8)
        mLocation.y++;
    else
        mLocation.y--;
}


void Walker::draw() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( mLocation, mRadius);
}
