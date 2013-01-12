#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example4App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<ParticleSystem*> mParticleSystems;
};

void Example4App::setup()
{
}

void Example4App::mouseDown( MouseEvent event )
{
    mParticleSystems.push_back( new ParticleSystem( Vec2f( event.getPos() ) ) );
}

void Example4App::update()
{
    for (auto system : mParticleSystems) {
        system->update();
    }
}

void Example4App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto system : mParticleSystems) {
        system->draw();
    }
}

CINDER_APP_BASIC( Example4App, RendererGl )
