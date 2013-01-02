#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"
#include "Car.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise1App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<Car> *mCars;
};

void Exercise1App::setup()
{
    mCars->push_back( Car(Colorf(1, 0, 0), Vec2f(40, 40), 1.5) );
    mCars->push_back( Car(Colorf(0, 0, 1), Vec2f(170, 170), 2.3) );
}

void Exercise1App::mouseDown( MouseEvent event )
{
}

void Exercise1App::update()
{
    for (Car &car : *mCars) {
        car.move();
    }
}

void Exercise1App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    for (Car &car : *mCars) {
        car.display();
    }
}

CINDER_APP_BASIC( Exercise1App, RendererGl )
