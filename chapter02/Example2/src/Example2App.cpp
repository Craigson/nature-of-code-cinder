#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example2App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    vector<Mover*> mMovers;
    int mNumMovers;
};

void Example2App::setup()
{
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(0.1, 5.0), randFloat(getWindowWidth()), randFloat(getWindowHeight())));
        i++;
    }
}

void Example2App::update()
{
    Vec2f gravity = Vec2f(0, 0.2);
    Vec2f wind = Vec2f(0.05, 0);
    for (auto mover : mMovers) {
        mover->applyForce(gravity);
        mover->applyForce(wind);
        mover->update();
        mover->checkEdges();
    }
}

void Example2App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example2App, RendererGl )
