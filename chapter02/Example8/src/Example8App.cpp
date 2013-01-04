#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Example8App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    vector<MoverRef> mMovers;
};

void Example8App::prepareSettings(Settings *settings) {
    settings->setFullScreen();
}

void Example8App::setup()
{
    int numMovers = 10;
    for (int i = 0; i < numMovers; i++) {
        auto m = MoverRef( new Mover(randFloat(0.5, 3), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
        mMovers.push_back(m);
    }
}

void Example8App::update()
{
    for (auto mover : mMovers) {
        for (auto attractingMover : mMovers) {
            if (mover != attractingMover) {
                Vec2f force = attractingMover->attract(mover);
                mover->applyForce(force);
            }
        }
        mover->update();
    }
}

void Example8App::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }

}

CINDER_APP_BASIC( Example8App, RendererGl )
