#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Snake.h"
#include "Food.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EcosystemApp : public AppBasic {
  public:
	void setup();
    void prepareSettings( Settings *settings );

	void update();
	void draw();
    
    vector<SnakeRef> mSnakes;
    int mNumSnakes;
    
    vector<FoodRef> mFoodBalls;
    int mNumFoodBalls;
};

void EcosystemApp::setup()
{
    Rand::randomize();
    
    mNumSnakes = randInt(2, 10);
    for (int i = 0; i < mNumSnakes; i++) {
        mSnakes.push_back( SnakeRef( new Snake() ) );
    }
    
    mNumFoodBalls = randInt(1, 5);
    for (int i = 0; i < mNumFoodBalls; i++) {
        mFoodBalls.push_back( FoodRef( new Food() ) );
    }
}

void EcosystemApp::prepareSettings(Settings *settings) {
    settings->setFrameRate(60.0f);
    settings->setFullScreen();
}


void EcosystemApp::update()
{
    for (auto snake : mSnakes) {
        for (auto food : mFoodBalls) {
            Vec2f attraction = food->attract(snake);
            snake->applyForce(attraction);
            
            if (snake->isTouchingFood(food)) {
                snake->eat(food);
            }
        }
        snake->update();
    }
}

void EcosystemApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    for (auto food : mFoodBalls) {
        food->draw();
    }
    
    for (auto snake : mSnakes) {
        snake->draw();
    }
}

CINDER_APP_BASIC( EcosystemApp, RendererGl )
