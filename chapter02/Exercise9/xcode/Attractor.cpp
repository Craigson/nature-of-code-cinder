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
#include "cinder/Rand.h"
#include "Mover.h"
#include "Attractor.h"

// namespaces
using namespace ci;


Attractor::Attractor( ) {
	mLocation = Vec2f(randFloat(app::getWindowWidth()), randFloat(app::getWindowHeight()) );
    mMass = randFloat(10.0, 30.0);
    mG = 0.4f;
    mIsVisible = false;
}

Attractor::Attractor( Vec2f l, float m, float g, bool isV) {
    mLocation = l;
    mMass = m;
    mG = g;
    mIsVisible = isV;
}


void Attractor::draw( ) {
    if (mIsVisible) {
        gl::color(0.68, 0.68, 0.68);
        gl::drawSolidCircle(mLocation, mMass*2);
        gl::color(0, 0, 0);
        gl::drawStrokedCircle(mLocation, mMass*2);
    }
}

Vec2f Attractor::attract(MoverRef m) {
    Vec2f force = mLocation - m->mLocation;
    float distance = force.length();
    distance = math<float>::clamp(distance, 5.0f, 25.0f);
    float strength = (mG * math<float>::sin(mMass)) * ( math<float>::cos(distance) );
    force.safeNormalize();
    force *= strength;
    return force;
}
