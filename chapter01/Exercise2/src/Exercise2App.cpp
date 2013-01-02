#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Exercise2App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void mouseMove(MouseEvent event);
    void mouseDrag(MouseEvent event);

  private:
    WalkerRef mWalker;
};

void Exercise2App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    mWalker = WalkerRef(new Walker());
}

void Exercise2App::mouseMove(MouseEvent event)
{
}

void Exercise2App::mouseDrag(MouseEvent event)
{
    mouseMove(event);
}

void Exercise2App::update()
{
    mWalker->update();
}

void Exercise2App::draw()
{
    mWalker->draw();
}

CINDER_APP_BASIC( Exercise2App, RendererGl )
