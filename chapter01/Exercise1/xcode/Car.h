/*
 *  Car.h
 *  Exercise1
 *
 *  Created by Nathan Koch on 1/1/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
using namespace ci;

class Car {
	
  public:
	
	Car();
    Car(Colorf color, Vec2f mLocation, float speed);
	
	void move();
	void display();
    
    Colorf mColor;
    Vec2f mLocation;
    Vec2f mVelocity;
	
};