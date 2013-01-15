/*
 *  Box.cpp
 *  Example1
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Box.h"
#include "Globals.h"
#include "Conversions.h"

// namespaces
using namespace ci;


Box::Box( float x, float y, bool lock) {
    float size = 8;
	mWidth = size;
    mHeight = size;
    mPosition = Vec2f(x, y);
    mAngle = 0.0;
    b2BodyDef bd = b2BodyDef();
    
    if (lock)
        bd.type = b2BodyType::b2_staticBody;
    else
        bd.type = b2BodyType::b2_dynamicBody;
    
    bd.position.Set(Conversions::toPhysics(x), Conversions::toPhysics(y));
    mBody = globals::world->CreateBody(&bd);

    b2PolygonShape ps = b2PolygonShape();
    float box2dW = Conversions::toPhysics(mWidth / 2);
    float box2dH = Conversions::toPhysics(mHeight / 2);
    ps.SetAsBox(box2dW, box2dH);
    
    b2FixtureDef fd = b2FixtureDef();
    fd.shape = &ps;
    fd.density = size / 5;
    fd.friction = 0.3;
    fd.restitution = 0.5;

    mBody->CreateFixture(&fd);
    
    mBody->SetLinearVelocity(b2Vec2(randFloat(-5,5),randFloat(2,5)));
    mBody->SetAngularVelocity(randFloat(-5,5));
}

void Box::killBody() {
    globals::world->DestroyBody(mBody);
}

void Box::update( ) {
	mPosition = Conversions::toScreen(mBody->GetPosition());
	mAngle = mBody->GetAngle();
}


void Box::draw( ) {
    gl::pushMatrices();
    gl::translate( mPosition );
    gl::rotate(-mAngle);
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidRoundedRect(Rectf(0, 0, mWidth, mHeight), 5);
    gl::color(0, 0, 0);
    glLineWidth(2.0);
    gl::drawStrokedRoundedRect(Rectf(0, 0, mWidth, mHeight), 5);
    gl::popMatrices();
}
