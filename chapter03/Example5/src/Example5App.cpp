#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example5App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Example5App::setup()
{
}

void Example5App::prepareSettings(Settings *settings) {
    settings->setWindowSize(440, 240);
    settings->setFrameRate(60);
}

void Example5App::mouseDown( MouseEvent event )
{
}

void Example5App::update()
{
}

void Example5App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    float period = 80;
    float amplitude = 100;
    
    float x = amplitude * cos(M_2_PI * getElapsedFrames() / period);
    gl::pushMatrices();
    gl::translate((Vec2f)getWindowCenter());
    gl::color(0, 0, 0);
    gl::drawLine(Vec2f(0, 0), Vec2f(x, 0));
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(Vec2f(x, 0), 20);
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(Vec2f(x, 0), 20);
    gl::popMatrices();
}

CINDER_APP_BASIC( Example5App, RendererGl )
