/*
 *  ParticleSystem.cpp
 *  Example4
 *
 *  Created by Nathan Koch on 1/12/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "ParticleSystem.h"

// namespaces
using namespace ci;


ParticleSystem::ParticleSystem( Vec2f location ) {
	mOrigin = location;
}

void ParticleSystem::addParticle() {
    mParticles.push_back(new Particle(mOrigin));
}


void ParticleSystem::update( ) {
    addParticle();
    for (int i = 0; i < mParticles.size(); i++) {
        Particle *particle = mParticles.at(i);
        particle->update();
        if (particle->isDead()) {
            mParticles.erase(mParticles.begin() + i);
        }
    }
}


void ParticleSystem::draw( ) {
    for (auto p : mParticles) {
        p->draw();
    }
}
