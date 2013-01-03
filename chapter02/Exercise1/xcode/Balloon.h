/*
 *  Balloon.h
 *  Exercise1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Balloon {
	
public:

    Balloon();

    void update();
    void draw();
    void applyForce(ci::Vec2f force);
    void checkEdges();

private:
    
    ci::Vec2f mLocation;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration;
    float mRadius;
	
};
