#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example6App : public AppBasic {
  public:
	void setup();
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    void prepareSettings( Settings *settings );
    
    Vec2f mMouseLoc;
    float mRectWidth = 0.0;
};

void Example6App::setup()
{
    mMouseLoc = getWindowCenter();
}

void Example6App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Example6App::mouseMove( MouseEvent event ) {
    mMouseLoc = (Vec2f)event.getPos();
}

void Example6App::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}


void Example6App::update()
{
    mMouseLoc -= getWindowCenter();
    
    mMouseLoc.safeNormalize();
    mMouseLoc *= 50;
    
    mRectWidth = mMouseLoc.length();
}

void Example6App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    gl::color(0, 0, 0);
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::drawLine(Vec2f::zero(), mMouseLoc);
    gl::popMatrices();
    
    gl::color(0, 0.8, 0);
    
    gl::drawSolidRect(Rectf(0, 0, mRectWidth, 10));
}

CINDER_APP_BASIC( Example6App, RendererGl )
