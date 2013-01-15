/*
 *  Windmill.cpp
 *  Example7
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Globals.h"
#include "Conversions.h"
#include "Windmill.h"

// namespaces
using namespace ci;


Windmill::Windmill( float x, float y ) {
    mBox1 = new Box(x, y-20, false);
    mBox2 = new Box(x, y, true);
    
    b2RevoluteJointDef rjd = b2RevoluteJointDef();
    rjd.Initialize(mBox1->mBody, mBox2->mBody, mBox1->mBody->GetWorldCenter());
    
    // Turning on a motor (optional)
    rjd.motorSpeed = M_PI*2;       // how fast?
    rjd.maxMotorTorque = 1000.0; // how powerful?
    rjd.enableMotor = false;      // is it on?
    // m_joint = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef );
    mJoint = (b2RevoluteJoint*)globals::world->CreateJoint( &rjd );
}

// Turn the motor on or off
void Windmill::toggleMotor() {
    mJoint->EnableMotor(!motorOn());
}

bool Windmill::motorOn() {
    return mJoint->IsMotorEnabled();
}


void Windmill::draw( ) {
    mBox2->draw();
    mBox1->draw();
    
    // Draw anchor just for debug
    Vec2f anchor = Conversions::toScreen(mBox1->mBody->GetWorldCenter());
    gl::color(0, 0, 0);
    gl::drawSolidCircle(anchor, 8);
}
