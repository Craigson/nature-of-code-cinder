#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Example2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<int> randomCounts_;
};

void Example2App::setup()
{
    for(int i = 0; i < 20; i++) {
        randomCounts_.push_back(0);
    }
}

void Example2App::mouseDown( MouseEvent event )
{
}

void Example2App::update()
{
    int index = randInt(randomCounts_.size());
    randomCounts_[index]++;
}

void Example2App::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    
    int w = app::getWindowWidth() / randomCounts_.size();
    for (int x = 0; x < randomCounts_.size(); x++) {
        Rectf bar = Rectf(x*w, app::getWindowHeight() - randomCounts_[x], x*w + 30, app::getWindowHeight());
        gl::color(0.75f, 0.75f, 0.75f);
        gl::drawSolidRect( bar );
        gl::color(0.0f, 0.0f, 0.0f);
        gl::drawStrokedRect( bar );

    }
}

CINDER_APP_BASIC( Example2App, RendererGl )
