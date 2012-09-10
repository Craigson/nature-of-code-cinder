#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Exercise7App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();

  private:
    WalkerRef w;
};

void Exercise7App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    gl::enableAlphaBlending();
    w = WalkerRef(new Walker());
}

void Exercise7App::update()
{
    w->step();
}

void Exercise7App::draw()
{
    gl::color(0, 0, 0, 0.04);
    gl::drawSolidRect(Rectf(Vec2f(0, 0), Vec2f(getWindowWidth(), getWindowHeight())));
    
    w->draw();
}

CINDER_APP_BASIC( Exercise7App, RendererGl )
