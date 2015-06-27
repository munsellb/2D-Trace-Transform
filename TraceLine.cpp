#include "TraceLine.h"
#include <math.h>


//**********************************
//	Constructor
//
//
//**********************************

TraceLine::TraceLine( int m_tfirst, int m_tlast ) {

    line = NULL;
    trace = NULL;

    increment = 2;

    PIX_FRAC = 0.25;

    pos = 0;
    rho = 0;
    phi = 0;

    t_first = m_tfirst;
    t_last = m_tlast;

    deg2rad = PI/180.0;
    rightAngle = 90.0 * PI/180.0;

} // end constructor


//**********************************
//	Destructor
//
//
//**********************************

TraceLine::~TraceLine() {

} // end destructor


// ----------------------------------------------
// METHOD: void TraceLine::dispose()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::dispose() {

    if ( line != NULL ) {
	    
      free(line);

    }

    if ( trace != NULL ) {
	    
      free(trace);

    }

} // end dispose() method


// ----------------------------------------------
// METHOD: void TraceLine::init()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::init() {

    dispose();

    double incf = 1.0 /  ( (double) increment );

    pos = ( t_last - t_first ) * increment + 1;

    trace = (double*)calloc( pos, sizeof(double) );
    line = (double*)calloc( pos, sizeof(double) );

    for ( int t=0; t<pos; t++ ) {

      trace[t] = t_first + incf*( (double)t );
      //std::cout<<"trace["<<t<<"] = "<<trace[t]<<std::endl;

    }

} // end init() method


// ----------------------------------------------
// METHOD: void TraceLine::build()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::build() {

    rad = phi * deg2rad;

    cosine = cos( rad );
    sine = sin( rad );

    tcosine = cos( rad + rightAngle );
    tsine = sin( rad + rightAngle );

    double x_r = rho * cosine;
    double y_r = rho * sine;

    double x_t = 0.0;
    double y_t = 0.0;

    int n = 0;
    int m = 0;

    for ( int t=0; t<pos; t++ ) {

      x_t = trace[t]*tcosine + x_r + image->getXOrigin() + 0.5;
      y_t = trace[t]*tsine + y_r + image->getYOrigin() + 0.5;

      n = (int) floor( x_t );
      m = (int) floor( y_t );

      if ( n >= 0 && n < image->getNumberOfColumns() ) {

	if ( m >= 0 && m < image->getNumberOfRows() ) {

	  line[t] = image->getPixelValue( m , n );

	}
	else {

	  line[t] = 0.0;

	}

      }
      else {

	line[t] = 0.0;

      }

    }

} // end build() method


// ----------------------------------------------
// METHOD: void TraceLine::calculateRadon()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::calculateRadon() {

    calculatedValue = 0.0;

    for ( int i=0; i<pos; i++ ) {

      calculatedValue += line[i];

    }

} // end calculateRadon() method


// ----------------------------------------------
// METHOD: void TraceLine::calculateT3()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::calculateT3() {

    double tmp = 0.0;
    calculatedValue = 0.0;

    for ( int i=0; i<pos; i++ ) {

      tmp += pow( line[i] , 4.0 ) ;

    }

    calculatedValue = pow( tmp , 0.25 );

} // end calculateT3() method


// ----------------------------------------------
// METHOD: void TraceLine::calculateT20()
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void TraceLine::calculateT20() {

    double c = 0.0;
    double S = 0.0;
    int c_i = 0;

    calculateRadon();
    S = calculatedValue;

    if ( S > 0.0 ) {

      for ( int i=0; i<pos; i++ ) {

	c += line[i] * ( i + 1 );

      }

      c_i = (int) floor( ( ( c / S ) + 0.5 ) );

      calculatedValue = 0.0;

      for ( int i=c_i; i<pos; i++ ) {

	calculatedValue += pow( ( (double)( i - c_i ) ) , 0.5 ) * line[i];

      }

    }

} // end calculateT20() method
