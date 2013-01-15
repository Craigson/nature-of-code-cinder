/*
 *  Globals.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/13/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <Box2d/Box2d.h>

namespace globals {
    static b2Vec2 gravity = b2Vec2(0.0f, 3.0f);
    static b2World *world = new b2World(gravity);
}
