#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise6App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    void keyDown(KeyEvent event);
    
    Mover *mMover;
};

void Exercise6App::setup()
{
    Rand::randomize();
    mMover = new Mover();
}

void Exercise6App::prepareSettings(Settings *settings) {
    settings->setWindowSize(640, 360);
}

void Exercise6App::mouseDown( MouseEvent event )
{
}

void Exercise6App::keyDown(KeyEvent event) {
    if (event.getCode() == event.KEY_UP)
        mMover->accelerate();
    if (event.getCode() == event.KEY_DOWN)
        mMover->brake();
}

void Exercise6App::update()
{
    mMover->update();
    mMover->checkEdges();
}

void Exercise6App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mMover->draw();
}

CINDER_APP_BASIC( Exercise6App, RendererGl )
