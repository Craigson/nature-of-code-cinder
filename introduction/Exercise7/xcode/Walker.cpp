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

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    Vec2f center = app::getWindowCenter();
    x = center.x;
    y = center.y;
    radius = 24;
    tx = 0;
    ty = 10000;
}

Walker::Walker(float x, float y) {
    this->x = x;
    this->y = y;
    radius = 2;
}

void Walker::step( ) {
    float xStep = lmap(noise.noise(tx), -1.0f, 1.0f, -5.0f, 5.0f);
    float yStep = lmap(noise.noise(ty), -1.0f, 1.0f, -5.0f, 5.0f);
    
    x += xStep;
    y += yStep;
    
    tx += 0.01;
    ty += 0.01;
}


void Walker::draw( ) {
    gl::color(0.2, 0.2, 0.2);
    gl::drawSolidCircle( Vec2f(x, y), radius);
}
