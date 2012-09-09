#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Exercise1App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();

  private:
    WalkerRef w;
};

void Exercise1App::setup()
{
    w = WalkerRef(new Walker());
    gl::clear( Color( 0, 0, 0 ) );
}

void Exercise1App::update()
{
    w->update();
}

void Exercise1App::draw()
{
    w->draw();
}

CINDER_APP_BASIC( Exercise1App, RendererGl )
