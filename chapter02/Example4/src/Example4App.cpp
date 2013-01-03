#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example4App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    vector<Mover*> mMovers;
    int mNumMovers;
};

void Example4App::setup()
{
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(0.1, 5.0), randFloat(getWindowWidth()), randFloat(getWindowHeight())));
        i++;
    }
}

void Example4App::update()
{
    Vec2f wind = Vec2f(0.05, 0);
    for (auto mover : mMovers) {
        mover->applyForce(wind);
        
        float c = 0.01;
        Vec2f friction = mover->mVelocity;
        friction *= -1;
        friction.safeNormalize();
        friction *= c;
        mover->applyForce(friction);
        
        Vec2f gravity = Vec2f(0, 0.1 * mover->mMass);
        mover->applyForce(gravity);

        mover->update();
        mover->checkEdges();
    }
}

void Example4App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example4App, RendererGl )
