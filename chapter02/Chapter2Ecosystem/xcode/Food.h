/*
 *  Food.h
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/5/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Food> FoodRef;

class Snake;
typedef std::shared_ptr<class Snake> SnakeRef;

class Food {
	
  public:
	
	Food();
	
	void draw();
    void update();
    ci::Vec2f attract(SnakeRef snake);
	
    float mAmount;
    float mInitialAmount;
    ci::Vec2f mLocation;
};
