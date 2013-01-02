#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example3App : public AppBasic {
  public:
	void setup();
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    void prepareSettings( Settings *settings );
    
    Vec2f mMouseLoc;
};

void Example3App::setup()
{
    mMouseLoc = getWindowCenter();
}

void Example3App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Example3App::mouseMove( MouseEvent event ) {
    mMouseLoc = (Vec2f)event.getPos();
}

void Example3App::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}


void Example3App::update()
{
    mMouseLoc = mMouseLoc - getWindowCenter();
}

void Example3App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    gl::color(0, 0, 0);
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::drawLine(Vec2f::zero(), mMouseLoc);
    gl::popMatrices();
}

CINDER_APP_BASIC( Example3App, RendererGl )
