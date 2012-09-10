#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
#include "cinder/Perlin.h"
#include "cinder/params/Params.h"
#include "cinder/gl/Fbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise9App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    Perlin perlin_;
    Channel clouds_;
    gl::Texture cloudsTex_;
    
    float xoff_;
    float yoff_;
    float zoff_;
};

void Exercise9App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    clouds_ = Channel(getWindowWidth(), getWindowHeight());
    cloudsTex_ = gl::Texture(getWindowWidth(), getWindowHeight());
    
    xoff_ = 0.0f;
    yoff_ = 0.0f;
    zoff_ = 0.0f;
}

void Exercise9App::update()
{
    xoff_ = 0.0f;
    Channel::Iter iter = clouds_.getIter();
    while (iter.line()) {
        yoff_ = 0.0f;
        while (iter.pixel()) {
            float noiseOutput = perlin_.noise(xoff_, yoff_, zoff_);
            float brightness = lmap(noiseOutput, -1.0f, 1.0f, 0.0f, 255.0f);
            iter.v() = brightness;
            
            yoff_ += 0.01;
        }
        xoff_ += 0.01;
    }
    zoff_ += 0.1;
    cloudsTex_.update(clouds_, getWindowBounds());
}

void Exercise9App::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    gl::draw(cloudsTex_);
}

CINDER_APP_BASIC( Exercise9App, RendererGl )
