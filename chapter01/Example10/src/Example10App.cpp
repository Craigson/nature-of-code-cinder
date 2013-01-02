#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example10App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover *mMover;
};

void Example10App::setup()
{
    Rand::randomize();
    mMover = new Mover();
}

void Example10App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Example10App::mouseMove(MouseEvent event) {
    mMover->setTarget(event.getPos());
}

void Example10App::mouseDown( MouseEvent event )
{
}

void Example10App::update()
{
    mMover->update();
    mMover->checkEdges();
}

void Example10App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mMover->draw();
}

CINDER_APP_BASIC( Example10App, RendererGl )
