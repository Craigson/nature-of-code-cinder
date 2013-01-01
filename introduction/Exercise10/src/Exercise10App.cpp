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
    
    CameraPersp mCam;
    Vec3f mEye, mCenter, mUp;
    params::InterfaceGl mParams;
    Quatf mSceneRotation;
    float   mCameraDistance;
    LandscapeRef mLand;
};

void Exercise10App::setup()
{
    mCam.setPerspective( 60.0f, getWindowAspectRatio(), 5.0f, 3000.0f );
    
    mEye        = Vec3f( 0.0f, 0.0f, 500.0f );
    mCenter     = Vec3f::zero();
    mUp         = Vec3f::yAxis();
    
    mCam.lookAt( mEye, mCenter, mUp );
    gl::setMatrices( mCam );
    
    mParams = params::InterfaceGl( "Perlin", Vec2i( 225, 200 ) );
    mParams.addParam( "Scene Rotation", &mSceneRotation );
    mParams.addParam( "Eye Distance", &mCameraDistance, "min=50.0 max=1500.0 step=50.0 keyIncr=s keyDecr=w" );
    
    gl::rotate( mSceneRotation );
    
    // Create a landscape object
    mLand = LandscapeRef( new Landscape(20, getWindowWidth(), getWindowHeight()) );
}

void Exercise10App::mouseDown( MouseEvent event )
{
}

void Exercise10App::update()
{
    // UPDATE CAMERA
	mEye = Vec3f( 0.0f, 0.0f, mCameraDistance );
	mCam.lookAt( mEye, mCenter, mUp );
	gl::setMatrices( mCam );
	gl::rotate( mSceneRotation );
    mLand->update();
}

void Exercise10App::draw()
{
	gl::clear( Color( 0, 0, 0 ), true );
	gl::enableDepthRead();
	gl::enableDepthWrite();
    
//    gl::color(0, 0.5, 0.5);
//    gl::drawSphere(Vec3f(5.0f, 5.0f, 5.0f), 16);
    
    mLand->draw();
    
    // DRAW PARAMS WINDOW
	params::InterfaceGl::draw();
}

CINDER_APP_BASIC( Exercise10App, RendererGl )
