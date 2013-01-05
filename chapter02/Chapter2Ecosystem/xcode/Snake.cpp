/*
 *  Snake.cpp
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "cinder/Rand.h"
#include "Food.h"
#include "Snake.h"

// namespaces
using namespace ci;
using namespace std;


Snake::Snake( ) {
	mLocation = Vec2f(Rand::randFloat(app::getWindowWidth()), Rand::randFloat(app::getWindowHeight()));
    mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
    mLength = randFloat(150, 300);
    mTopSpeed = randFloat(2.0, 4.0);
    mRadius = app::getWindowWidth() / randFloat(40, 200);
    mHunger = randFloat(mRadius / 20, mRadius * 10);
}


void Snake::update( ) {
	mPreviousLocations.push_front(mLocation);
    if (mPreviousLocations.size() > mLength) {
        mPreviousLocations.pop_back();
    }
    mVelocity += mAcceleration;
    mVelocity.limit(mTopSpeed);
    mLocation += mVelocity;
    
    mAcceleration *= 0;
}

void Snake::applyForce(Vec2f force) {
//    Vec2f wriggle = Vec2f(math<float>::sin(force.x), math<float>::cos(force.y));
    Vec2f wriggle = force;
    mAcceleration += wriggle;
}

void Snake::draw( ) {
    list<Vec2f> snakeCells = mPreviousLocations;
    snakeCells.push_front(mLocation);

    float incAmount = 1.0f / snakeCells.size();
    float inc = 0.0f;
    for (Vec2f cellLoc : snakeCells) {;
        gl::color(inc, inc, inc);
        gl::drawSolidCircle(cellLoc, mRadius);
        inc += incAmount;
    }
}

bool Snake::isTouchingFood(FoodRef food) {
    Vec2f v = food->mLocation - mLocation;
    float distance = v.length();
    return (distance < food->mAmount);
}

void Snake::eat(FoodRef food) {
    food->mAmount--;
}