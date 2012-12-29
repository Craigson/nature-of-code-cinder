/*
 *  Walker.h
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "cinder/CinderMath.h"

typedef std::shared_ptr<class Walker> WalkerRef;
class Walker {
	
public:
    Walker(float x, float y);
    Walker();

    void step();
    void draw();
    
private:
    float x, y;
    float tx, ty;
    int radius;
    ci::Perlin noise;
    
};
