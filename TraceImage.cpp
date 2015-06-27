#include "TraceImage.h"


//**********************************
//	Constructor
//
//
//**********************************

TraceImage::TraceImage() {
  
  hasMask = false;

} // end constructor


//**********************************
//	Destructor
//
//
//**********************************
TraceImage::~TraceImage() {

} // end destructor


// ----------------------------------------------
// METHOD: void TraceImage::setImage( std::string m_imageFile , bool m_isRGB, bool m_histeq )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceImage::setImage( std::string m_imageFile , bool m_isRGB, bool m_histeq ) {

    imageFile = m_imageFile;  
    isRGB = m_isRGB;
    histeq = m_histeq;

    load();

} // end setImage() method


// ----------------------------------------------
// METHOD: void TraceImage::setImage( std::string m_imageFile, std::string m_maskFile, bool m_isRGB, bool m_histeq )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceImage::setImage( std::string m_imageFile, std::string m_maskFile, bool m_isRGB, bool m_histeq ) {

    imageFile = m_imageFile;
    maskFile = m_maskFile;
    isRGB = m_isRGB;
    histeq = m_histeq;
    
    hasMask = true;

    load();

} // end setImage() method


// ----------------------------------------------
// METHOD: unsigned int TraceImage::getPixelValue( unsigned int m, unsigned int n )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

double TraceImage::getPixelValue( unsigned int m, unsigned int n ) {

    if ( inputImage != NULL ) {

	    return (double) cvGetAt( inputImage, m, n ).val[0];

    }
    else {

	    return 0.0;

    }

} // end getPixelValue() method

// ----------------------------------------------
// METHOD: void TraceImage::load()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceImage::load() {

    IplImage* rgb = NULL;
    IplImage* gray = NULL;
    IplImage* norm = NULL;

    if ( isRGB ) {

	    rgb = cvLoadImage( imageFile.c_str() , CV_LOAD_IMAGE_COLOR );

	    gray = cvCreateImage( cvGetSize( rgb ) , IPL_DEPTH_8U , 1 );

	    cvCvtColor( rgb , gray, CV_RGB2GRAY );

    }
    else {

	    gray = cvLoadImage( imageFile.c_str() , CV_LOAD_IMAGE_GRAYSCALE );

    }

    norm = cvCreateImage( cvSize( IMG_NORM , IMG_NORM ) , IPL_DEPTH_8U , 1 );
    cvResize( gray , norm );

    if ( histeq ) {

	    inputImage = cvCreateImage( cvGetSize( norm ) , IPL_DEPTH_8U , 1 );

	    cvEqualizeHist( norm , inputImage );

    }
    else {

	    inputImage = cvCloneImage( norm );

    }

    dispose( rgb );
    dispose( gray );
    dispose( norm );

    M = inputImage->height;
    N = inputImage->width;

    xOrigin = (int)( (N-1)/2 );
    yOrigin = (int)( (M-1)/2 );

    /*xOrigin = (int)( N/2 );
    yOrigin = (int)( M/2 );*/

    if ( LOAD_IMG_DEBUG ) cvSaveImage( "imgNorm.jpg",inputImage );

} // end loadImage() method


// ----------------------------------------------
// METHOD: void TraceImage::dispose( IplImage* image )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceImage::dispose( IplImage* image ) {

    if ( image != NULL ) {

	    cvReleaseImage( &image );

    }

} // end dispose() method


// ----------------------------------------------
// METHOD: void TraceImage::printSelf()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceImage::printSelf() {

    std::cout<<"M = "<<M<<std::endl;
    std::cout<<"N = "<<N<<std::endl;

    std::cout<<"xOrigin = "<<xOrigin<<std::endl;
    std::cout<<"yOrigin = "<<yOrigin<<std::endl;

} // end printSelf() method
