/*
 *  Mover.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"
#include "Mover.h"

// namespaces
using namespace ci;


Mover::Mover( ) {
	mMass =  1.0f;
    mLocation = Vec2f( randFloat(app::getWindowWidth()), randFloat(app::getWindowHeight()) );
	mVelocity = Vec2f::zero();
    mAcceleration = Vec2f::zero();
}

Mover::Mover(float m, float x, float y) {
    mMass = m;
    mLocation = Vec2f(x, y);
}


void Mover::update( ) {
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    
    mAcceleration *= 0;
}


void Mover::draw( ) {
    gl::enableAlphaBlending();
    gl::color(0.68, 0.68, 0.68, 0.4);
    gl::drawSolidCircle(mLocation, mMass * 16);
    gl::color(0, 0, 0, 0.8);
    gl::drawStrokedCircle(mLocation, mMass * 16);
    gl::disableAlphaBlending();
}

void Mover::applyForce(Vec2f force) {
    Vec2f f = force / mMass;
    mAcceleration += f;
}

Vec2f Mover::attract(Vec2f mousePosition) {
    Vec2f force = calculateAttraction(mMass, 100.0f, mousePosition, mLocation);
    return force;
}

Vec2f Mover::repel(MoverRef m) {
    Vec2f force = calculateAttraction(mMass, m->mMass, mLocation, m->mLocation);
    force *= -1;
    return force;
}

Vec2f Mover::calculateAttraction(float mass1, float mass2, Vec2f pos1, Vec2f pos2) {
    float G = 0.4;
    Vec2f force = pos1 - pos2;
    float distance = force.length();
    distance = math<float>::clamp(distance, 5.0, 25.0);
    force.safeNormalize();
    
    float strength = (G * mass1 * mass2) / (distance * distance);
    force *= strength;
    return force;
}
