#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Snake.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EcosystemApp : public AppBasic {
  public:
	void setup();
    void prepareSettings( Settings *settings );
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    
//    Snake *snake;
    vector<Snake*> mSnakes;
    int mNumSnakes;
};

void EcosystemApp::setup()
{
    mNumSnakes = 5;
    for (int i = 0; i < mNumSnakes; i++) {
        mSnakes.push_back(new Snake());
    }
    Rand::randomize();
}

void EcosystemApp::prepareSettings(Settings *settings) {
    settings->setFrameRate(60.0f);
    settings->setFullScreen();
}

void EcosystemApp::mouseDown( MouseEvent event )
{
}

void EcosystemApp::mouseMove( MouseEvent event )
{
    for (auto snake : mSnakes) {
        snake->setTarget(event.getPos());
    }
}

void EcosystemApp::mouseDrag( MouseEvent event )
{
    mouseMove(event);
}

void EcosystemApp::update()
{
    for (auto snake : mSnakes) {
        snake->update();
    }
}

void EcosystemApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto snake : mSnakes) {
        snake->draw();
    }
}

CINDER_APP_BASIC( EcosystemApp, RendererGl )
