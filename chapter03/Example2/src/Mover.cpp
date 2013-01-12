/*
 *  Mover.cpp
 *  Example2
 *
 *  Created by Nathan Koch on 1/5/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "cinder/app/AppBasic.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover( float m, float x , float y )
{
	mMass = m;
	mLocation = Vec2f( x, y );
	mVelocity = Vec2f( randFloat( -1.0, 1.0 ), randFloat( -1.0, 1.0 ) );
	mAcceleration = Vec2f( 0.0, 0.0 );
	mAngle = 0;
	mAVelocity = 0;
	mAAcceleration = 0;
}

void Mover::applyForce( Vec2f force )
{
	Vec2f f = force / mMass;
	mAcceleration += f;
}

void Mover::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	
	mAAcceleration = mAcceleration.x / 10.0;
    mAVelocity += mAAcceleration;
    mAVelocity = constrain( mAVelocity, -0.1f, 0.1f );
    mAngle += toDegrees(mAVelocity);
	
	mAcceleration *= 0;
}



void Mover::draw()
{
	float w = mMass*16;
	Rectf rect = Rectf( -w/2, -w/2, w/2, w/2 );
	
	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( mAngle );
	
	// draw solid
	gl::color( ColorA8u::gray( 175, 200 ) );
	gl::drawSolidRect( rect );
	
	// draw outline
	glLineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawStrokedRect( rect );
	glPopMatrix();
}