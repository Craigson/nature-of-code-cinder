#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Attractor.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise8App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    vector<MoverRef> mMovers;
    vector<AttractorRef> mAttractors;
};

void Exercise8App::prepareSettings(Settings *settings) {
    settings->setFullScreen();
    settings->setFrameRate(60.0);
}

void Exercise8App::setup()
{
    Rand::randomize();
    int numMovers = randInt(5, 20);
    for (int i = 0; i < numMovers; i++) {
        auto m = MoverRef( new Mover(randFloat(0.2, 2), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
        mMovers.push_back(m);
    }
    
    int numAttractors = randInt(3, 15);
    for (int i = 0; i < numAttractors; i++) {
        auto a = AttractorRef( new Attractor() );
        mAttractors.push_back(a);
    }
    gl::clear( Color( 1, 1, 1 ) );
}

void Exercise8App::update()
{
    for (auto mover : mMovers) {
        for (auto attractor : mAttractors) {
            Vec2f force = attractor->attract(mover);
            mover->applyForce(force);
        }
        mover->update();
    }
}

void Exercise8App::draw()
{
    gl::enableAlphaBlending();
    gl::color(1, 1, 1, 0.02);
    gl::drawSolidRect( Rectf(getWindowBounds()) );
    for (auto attractor : mAttractors) {
        attractor->draw();
    }
    for (auto mover : mMovers) {
        mover->draw();
    }
    gl::disableAlphaBlending();
}

CINDER_APP_BASIC( Exercise8App, RendererGl )
