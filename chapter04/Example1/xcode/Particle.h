/*
 *  Particle.h
 *  Example1
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Particle {
	
  public:
	
	Particle(ci::Vec2f location);
	
	void update();
	void draw();
    bool isDead();
    
    ci::Vec2f mLocation;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration;
    float mLifespan;
	
};
