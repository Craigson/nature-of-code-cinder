/*
 *  Windmill.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <Box2d/Box2D.h>
#include "Box.h"

class Windmill {
	
  public:
	
	Windmill(float x, float y);
	
	void draw();
    void toggleMotor();
    bool motorOn();
    
	
    b2RevoluteJoint *mJoint;
    Box *mBox1;
    Box *mBox2;
};
