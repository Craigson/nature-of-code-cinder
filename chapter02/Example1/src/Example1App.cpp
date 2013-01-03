#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example1App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    vector<Mover*> mMovers;
    int mNumMovers;
};

void Example1App::setup()
{
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(0.1, 5.0), randFloat(getWindowWidth()), randFloat(getWindowHeight())));
        i++;
    }
}

void Example1App::update()
{
    for (auto mover : mMovers) {
        mover->update();
        mover->checkEdges();
    }
}

void Example1App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example1App, RendererGl )
