#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise8App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover *mMover;
};

void Exercise8App::setup()
{
    Rand::randomize();
    mMover = new Mover();
}

void Exercise8App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Exercise8App::mouseMove(MouseEvent event) {
    mMover->setTarget(event.getPos());
}

void Exercise8App::mouseDown( MouseEvent event )
{
}

void Exercise8App::update()
{
    mMover->update();
    mMover->checkEdges();
}

void Exercise8App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mMover->draw();
}

CINDER_APP_BASIC( Exercise8App, RendererGl )
