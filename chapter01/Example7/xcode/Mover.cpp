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
    mLoc = Vec2f( randFloat(app::getWindowWidth()), randFloat(app::getWindowHeight()) );
    mVel = randVec2f() * 2.0;
}



void Mover::update( ) {
	mLoc += mVel;
}


void Mover::draw( ) {
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLoc, 16);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLoc, 16);
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
