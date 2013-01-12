/*
 *  Pendulum.h
 *  Example10
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Pendulum {
	
  public:
	
	Pendulum(ci::Vec2f origin, float armLength);
	
	void update();
	void draw();
    
    ci::Vec2f mLocation;
    ci::Vec2f mOrigin;
    float mArmLength;
    float mAngle;
    float mAngleVelocity;
    float mAngleAcceleration;
    float mDamping;
};
