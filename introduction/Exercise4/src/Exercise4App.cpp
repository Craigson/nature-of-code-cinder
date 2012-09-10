#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise4App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Rand generatorX;
    Rand generatorY;
    Rand generatorColor;
    params::InterfaceGl params_;
    float stdDev = 60;
};

void Exercise4App::setup()
{
    setFullScreen(true);
    gl::clear( Color( 0, 0, 0 ) );
    gl::enableAlphaBlending();
    
    generatorX.seed(randInt());
    generatorY.seed(randInt());
    generatorColor.seed(randInt());
    
    params_ = params::InterfaceGl( "Paint Splatter", Vec2i( 250, 200 ) );
    params_.addParam("Spacial Std Deviation", &stdDev, "min=0 max=300.0 step=5");
}

void Exercise4App::mouseDown( MouseEvent event )
{
}

void Exercise4App::update()
{
}

void Exercise4App::draw()
{
    gl::color(0, 0, 0, 0.05);
    gl::drawSolidRect(Rectf(Vec2f(0, 0), Vec2f(getWindowWidth(), getWindowHeight())));
    
    float numX = generatorX.nextGaussian();
    float meanX = getWindowCenter().x;
    float x = stdDev * numX + meanX;
    
    float numY = generatorY.nextGaussian();
    float meanY = getWindowCenter().y;
    float y = stdDev * numY + meanY;
  
    Color randColor = Color(ColorModel::CM_RGB, generatorColor.nextVec3f());
    Color randColorWithAlpha = ColorA(randColor,1.0);
    gl::color(randColorWithAlpha);
    gl::drawSolidCircle(Vec2f(x, y), 16);
    
    params::InterfaceGl::draw();
}

CINDER_APP_BASIC( Exercise4App, RendererGl )
