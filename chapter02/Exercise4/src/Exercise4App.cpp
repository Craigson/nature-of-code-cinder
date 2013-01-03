#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "FrictionSurface.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise4App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    
    vector<Mover*> mMovers;
    int mNumMovers;
    
    vector<FrictionSurface*> mSurfaces;
    int mNumSurfaces;
};

void Exercise4App::prepareSettings(Settings *settings) {
    settings->setFullScreen();
}

void Exercise4App::setup()
{
    Rand::randomize();
    
    mNumMovers = 20;
    int i = 0;
    while (i < mNumMovers) {
        mMovers.push_back(new Mover(randFloat(0.1, 5.0), randFloat(getWindowWidth()), randFloat(getWindowHeight())));
        i++;
    }
    
    mNumSurfaces = 10;
    int j = 0;
    while (j < mNumSurfaces) {
        mSurfaces.push_back(new FrictionSurface());
        j++;
    }
}

void Exercise4App::update()
{
    Vec2f wind = Vec2f(0.05, 0);
    for (auto mover : mMovers) {
        for (auto surface : mSurfaces) {
            surface->update(mover);
        }
        
        mover->applyForce(wind);
        
        Vec2f gravity = Vec2f(0, 0.1 * mover->mMass);
        mover->applyForce(gravity);

        mover->update();
        mover->checkEdges();
    }
}

void Exercise4App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
    
    for (auto surface : mSurfaces) {
        surface->draw();
    }
}

CINDER_APP_BASIC( Exercise4App, RendererGl )
