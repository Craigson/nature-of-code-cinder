/*
 *  Boundary.cpp
 *  Example2
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "Conversions.h"
#include "Boundary.h"

// namespaces
using namespace ci;


Boundary::Boundary( float x, float y, float w, float h, b2World &world) {
	mX = x;
    mY = y;
    mW = w;
    mH = h;
    mWorld = &world;
    
    b2BodyDef bd = b2BodyDef();
    bd.position.Set(Conversions::toPhysics(x), Conversions::toPhysics(y));
    bd.type = b2BodyType::b2_staticBody;
    mBody = mWorld->CreateBody(&bd);
    
    float box2dW = Conversions::toPhysics(mW);
    float box2dH = Conversions::toPhysics(mH);
    b2PolygonShape ps = b2PolygonShape();
    ps.SetAsBox(box2dW, box2dH);
    
    mBody->CreateFixture(&ps, 1);
}


void Boundary::draw( ) {
    gl::color(0, 0, 0);
    gl::drawSolidRect(Rectf(mX, mY, mX+mW, mY+mH));
	
}
