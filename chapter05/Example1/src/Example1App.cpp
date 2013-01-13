#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2D/Box2d.h>
#include "Box.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example1App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<Box*> mBoxes;
    
    b2Vec2 gravity = b2Vec2(0.0f, 3.0f);
    b2World mWorld = b2World(gravity);
};

void Example1App::setup()
{

}

void Example1App::mouseDown( MouseEvent event )
{
    Box *box = new Box(event.getPos().x, event.getPos().y, mWorld);
    mBoxes.push_back(box);
}

void Example1App::update()
{
    float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
    
    mWorld.Step(timeStep, velocityIterations, positionIterations);
    for (auto b : mBoxes) {
        b->update();
    }
}

void Example1App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    // Display all the boxes
    for (auto b: mBoxes) {
        b->draw();
    }
}

CINDER_APP_NATIVE( Example1App, RendererGl )
