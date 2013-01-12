/*
 *  ParticleSystem.h
 *  Example4
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "Particle.h"

class ParticleSystem {
	
  public:
	
	ParticleSystem( ci::Vec2f location );
	
	void update();
	void draw();
    void addParticle();
	
    std::vector<Particle*> mParticles;
    ci::Vec2f mOrigin;
};
