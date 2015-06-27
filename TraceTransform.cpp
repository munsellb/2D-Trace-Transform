#include "TraceTransform.h"
#include "MatrixWriter.h"


//**********************************
//	Constructor
//
//
//**********************************

TraceTransform::TraceTransform() {

	numAngles = 180;

	traceMat = NULL;
	traceLine = NULL;

	functional = 0;
	traceFile = "";
	
	rhoVector.clear();

} // end constructor


//**********************************
//	Destructor
//
//
//**********************************

TraceTransform::~TraceTransform() {

	dispose( traceMat );

} // end destructor


// ----------------------------------------------
// METHOD: void TraceTransform::initialize()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceTransform::initialize() {

    image.printSelf();

    int temp1 = 0; 
    int temp2 = 0; 

    temp1 = image.getNumberOfRows() - 1 - image.getYOrigin();
    temp2 = image.getNumberOfColumns() - 1 - image.getXOrigin();

    /*temp1 = image.getNumberOfRows() - image.getYOrigin();
    temp2 = image.getNumberOfColumns() - image.getXOrigin();*/

    rLast = (int) ceil(sqrt((double)(temp1*temp1+temp2*temp2))) + 1;
    rFirst = -rLast;
    rSize = rLast - rFirst + 1;

    std::cout<<"rFirst = "<<rFirst<<std::endl;
    std::cout<<"rLast = "<<rLast<<std::endl;

    traceLine = new TraceLine( rFirst , rLast );
    traceLine->setTraceImage( &image );
    traceLine->init();

    for ( int t=0; t < rSize; t++ ) {

      rhoVector.push_back( (double) ( rFirst + t ) );
      //std::cout<<"rhovec["<<t<<"] = "<<rhoVector.back()<<std::endl;

    }

} // end initialize() method


// ----------------------------------------------
// METHOD: void TraceTransform::calculate()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceTransform::calculate() {

    dispose( traceMat );

    traceMat = cvCreateMat( rSize, numAngles, CV_64F );
    cvSetZero( traceMat );

    for ( int k = 0; k < numAngles; k++ ) {

	//std::cout<<" angle = "<<k<<std::endl;

	for ( int r = 0; r < rhoVector.size() ; r++ ) {

	    traceLine->setAngle(  ( (double) k ) );
	    traceLine->setDistance( rhoVector.at( r ) );
	    traceLine->build();

	    switch( functional ) {

		    case RADON:

			    traceLine->calculateRadon();
			    break;

		    case T3:

			    traceLine->calculateT3();
			    break;

		    case T20:

			    traceLine->calculateT20();
			    break;

	    }

	    cvSetAt( traceMat , cvScalar( traceLine->getCalculatedValue() ) , (unsigned int) r , (unsigned int) k );

	}

    }

    MatrixWriter writer;
    writer.writeMatrix( traceFile, traceMat );

} // end calculate() method



// ----------------------------------------------
// METHOD: void TraceTransform::setImage( std::string m_imageFile , bool m_isRGB, bool m_histeq )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceTransform::setImage( std::string m_imageFile , bool m_isRGB, bool m_histeq ) {

	image.setImage( m_imageFile, m_isRGB, m_histeq );

} // end setImage() method


// ----------------------------------------------
// METHOD: void TraceTransform::dispose( CvMat* matrix )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceTransform::dispose( CvMat* matrix ) {

	if ( matrix != NULL ) {

		cvReleaseMat( &matrix );

	}

} // end dispose() method