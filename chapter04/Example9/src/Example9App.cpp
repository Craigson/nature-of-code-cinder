#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example9App : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
	void update();
	void draw();
    
    vector<ParticleSystem*> mParticleSystems;
    bool mIsFullscreen;
};

void Example9App::setup()
{
    mIsFullscreen = false;
}

void Example9App::keyDown(KeyEvent event) {
    if (event.getCode() == event.KEY_f) {
        setFullScreen(!mIsFullscreen);
        mIsFullscreen = !mIsFullscreen;
    }
}

void Example9App::mouseDown( MouseEvent event )
{
    mParticleSystems.push_back( new ParticleSystem( Vec2f( event.getPos() ) ) );
}

void Example9App::update()
{
    for (auto system : mParticleSystems) {
        system->update();
    }
}

void Example9App::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    for (auto system : mParticleSystems) {
        system->draw();
    }
}

CINDER_APP_BASIC( Example9App, RendererGl )
