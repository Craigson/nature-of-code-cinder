/*
 *  FrictionSurface.h
 *  Exercise4
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "Mover.h"
#pragma once


class FrictionSurface {
	
  public:
	
	FrictionSurface();
	
	void update(Mover *mover);
	void draw();
    bool containsPoint(ci::Vec2f p);
    void applyFriction(Mover *mover);
    
    
    ci::Vec2f mCenter;
    float mRadius;
    float mCoefficient;
	
};
