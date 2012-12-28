#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Exercise3App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void mouseMove(MouseEvent event);
    void mouseDrag(MouseEvent event);

  private:
    WalkerRef w_;
};

void Exercise3App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
}

void Exercise3App::mouseMove(MouseEvent event)
{
    w_->setTarget(event.getPos());
}

void Exercise3App::mouseDrag(MouseEvent event)
{
    mouseMove(event);
}

void Exercise3App::update()
{
    w_->update();
}

void Exercise3App::draw()
{
    w_->draw();
}

CINDER_APP_BASIC( Exercise3App, RendererGl )
