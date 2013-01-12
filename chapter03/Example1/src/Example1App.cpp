#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example1App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void update();
	void draw();
    
    float mAngle;
    float mAngleVelocity;
    float mAngleAcceleration;
};

void Example1App::setup()
{
    mAngle = 0;
    mAngleVelocity = 0;
    mAngleAcceleration = 0.001;
}

void Example1App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 480);
    settings->setFrameRate(30.0);
}

void Example1App::update()
{
    mAngleVelocity += mAngleAcceleration;
    mAngle += mAngleVelocity;
}

void Example1App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    

    gl::pushMatrices();
    gl::translate( (Vec2f)app::getWindowCenter() );
    gl::rotate( toDegrees(mAngle) );
    gl::color(0, 0, 0);
    gl::drawLine(Vec2f(-50, 0), Vec2f(50, 0));
    gl::drawStrokedCircle(Vec2f(50, 0), 8);
    gl::drawStrokedCircle(Vec2f(-50, 0), 8);
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(Vec2f(50, 0), 8);
    gl::drawSolidCircle(Vec2f(-50, 0), 8);
    gl::popMatrices();
}

CINDER_APP_BASIC( Example1App, RendererGl )
