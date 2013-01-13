/*
 *  Globals.h
 *  Example1
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

namespace globals {
    b2Vec2 gGravity;
    b2World *gWorld;
    
    b2World getWorld() {
        static b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
        static b2World world = b2World(gravity);
        return world;
    }
}
