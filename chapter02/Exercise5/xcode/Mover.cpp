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

// namespaces
using namespace ci;


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
        mVelocity.x *= -1;
        mLocation.x = w;
    } else if (mLocation.x < 0) {
        mVelocity.x *= -1;
        mLocation.x = 0;
    }
    
    float h = app::getWindowHeight();
    if (mLocation.y > h) {
        mVelocity.y *= -1;
        mLocation.y = h;
    } else if (mLocation.y < 0) {
        mVelocity += -1;
        mLocation.y = 0;
    }
}

void Mover::drag(Liquid *liquid) {
    float speed = mVelocity.length();
    float dragMagnitude = liquid->getCoefficient() * speed * speed;
    
    Vec2f drag = mVelocity;
    drag *= -1;
    drag.safeNormalize();
    drag *= dragMagnitude;
    
    applyForce(drag);
    
}
