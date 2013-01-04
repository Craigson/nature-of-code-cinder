/*
 *  Attractor.cpp
 *  Example6
 *
 *  Created by Nathan Koch on 1/4/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "Mover.h"
#include "Attractor.h"

// namespaces
using namespace ci;


Attractor::Attractor( ) {
	mLocation = (Vec2f)app::getWindowCenter();
    mMass = 20.0f;
    mG = 0.4f;
}


void Attractor::draw( ) {
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLocation, mMass*2);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLocation, mMass*2);
}

Vec2f Attractor::attract(MoverRef m) {
    Vec2f force = mLocation - m->mLocation;
    float distance = force.length();
    distance = math<float>::clamp(distance, 5.0f, 25.0f);
    float strength = (mG * mMass * mMass) / ( distance * distance );
    force.safeNormalize();
    force *= strength;
    return force;
}
