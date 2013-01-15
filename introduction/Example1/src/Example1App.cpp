#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example1App : public AppBasic {
  public:
	void setup();
    void prepareSettings( Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    WalkerRef w_;
};

void Example1App::prepareSettings(Settings *settings) {
    settings->setWindowSize(200, 200);
}

void Example1App::setup()
{
    w_ = WalkerRef(new Walker());
    gl::clear( Color( 1, 1, 1 ) );
}

void Example1App::mouseDown( MouseEvent event )
{
}

void Example1App::update()
{
    w_->step();
}

void Example1App::draw()
{
    w_->display();
}

CINDER_APP_BASIC( Example1App, RendererGl )
