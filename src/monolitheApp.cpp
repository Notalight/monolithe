#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class monolitheApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void monolitheApp::setup()
{
}

void monolitheApp::mouseDown( MouseEvent event )
{
}

void monolitheApp::update()
{
}

void monolitheApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}


CINDER_APP_BASIC( monolitheApp, RendererGl )
