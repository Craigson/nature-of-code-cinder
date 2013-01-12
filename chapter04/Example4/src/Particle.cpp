/*
 *  Particle.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Particle.h"

// namespaces
using namespace ci;


Particle::Particle( Vec2f location ) {
	mAcceleration = Vec2f(0, 0.05);
    mVelocity = Vec2f(randFloat(-1, 1), randFloat(-2, 0));
	mLocation = location;
    mLifespan = 255.0;
}


void Particle::update( ) {
	mVelocity += mAcceleration;
    mLocation += mVelocity;
    mLifespan -= 2.0;
}


void Particle::draw( ) {
    float alpha = lmap<float>(mLifespan, 0, 255.0, 0, 1);
    gl::color(0, 0, 0, alpha);
    gl::enableAlphaBlending();
    gl::drawSolidCircle(mLocation, 8);
    gl::disableAlphaBlending();
}

bool Particle::isDead() {
    if (mLifespan < 0.0)
        return true;
    else
        return false;
}