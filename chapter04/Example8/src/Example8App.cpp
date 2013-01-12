#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example8App : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
    vector<ParticleSystem*> mParticleSystems;
};

void Example8App::setup()
{
}

void Example8App::mouseDown( MouseEvent event )
{
    mParticleSystems.push_back( new ParticleSystem( Vec2f( event.getPos() ) ) );
}

void Example8App::update()
{
    for (auto system : mParticleSystems) {
        system->update();
    }
}

void Example8App::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    for (auto system : mParticleSystems) {
        system->draw();
    }
}

CINDER_APP_BASIC( Example8App, RendererGl )
