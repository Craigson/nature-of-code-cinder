#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example3App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    vector<Mover*> mMovers;
    int mNumMovers;
};

void Example3App::setup()
{
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(0.1, 5.0), randFloat(getWindowWidth()), randFloat(getWindowHeight())));
        i++;
    }
}

void Example3App::update()
{
    Vec2f wind = Vec2f(0.05, 0);
    for (auto mover : mMovers) {
        mover->applyForce(wind);
        
        Vec2f gravity = Vec2f(0, 0.1 * mover->mMass);
        mover->applyForce(gravity);

        mover->update();
        mover->checkEdges();
    }
}

void Example3App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example3App, RendererGl )
