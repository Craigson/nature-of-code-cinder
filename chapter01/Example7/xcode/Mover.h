/*
 *  Mover.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Mover {
	
  public:
	
	Mover();
	
	void update();
	void draw();
    void checkEdges();
    
    cinder::Vec2f mLoc;
    cinder::Vec2f mVel;
	
};
