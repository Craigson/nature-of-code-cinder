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
    for(int i = 0; i < mNumMovers; i++) {
        mMovers.push_back( new Mover(randFloat(1, 10), randFloat(getWindowWidth()), randFloat(getWindowHeight())) ) ;
    }
}

void Example2App::update()
{
    for (auto mover : mMovers) {
        mover->update();
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
