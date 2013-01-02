/*
 *  Snake.h
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

class Snake {
	
public:
    
    Snake();

    void update();
    void draw();
    void setTarget(ci::Vec2f target);
    
private:
    
    ci::Vec2f mLocation;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration; 
    ci::Vec2f mTarget;
    std::list<ci::Vec2f> mPreviousLocations;
    int mLength;
    float mTopSpeed;
    float mRadius;
};
