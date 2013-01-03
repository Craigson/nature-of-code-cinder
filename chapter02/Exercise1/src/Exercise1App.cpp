#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Balloon.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise1App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Balloon *mBalloon;
    Perlin mPerlin;
    Vec2f mOffset;
};

void Exercise1App::setup()
{
    mBalloon = new Balloon();
    mOffset = Vec2f(0.0f, 1000.0f);
}

void Exercise1App::mouseDown( MouseEvent event )
{
}

void Exercise1App::update()
{
    mBalloon->checkEdges();

    Vec2f helium = Vec2f(0, -0.002);
    mBalloon->applyForce(helium);
    
    float windAmt = lmap(mPerlin.fBm(mOffset), -1.0f, 1.0f, -0.01f, 0.01f);
    Vec2f wind = Vec2f(windAmt, 0);
    mBalloon->applyForce(wind);
    
    mBalloon->update();
    
    mOffset += 0.001;
}

void Exercise1App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    mBalloon->draw();
}

CINDER_APP_BASIC( Exercise1App, RendererGl )
