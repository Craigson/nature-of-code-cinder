/*
 *  Walker.h
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

#pragma once
#include "cinder/Rand.h"

typedef std::shared_ptr<class Walker> WalkerRef;
class Walker {
	
public:
    Walker(float x, float y);
    Walker();

    
    void update();
    void draw();
    void setTarget(ci::Vec2i loc);
    void moveTowardTarget();
    
private:
    ci::Vec2f mLocation;
    int mRadius;
};
