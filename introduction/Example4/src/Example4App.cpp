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
    const float mean_ = 320;
    float xPos_;
};

void Example4App::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    gl::enableAlphaBlending();
    
    generator_.seed(randInt());
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
    gl::color(0, 0, 0, 0.1);
    gl::drawSolidEllipse( Vec2f(xPos_, 180), 16, 16);
    
}

CINDER_APP_BASIC( Example4App, RendererGl )
