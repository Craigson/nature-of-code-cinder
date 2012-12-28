#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Example3App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void mouseMove(MouseEvent event);
    void mouseDrag(MouseEvent event);

  private:
    WalkerRef w_;
};

void Example3App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    w_ = WalkerRef(new Walker());
}

void Example3App::mouseMove(MouseEvent event)
{
}

void Example3App::mouseDrag(MouseEvent event)
{
    mouseMove(event);
}

void Example3App::update()
{
    w_->update();
}

void Example3App::draw()
{
    w_->draw();
}

CINDER_APP_BASIC( Example3App, RendererGl )
