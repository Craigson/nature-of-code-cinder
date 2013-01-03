/*
 *  FrictionSurface.cpp
 *  Exercise4
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "FrictionSurface.h"
#include "cinder/Rand.h"


// namespaces
using namespace ci;


FrictionSurface::FrictionSurface( ) {
	mCenter = Vec2f( randFloat(app::getWindowWidth()), randFloat(app::getWindowHeight()) );
    mRadius = randFloat(50.0f, 250.0f);
    mCoefficient = randFloat(0.1, 0.6);
}

void FrictionSurface::update( Mover *mover ) {
	if (containsPoint(mover->mLocation)) {
        applyFriction(mover);
    }
}

bool FrictionSurface::containsPoint(Vec2f p) {
    return (mCenter.distanceSquared(p) < mRadius);
}

void FrictionSurface::applyFriction( Mover *mover ) {
    Vec2f friction = mover->mVelocity;
    friction *= -1;
    friction.safeNormalize();
    friction *= mCoefficient;
    mover->applyForce(friction);
}

void FrictionSurface::draw( ) {
    gl::enableAlphaBlending();
    gl::color(0.6, 0, 0, 0.2);
    gl::drawSolidCircle(mCenter, mRadius);
    gl::color(0.6, 0, 0, 1.0);
    gl::drawStrokedCircle(mCenter, mRadius);
    gl::disableAlphaBlending();
	
}
