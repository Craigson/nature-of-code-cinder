/*
 *  Food.cpp
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/5/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Snake.h"
#include "Food.h"

// namespaces
using namespace ci;


Food::Food( ) {
	mInitialAmount = randFloat(20, 60);
    mAmount = mInitialAmount - 10;
    mLocation = Vec2f( randFloat(0, app::getWindowWidth()), randFloat(0, app::getWindowHeight()) );
}

void Food::draw( ) {
    gl::color(0.42, 0.88, 0.88);
    gl::drawSolidCircle(mLocation, mAmount);
    gl::color(0, 0, 0);
    glLineWidth(2);
    gl::drawStrokedCircle(mLocation, mInitialAmount);
    glLineWidth(1);
}


Vec2f Food::attract(SnakeRef snake) {
    Vec2f force = mLocation - snake->getLocation();
    float distance = force.length();
    distance = math<float>::clamp(distance, 10.0f, 25.0f);
    float strength = (mAmount * snake->getHunger()) / ( distance * distance ) / 10;
    force.safeNormalize();
    force *= strength;
    return force;
}
