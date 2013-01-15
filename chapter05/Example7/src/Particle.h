/*
 *  Particle.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <Box2D/Box2D.h>
#include "Globals.h"

extern b2World *globals::world;

class Particle {
	
  public:
	
	Particle(float x, float y, float radius);
	
	void draw();
    void makeBody(float x, float y, float r);
    void killBody();
    bool isDone();
    
    b2Body *mBody;
    float mRadius;
};
