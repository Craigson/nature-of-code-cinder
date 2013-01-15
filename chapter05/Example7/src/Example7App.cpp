#include "cinder/app/AppNative.h"
#include <Box2d/Box2D.h>
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Globals.h"
#include "Windmill.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

extern b2World *globals::world;

class Example7App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Windmill* mWindmill;
    vector<Particle*> mParticles;
};

void Example7App::setup()
{
    mWindmill = new Windmill(getWindowWidth() / 2, 175);
}

void Example7App::mouseDown( MouseEvent event )
{
    mWindmill->toggleMotor();
}

void Example7App::update()
{
    float32 timeStep = 1.0f / 60.f;
    int32 velocityIterations = 10;
    int32 positionIterations = 8;
    
    globals::world->Step(timeStep, velocityIterations, positionIterations);
    
    if (true) {
        float sz = randFloat(4,8);
        mParticles.push_back( new Particle( randFloat((getWindowWidth()/2)-100,(getWindowWidth()/2)+100), getWindowHeight()/2, sz) );
    }
}

void Example7App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    // Look at all particles
    
    for (int i = mParticles.size()-1; i >= 0; i--) {
        Particle *p = mParticles[i];
        p->draw();
        
        if ( p->isDone() ) {
            mParticles.erase(mParticles.begin() + i);
        }
    }
    
    mWindmill->draw();
}

CINDER_APP_NATIVE( Example7App, RendererGl )
