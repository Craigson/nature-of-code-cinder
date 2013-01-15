/*
 *  Box.h
 *  Example1
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <Box2D/Box2d.h>

class Box {
	
  public:
	
	Box(float x, float y, bool lock=false);
	
	void update();
	void draw();
    void killBody();
    
    b2Body *mBody;
    float mWidth;
    float mHeight;
    ci::Vec2f mPosition;
	float mAngle;
    b2World *mWorld;
};
