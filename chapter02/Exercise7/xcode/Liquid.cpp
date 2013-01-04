/*
 *  Liquid.cpp
 *  Example5
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Liquid.h"

// namespaces
using namespace ci;


Liquid::Liquid( ) {
    mBounds = Rectf( 0, app::getWindowHeight() / 2, app::getWindowWidth(), app::getWindowHeight());
    mCoefficient = 0.05;
}

Liquid::Liquid( float x, float y, float w, float h, float c ) {
    mBounds = Rectf(x, y, x+w, y+h);
    mCoefficient = c;
}

void Liquid::draw( ) {
    gl::color(0.2, 0.2, 0.2);
    gl::drawSolidRect(mBounds);
}
