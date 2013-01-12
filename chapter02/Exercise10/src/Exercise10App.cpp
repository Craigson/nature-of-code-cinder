#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise10App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    void prepareSettings(Settings *settings);
    void mouseMove(MouseEvent event);
    
    vector<MoverRef> mMovers;
    Vec2f mMousePosition;
};

void Exercise10App::prepareSettings(Settings *settings) {
    settings->setWindowSize(800, 600);
}

void Exercise10App::mouseMove(MouseEvent event) {
    mMousePosition = (Vec2f)event.getPos();
}

void Exercise10App::setup()
{
    int numMovers = 10;
    for (int i = 0; i < numMovers; i++) {
        auto m = MoverRef( new Mover(randFloat(0.5, 3), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
        mMovers.push_back(m);
    }
    mMousePosition = Vec2f::zero();
    gl::clear( Color( 1, 1, 1 ) );
}

void Exercise10App::update()
{
    for (auto mover : mMovers) {
        for (auto repellingMover : mMovers) {
            if (mover != repellingMover) {
                Vec2f force = repellingMover->repel(mover);
                mover->applyForce(force);
            }
        }
        Vec2f mouseForce = mover->attract(mMousePosition);
        mover->applyForce(mouseForce);
        mover->update();
    }
}

void Exercise10App::draw()
{
    gl::enableAlphaBlending();
    gl::color(1, 1, 1, 0.02);
    gl::drawSolidRect(Rectf(getWindowBounds()));
    for (auto mover : mMovers) {
        mover->draw();
    }
    gl::disableAlphaBlending();

}

CINDER_APP_BASIC( Exercise10App, RendererGl )
