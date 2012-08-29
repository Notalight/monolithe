#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ip/Fill.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"

#include "CinderOpenCv.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class monolitheApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );
	void update();
	void draw();
    
    cairo::Context mCtx;
	Surface32f mCairoSurface;

	gl::Texture	mTexture;
};

void monolitheApp::setup()
{
	mCtx = cairo::Context(cairo::createWindowSurface());

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

void monolitheApp::keyDown( KeyEvent event )
{
	if( event.getCode() == KeyEvent::KEY_f ) {
		setFullScreen( ! isFullScreen() );
	}
/*	else if( event.getChar() == 'x' ) {
		mFlowers.clear();
	}
	else if( event.getChar() == 's' ) {
		cairo::Context ctx( cairo::SurfaceSvg( getHomeDirectory() / "CairoBasicShot.svg", getWindowWidth(), getWindowHeight() ) );
		renderScene( ctx );
	}
	else if( event.getChar() == 'e' ) {
		cairo::Context ctx( cairo::SurfaceEps( getHomeDirectory() / "CairoBasicShot.eps", getWindowWidth(), getWindowHeight() ) );
		renderScene( ctx );
	}
	else if( event.getChar() == 'p' ) {
		cairo::Context ctx( cairo::SurfacePs( getHomeDirectory() / "CairoBasicShot.ps", getWindowWidth(), getWindowHeight() ) );
		renderScene( ctx );
	}	
	else if( event.getChar() == 'd' ) {
		cairo::Context ctx( cairo::SurfacePdf( getHomeDirectory() / "CairoBasicShot.pdf", getWindowWidth(), getWindowHeight() ) );
		renderScene( ctx );
	}*/	
}

void monolitheApp::update()
{
}

void monolitheApp::draw()
{
	// render the scene straight to the window
	cairo::Context ctx( cairo::createWindowSurface() );	

	// clear the screen
	ctx.setSourceRgb( 0.2f, 0.2f, 0.2f );
	ctx.paint();

	ctx.setSourceRgb( 0.5f, 0.75f, 1.0f );
	//ctx.setSource(Color( 0.6, 0.0, 0.0 ));
	ctx.rectangle(0,0,20,20);
	ctx.fill();
	//mCtx.paint() ;
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
    //gl::draw( mTexture );
}




CINDER_APP_BASIC( monolitheApp, Renderer2d )
