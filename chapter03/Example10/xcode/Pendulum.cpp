/*
 *  Pendulum.cpp
 *  Example10
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Pendulum.h"

// namespaces
using namespace ci;


Pendulum::Pendulum( Vec2f origin, float armLength) {
	mOrigin = origin;
	mLocation = Vec2f::zero();
    mArmLength = armLength;
    mAngle = M_PI / 4;
    
    mAngleVelocity = 0.0;
    mAngleAcceleration = 0.0;
    mDamping = 0.995;
}


void Pendulum::update( ) {
	float gravity = 0.4;
    mAngleAcceleration = ( -1 * gravity / mArmLength) * sin(mAngle);
	
    mAngleVelocity += mAngleAcceleration;
    mAngle += mAngleVelocity;
    mAngleVelocity *= mDamping;
}


void Pendulum::draw( ) {
	mLocation = Vec2f(mArmLength * sin(mAngle), mArmLength * cos(mAngle));
	mLocation += mOrigin;
    
    gl::color(0, 0, 0);
    gl::drawLine(mOrigin, mLocation);
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLocation, 16);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLocation, 16);
}
