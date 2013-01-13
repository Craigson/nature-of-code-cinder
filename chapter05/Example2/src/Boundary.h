/*
 *  Boundary.h
 *  Example2
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <Box2D/Box2D.h>


class Boundary {
	
  public:
	
	Boundary(float x, float y, float w, float h, b2World &world);
	
	void draw();
	
    float mX, mY, mW, mH;
    b2Body *mBody;
    b2World *mWorld;
};
