#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example4App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Rand generator_;
    const float sd_ = 60;
    float mean_;
    float xPos_;
};

void Example4App::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    gl::enableAlphaBlending();
    
    generator_.seed(randInt());
    app::setWindowSize(600, 200);
    mean_ = getWindowWidth() / 2;
}

void Example4App::mouseDown( MouseEvent event )
{
}

void Example4App::update()
{
    float num = generator_.nextGaussian();
    xPos_ = sd_ * num + mean_;
}

void Example4App::draw()
{
    gl::color(0, 0, 0, 0.08);
    gl::drawSolidEllipse( Vec2f(xPos_, getWindowHeight() / 2), 16, 16);
    
}

CINDER_APP_BASIC( Example4App, RendererGl )
