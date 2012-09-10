/*
 *  Walker.h
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 Dialect Partners. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Walker> WalkerRef;
class Walker {
	
public:
    Walker(float x, float y);
    Walker();
    
    void update();
    void draw();
    float exponentialRand(float loVal, float hiVal);
    
private:
    float x_;
    float y_;
    int radius_;

};
