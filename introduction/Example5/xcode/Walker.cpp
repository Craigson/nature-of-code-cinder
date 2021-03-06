/*
 *  Walker.cpp
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

// header files
#include "Walker.h"
#include "cinder/CinderMath.h"

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    Vec2f center = app::getWindowCenter();
    x = center.x;
    y = center.y;
    radius = 16;
    tx = 0;
    ty = 10000;
}

Walker::Walker(float x, float y) {
    this->x = x;
    this->y = y;
    radius = 2;
}

void Walker::step( ) {
    x = lmap(noise.noise(tx), 0.0f, 1.0f, 0.0f, (float)app::getWindowWidth());
    y = lmap(noise.noise(ty), 0.0f, 1.0f, 0.0f, (float)app::getWindowHeight());
    
    tx += 0.01;
    ty += 0.01;
}


void Walker::draw( ) {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( Vec2f(x, y), radius);
}
