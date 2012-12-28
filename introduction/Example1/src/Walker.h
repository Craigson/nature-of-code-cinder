/*
 *  Walker.h
 *  Example1
 *
 *  Created by Nathan Koch on 12/22/12
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Walker> WalkerRef;
class Walker {
	
  public:
	
	Walker();
	
	void step();
	void display();
	
    float x_, y_;
};
