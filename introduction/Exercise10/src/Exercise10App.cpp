#include "boost/multi_array.hpp"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/params/Params.h"
#include "cinder/Perlin.h"
#include "Landscape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise10App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    LandscapeRef mLand;
    float mTheta;
};

void Exercise10App::setup()
{
    mLand = LandscapeRef( new Landscape(12  , getWindowWidth(), getWindowHeight()) );
    mTheta = 0.0f;
}

void Exercise10App::mouseDown( MouseEvent event )
{
}

void Exercise10App::update()
{
    mLand->update();
}

void Exercise10App::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
	//gl::enableWireframe();
    
	glPushMatrix();
	gl::translate( (float)getWindowWidth() / 2, (float)getWindowHeight() / 2 + 20, -160 );
    
	float xRot = toDegrees( M_PI/3 );
	float zRot = toDegrees( mTheta );
	gl::rotate( Vec3f( xRot, 0, zRot ) );
	mLand->draw();
	glPopMatrix();
    
	mTheta += 0.0025;
}

CINDER_APP_BASIC( Exercise10App, RendererGl )
