#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example5App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    vector<Mover*> mMovers;
    int mNumMovers;
    
    Liquid *liquid;
};

void Example5App::prepareSettings(Settings *settings) {
    settings->setFullScreen();
}

void Example5App::setup()
{
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(1.0, 5.0), randFloat(getWindowWidth()), 10));
        i++;
    }
    liquid = new Liquid();
}

void Example5App::update()
{
    Vec2f wind = Vec2f(0.05, 0);
    for (auto mover : mMovers) {
        if (liquid->contains(mover->mLocation)) {
            mover->drag(liquid);
        }
        
        mover->applyForce(wind);
        
        float c = 0.01;
        Vec2f friction = mover->mVelocity;
        friction *= -1;
        friction.safeNormalize();
        friction *= c;
        mover->applyForce(friction);

        float m = (0.1 * mover->mMass);
        Vec2f gravity = Vec2f(0, m);
        mover->applyForce(gravity);

        mover->update();
        mover->checkEdges();
    }
}

void Example5App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    liquid->draw();
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example5App, RendererGl )
