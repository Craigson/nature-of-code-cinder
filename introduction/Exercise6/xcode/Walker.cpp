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
#include "Walker.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    Vec2f center = app::getWindowCenter();
    x_ = center.x;
    y_ = center.y;
    radius_ = 2;
}

Walker::Walker(float x, float y) {
    x_ = x;
    y_ = y;
    radius_ = 2;
}

void Walker::update() {
    float stepsize = exponentialRand(-10.0, 10.0);
    float stepx = randFloat(-stepsize, stepsize);
    float stepy = randFloat(-stepsize, stepsize);
    
    x_ += stepx;
    y_ += stepy;
}

float Walker::exponentialRand(float loVal, float hiVal) {
    
    while (true) {
        // Pick a random number: R1
        float r1 = randFloat(loVal, hiVal);
        
        // Computer a probability P that R1 should qualify
        // In this case - R1 squared
        float probability = r1 * r1;
        
        // Pick another number: R2
        float r2 = randFloat(loVal, hiVal);

        // if R2 is less than P, we found our number
        if (r2 < probability) {
            return r1;
        }
        

        // otherwise, go back and do it again
    }
}


void Walker::draw() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( Vec2f(x_, y_), radius_);
}
