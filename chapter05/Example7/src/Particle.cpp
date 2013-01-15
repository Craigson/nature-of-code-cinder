/*
 *  Particle.cpp
 *  Example7
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Conversions.h"
#include "Particle.h"


// namespaces
using namespace ci;


Particle::Particle( float x, float y, float radius ) {
    mRadius = radius;
    makeBody(x, y, mRadius);
	mBody->SetUserData(this);
}


void Particle::killBody() {
    globals::world->DestroyBody(mBody);
}

bool Particle::isDone() {
    Vec2f pos = Conversions::toScreen( mBody->GetPosition() );
    bool status = false;
    if (pos.y > app::getWindowHeight() + mRadius * 2) {
        killBody();
        status = true;
    }
    return status;
}

void Particle::draw( ) {
    // We look at each body and get its screen position
    Vec2f pos = Conversions::toScreen( mBody->GetPosition() );

    // Get its angle of rotation
    float a = mBody->GetAngle();
    gl::pushMatrices();
    gl::translate(pos);
    
    gl::rotate(-a);
    gl::color(0.5, 0.5, 0.5);
    gl::drawSolidCircle(pos, mRadius);
    glLineWidth(2.0);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(pos, mRadius);
    glLineWidth(1.0);

    // Let's add a line so we can see the rotation
    gl::drawLine(Vec2f::zero(), Vec2f(mRadius, 0));
    gl::popMatrices();
	
}

// Here's our function that adds the particle to the Box2D world
void Particle::makeBody(float x, float y, float r) {
    // Define a body
    b2BodyDef bd = b2BodyDef();
    
    // Set its position
    bd.position = Conversions::toPhysics(Vec2f(x, y));
    
    bd.type = b2BodyType::b2_dynamicBody;
    
    mBody = globals::world->CreateBody(&bd);
    
    // Make the body's shape a circle
    b2CircleShape cs = b2CircleShape();
    cs.m_radius = Conversions::toPhysics(r);
    
    b2FixtureDef fd = b2FixtureDef();
    fd.shape = &cs;
    
    fd.density = 2.0;
    fd.friction = 0.01;
    fd.restitution = 0.3; // Restitution is bounciness
    
    mBody->CreateFixture(&fd);
    
    // Give it a random initial velocity (and angular velocity)
    mBody->SetLinearVelocity(b2Vec2(randFloat(-10.0f,10.0f),randFloat(5.0f,10.0f)));
    mBody->SetAngularVelocity(randFloat(-10, 10));
}