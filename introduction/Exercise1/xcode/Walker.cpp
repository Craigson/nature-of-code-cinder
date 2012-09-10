/*
 *  Walker.cpp
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Walker.h"

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    Vec2f center = app::getWindowCenter();
    x = center.x;
    y = center.y;
    radius = 2;
}

Walker::Walker(float x, float y) {
    this->x = x;
    this->y = y;
    radius = 2;
}

void Walker::update() {
    float r = Rand::randFloat();
    if (r < 0.4)
        x++;
    else if (r < 0.6)
        x--;
    else if (r < 0.8)
        y++;
    else
        y--;
}


void Walker::draw() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( Vec2f(x, y), radius);
}
