/*
 *  Liquid.h
 *  Example5
 *
 *  Created by Nathan Koch on 1/3/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Liquid {
	
public:
	
    Liquid();
    Liquid(float x, float y, float w, float h, float c);

    void draw();
    bool contains(ci::Vec2f point) { return mBounds.contains(point); }
    float getCoefficient() { return mCoefficient; }
    
private:
    ci::Rectf mBounds;
    float mCoefficient;
	
};
