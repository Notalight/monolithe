#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "CinderOpenCv.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class monolitheApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    
	gl::Texture	mTexture;
};

void monolitheApp::setup()
{
	ci::Surface8u surface( loadImage( loadResource( RES_MY_RES ) ) );
	cv::Mat input( toOcv( surface ) );
	cv::Mat output;
    
	//cv::medianBlur( input, output, 11 );
    cv::Sobel( input, output, CV_8U, 0, 1 );
    //cv::threshold( input, output, 128, 255, CV_8U );
    
	mTexture = gl::Texture( fromOcv( output ) );

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
    gl::draw( mTexture );
}


CINDER_APP_BASIC( monolitheApp, RendererGl )
