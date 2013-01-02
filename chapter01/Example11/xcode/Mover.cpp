/*
 *  Mover.cpp
 *  Example7
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"

// namespaces
using namespace ci;


Mover::Mover( ) {
    mLoc = Vec2f( Rand::randFloat(app::getWindowWidth()), Rand::randFloat(app::getWindowHeight()) );
    mVel = Rand::randVec2f() * 0.5;
    mAccel = Vec2f::zero();
    mTopSpeed = 10;
    mTarget = app::getWindowCenter();
    mRadius = app::getWindowWidth() / 50;
}

void Mover::update( ) {
    Vec2f dir = mTarget - mLoc;
    dir.safeNormalize();
    dir *= 0.5;
    mAccel = dir;
    
	mVel += mAccel;
    mVel.limit(mTopSpeed);
    
    mLoc += mVel;
}

void Mover::setTarget(Vec2f target) {
    mTarget = target;
}


void Mover::draw( ) {
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLoc, mRadius);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLoc, mRadius);
}

void Mover::checkEdges() {
    if (mLoc.x > app::getWindowWidth()) {
        mLoc.x = 0;
    } else if (mLoc.x < 0) {
        mLoc.x = app::getWindowWidth();
    }
    
    if (mLoc.y > app::getWindowHeight()) {
        mLoc.y = 0;
    } else if (mLoc.y < 0) {
        mLoc.y = app::getWindowHeight();
    }
}
