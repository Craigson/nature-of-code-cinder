#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example1App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Particle *mParticle;
    float mFrames;
};

void Example1App::setup()
{
    mParticle = new Particle(Vec2f(getWindowWidth() / 2, 10));
    gl::clear( Color( 1, 1, 1 ) );
    mFrames = 240;
}

void Example1App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
    settings->setFrameRate(60);
}

void Example1App::mouseDown( MouseEvent event )
{
}

void Example1App::update()
{
    if (getElapsedFrames() > mFrames)
        mParticle->update();
}

void Example1App::draw()
{
    gl::color(1, 1, 1, 0.1);
    gl::enableAlphaBlending();
    gl::drawSolidRect(Rectf(getWindowBounds()));
    gl::disableAlphaBlending();
    mParticle->draw();
}

CINDER_APP_BASIC( Example1App, RendererGl )
