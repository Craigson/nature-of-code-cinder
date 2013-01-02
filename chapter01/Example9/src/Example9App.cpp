#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example9App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Mover *mMover;
};

void Example9App::setup()
{
    Rand::randomize();
    mMover = new Mover();
}

void Example9App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Example9App::mouseDown( MouseEvent event )
{
}

void Example9App::update()
{
    mMover->update();
    mMover->checkEdges();
}

void Example9App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mMover->draw();
}

CINDER_APP_BASIC( Example9App, RendererGl )
