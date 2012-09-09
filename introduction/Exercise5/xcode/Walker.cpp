/*
 *  Walker.cpp
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
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
    float num = generatorStep.nextGaussian();
    float mean = 1.0;
    float stdDev = 3.0;
    float amount = num * stdDev + mean;
    
    float r = randFloat();
    if (r < 0.4)
        x += amount;
    else if (r < 0.6)
        x -= amount;
    else if (r < 0.8)
        y += amount;
    else
        y -= amount;
}


void Walker::draw() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( Vec2f(x, y), radius);
}
