/*
 *  Attractor.h
 *  Example6
 *
 *  Created by Nathan Koch on 1/4/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#include "Mover.h"
#pragma once

typedef std::shared_ptr<class Attractor> AttractorRef;
class Attractor {
	
  public:
	
	Attractor();
	
	void draw();
    ci::Vec2f attract(MoverRef m);
	
    float mMass;
    float mG;
    ci::Vec2f mLocation;
};
