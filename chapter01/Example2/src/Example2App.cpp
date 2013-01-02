#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example2App : public AppBasic {
  public:
	void setup();
    void prepareSettings (Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Vec2f mLocation;
    Vec2f mVelocity;
};

void Example2App::setup()
{
    mLocation = Vec2f(100, 100);
    mVelocity = Vec2f(2.5, 5);
}

void Example2App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 480);
}

void Example2App::mouseDown( MouseEvent event )
{
}

void Example2App::update()
{
    mLocation += mVelocity;
    
    if ( ( mLocation.x < 0)|| (mLocation.x > getWindowWidth() ) )
        mVelocity.x = mVelocity.x * -1;
    if ( ( mLocation.y < 0 ) || ( mLocation.y >= getWindowHeight() ) )
        mVelocity.y = mVelocity.y * -1;
}

void Example2App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLocation, 16);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLocation, 16);
}

CINDER_APP_BASIC( Example2App, RendererGl )
