#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example4App : public AppBasic {
  public:
	void setup();
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    void prepareSettings( Settings *settings );
    
    Vec2f mMouseLoc;
};

void Example4App::setup()
{
    mMouseLoc = getWindowCenter();
}

void Example4App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Example4App::mouseMove( MouseEvent event ) {
    mMouseLoc = (Vec2f)event.getPos();
}

void Example4App::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}


void Example4App::update()
{
    mMouseLoc = mMouseLoc - getWindowCenter();
    mMouseLoc *= 0.5;
}

void Example4App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    gl::color(0, 0, 0);
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::drawLine(Vec2f::zero(), mMouseLoc);
    gl::popMatrices();
}

CINDER_APP_BASIC( Example4App, RendererGl )
