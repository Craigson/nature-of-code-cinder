#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

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
    
    float mX = 100;
    float mY = 100;
    float mXSpeed = 1;
    float mYSpeed = 3.3;
};

void Example1App::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
}

void Example1App::prepareSettings( Settings *settings ) {
    settings->setWindowSize( 640, 360 );
    settings->setFrameRate(60.0f);
}

void Example1App::mouseDown( MouseEvent event )
{
}

void Example1App::update()
{
    mX = mX + mXSpeed;
    mY = mY + mYSpeed;
    if (mX < getWindowWidth() || mX < 0)
        mXSpeed = mXSpeed * -1;
    if (mY > getWindowHeight() || mY < 0)
        mYSpeed = mYSpeed * -1;
}

void Example1App::draw()
{
    int radius = 16;
    Vec2f loc = Vec2f(mX, mY);
    
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::color(0.69f, 0.69f, 0.69f);
    gl::drawSolidCircle(loc, radius);
    
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(loc, radius);
}

CINDER_APP_BASIC( Example1App, RendererGl )
