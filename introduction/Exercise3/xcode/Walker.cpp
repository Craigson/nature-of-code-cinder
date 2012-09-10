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

// namespaces
using namespace ci;
using namespace std;


Walker::Walker() {
    Vec2f center = app::getWindowCenter();
    x_ = center.x;
    y_ = center.y;
    radius_ = 4;
}

Walker::Walker(float x, float y) {
    x_ = x;
    y_= y;
    radius_ = 4;
}

void Walker::setTarget(Vec2i loc) {
    target_ = loc;
}

void Walker::moveTowardTarget() {
    Vec2f diff = Vec2f(target_) - Vec2f(x_, y_);
    Vec2f step = diff.limited(1);
    x_ += step.x;
    y_ += step.y;
}

void Walker::update() {
    float moveToTarget = randFloat();
    if (moveToTarget < 0.5) {
      moveTowardTarget();
    } else {
        float r = randFloat();
        if (r < 0.4)
            x_++;
        else if (r < 0.6)
            x_--;
        else if (r < 0.8)
            y_--;
        else
            y_--;
    }
}


void Walker::draw() {
    gl::color(255, 255, 255);
    gl::drawSolidCircle( Vec2f(x_, y_), radius_);
}
