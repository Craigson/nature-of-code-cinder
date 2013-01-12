#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example9App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    float mStartAngle;
    float mAngleVelocity;
};

void Example9App::setup()
{
    mStartAngle = 0;
    mAngleVelocity = 0.1;
}

void Example9App::prepareSettings(Settings *settings) {
    settings->setWindowSize(800, 400);
    settings->setFrameRate(60.0);
}

void Example9App::mouseDown( MouseEvent event )
{
}

void Example9App::update()
{
}

void Example9App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    float angle = mStartAngle;
    mStartAngle += 0.02;
    
    for (int x = 0; x <= getWindowWidth(); x+= 24 ) {
        float y = lmap<float>(math<float>::sin(angle), -1, 1, 0, getWindowHeight());
        gl::enableAlphaBlending();
        gl::color(0.68, 0.68, 0.68, 0.50);
        gl::drawSolidCircle(Vec2f(x, y), 24);
        gl::disableAlphaBlending();
        gl::color(0, 0, 0);
        gl::drawStrokedCircle(Vec2f(x, y), 24);
        
        angle += mAngleVelocity;
    }
}

CINDER_APP_BASIC( Example9App, RendererGl )
