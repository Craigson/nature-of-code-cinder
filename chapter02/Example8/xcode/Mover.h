/*
 *  Mover.h
 *  Example1
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Mover> MoverRef;
class Mover {
	
  public:
	
	Mover();
    Mover(float m, float x, float y);
	
	void update();
	void draw();
    void applyForce(ci::Vec2f force);
    ci::Vec2f attract(MoverRef m);
    
    ci::Vec2f mLocation;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration;
    
    float mMass;
	
};
