#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example11App : public AppBasic {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover *mMover;
    vector<MoverRef> mMovers;
};

void Example11App::setup()
{
    Rand::randomize();
    for (int i = 0; i < 20; i++) {
        mMovers.push_back( MoverRef(new Mover()) );
    }
}

void Example11App::prepareSettings(Settings *settings) {
    settings->setWindowSize(600, 400);
    settings->setFrameRate(60);
    settings->setTitle("Chapter 1 Example 11");
}

void Example11App::mouseMove(MouseEvent event) {
    for (auto mover : mMovers) {
        mover->setTarget(event.getPos());
    }
}

void Example11App::mouseDown( MouseEvent event )
{
}

void Example11App::update()
{
    for (auto mover : mMovers) {
        mover->update();
        mover->checkEdges();
    }
}

void Example11App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto mover : mMovers) {
        mover->draw();
    }
}

CINDER_APP_BASIC( Example11App, RendererGl )
