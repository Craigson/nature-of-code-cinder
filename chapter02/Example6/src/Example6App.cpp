#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Attractor.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Example6App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    MoverRef mMover;
    AttractorRef mAttractor;
};

void Example6App::prepareSettings(Settings *settings) {
    settings->setFullScreen();
}

void Example6App::setup()
{
    mMover = MoverRef(new Mover());
    mAttractor = AttractorRef(new Attractor());
}

void Example6App::update()
{
    Vec2f force = mAttractor->attract(mMover);
    mMover->applyForce(force);
    mMover->update();
}

void Example6App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    mAttractor->draw();
    mMover->draw();
}

CINDER_APP_BASIC( Example6App, RendererGl )
