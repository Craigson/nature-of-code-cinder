/*
 *  Mover.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Mover.h"
#include "cinder/CinderMath.h"

// namespaces
using namespace ci;
using namespace std;


Mover::Mover( ) {
	mMass =  1.0f;
    mLocation = Vec2f(30, 30);
	mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
}

Mover::Mover(float m, float x, float y) {
    mMass = m;
    mLocation = Vec2f(x, y);
}


void Mover::update( ) {
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    
    mAcceleration *= 0;
}


void Mover::draw( ) {
    gl::enableAlphaBlending();
    gl::color(0.68, 0.68, 0.68, 0.4);
    gl::drawSolidCircle(mLocation, mMass * 16);
    gl::color(0, 0, 0, 0.8);
    gl::drawStrokedCircle(mLocation, mMass * 16);
    gl::disableAlphaBlending();
}

void Mover::applyForce(Vec2f force) {
    Vec2f f = force / mMass;
    mAcceleration += f;
}

void Mover::checkEdges() {
    float w = app::getWindowWidth();
    if (mLocation.x > w) {
        applyForce( Vec2f(w - mLocation.x, 0) );
    } else if (mLocation.x < 0) {
        applyForce( Vec2f(math<float>::abs(mLocation.x), 0) );
    }
    float h = app::getWindowHeight();
    if (mLocation.y > h) {
        applyForce( Vec2f(0, h - mLocation.y) );
    } else if (mLocation.y < 0) {
        applyForce( Vec2f(0, math<float>::abs(mLocation.y)) );
    }
}
