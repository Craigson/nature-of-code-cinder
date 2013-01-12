#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example10App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
    void keyDown( KeyEvent event);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Pendulum *mPendulum;
    bool mSpacePressed;
};

void Example10App::setup()
{
    mPendulum = new Pendulum(Vec2f(getWindowWidth() / 2, 10), 125);
    mSpacePressed = false;
}

void Example10App::prepareSettings(Settings *settings) {
    settings->setFrameRate(60);
    settings->setWindowSize(640, 360);
}

void Example10App::keyDown(KeyEvent event) {
    if ( event.getCode() == event.KEY_SPACE ) {
        mSpacePressed = true;
    }
}

void Example10App::mouseDown( MouseEvent event )
{
}

void Example10App::update()
{
    if (mSpacePressed)
        mPendulum->update();
}

void Example10App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mPendulum->draw();
}

CINDER_APP_BASIC( Example10App, RendererGl )
