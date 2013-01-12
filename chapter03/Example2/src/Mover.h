/*
 *  Mover.h
 *  Example2
 *
 *  Created by Nathan Koch on 1/5/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "cinder/app/AppBasic.h"

class Mover {
public:
	Mover( float m, float x , float y );
    
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass, mAngle, mAVelocity, mAAcceleration;
    
	void applyForce( ci::Vec2f force );
	void update();
	void draw();
};