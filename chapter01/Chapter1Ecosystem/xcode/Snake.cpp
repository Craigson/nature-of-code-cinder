/*
 *  Snake.cpp
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "cinder/Rand.h"
#include "Snake.h"

// namespaces
using namespace ci;
using namespace std;


Snake::Snake( ) {
	mLocation = Vec2f(Rand::randFloat(app::getWindowWidth()), Rand::randFloat(app::getWindowHeight()));
    mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
    mTarget = app::getWindowCenter();
    mLength = 100;
    mTopSpeed = 4;
    mRadius = app::getWindowWidth() / 100;
}


void Snake::update( ) {
	mPreviousLocations.push_front(mLocation);
    if (mPreviousLocations.size() > mLength) {
        mPreviousLocations.pop_back();
    }
    
    Vec2f dist = mTarget - mLocation;
    Vec2f dir = dist.safeNormalized();
    Vec2f wriggle = Vec2f(math<float>::sin(dir.x) + Rand::randFloat(-0.2f, 0.2f), math<float>::cos(dir.y) + Rand::randFloat(-0.2f, 0.2f));
    mAcceleration = dir + wriggle;
	mVelocity += mAcceleration;
    mVelocity.limit(mTopSpeed);
    
    mLocation += mVelocity;
}


void Snake::draw( ) {
    list<Vec2f> snakeCells = mPreviousLocations;
    snakeCells.push_front(mLocation);

    float incAmount = 1.0f / snakeCells.size();
    float inc = 0.0f;
    for (Vec2f cellLoc : snakeCells) {;
        gl::color(inc, inc, inc);
        gl::drawSolidCircle(cellLoc, mRadius);
        inc += incAmount;
    }
}

void Snake::setTarget(Vec2f target) {
    mTarget = target;
}
