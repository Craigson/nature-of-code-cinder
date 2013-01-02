/*
 *  Mover.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "Cinder/Perlin.h"

class Mover {
	
  public:
	
	Mover();
	
	void update();
	void draw();
    void checkEdges();
    void accelerate();
    void brake();
    
    ci::Vec2f mLoc;
    ci::Vec2f mVel;
    ci::Vec2f mAccel;
    float mTopSpeed;
    ci::Perlin mPerlin;
    float mTime;
};
