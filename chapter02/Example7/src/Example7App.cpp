#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Attractor.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Example7App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    vector<MoverRef> mMovers;
    AttractorRef mAttractor;
};

void Example7App::prepareSettings(Settings *settings) {
    settings->setWindowSize(800, 600);
}

void Example7App::setup()
{
    int numMovers = 10;
    for (int i = 0; i < numMovers; i++) {
        auto m = MoverRef( new Mover(randFloat(0.2, 2), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
        mMovers.push_back(m);
    }
    mAttractor = AttractorRef(new Attractor());
}

void Example7App::update()
{
    for (auto mover : mMovers) {
        Vec2f force = mAttractor->attract(mover);
        mover->applyForce(force);
        mover->update();
    }
}

void Example7App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    mAttractor->draw();
    for (auto mover : mMovers) {
        mover->draw();
    }

}

CINDER_APP_BASIC( Example7App, RendererGl )
