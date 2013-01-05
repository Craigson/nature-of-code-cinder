/*
 *  Snake.h
 *  Ecosystem
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Snake> SnakeRef;

class Food;
typedef std::shared_ptr<class Food> FoodRef;

class Snake {
	
public:
    
    Snake();

    void update();
    void draw();
    void eat(FoodRef food);
    ci::Vec2f getLocation() { return this->mLocation; }
    float getHunger() { return this->mHunger; }
    
    void applyForce(ci::Vec2f force);
    bool isTouchingFood(FoodRef food);
    
private:
    
    ci::Vec2f mLocation;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration;
    std::list<ci::Vec2f> mPreviousLocations;
    int mLength;
    float mTopSpeed;
    float mRadius;
    float mHunger;
};
