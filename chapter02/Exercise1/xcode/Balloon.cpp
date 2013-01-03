/*
 *  Balloon.cpp
 *  Exercise1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Balloon.h"

// namespaces
using namespace ci;


Balloon::Balloon( ) {
    mLocation = Vec2f(app::getWindowCenter().x, app::getWindowHeight() - 20);
    mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
    mRadius = 40;
}


void Balloon::update( ) {
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    mAcceleration *= 0;
}


void Balloon::draw( ) {
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLocation, mRadius);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLocation, mRadius);
}

void Balloon::applyForce(Vec2f force) {
    mAcceleration += force;
}

void Balloon::checkEdges() {
    if (mLocation.y < 0 || mLocation.y > app::getWindowHeight()) {
        mVelocity *= -1.0;
    }
    if (mLocation.x < 0) {
        mLocation.x = app::getWindowWidth();
    } else if (mLocation.x > app::getWindowWidth()) {
        mLocation.x = 0;
    }
}