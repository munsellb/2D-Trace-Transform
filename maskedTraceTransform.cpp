#include <iostream>
#include <time.h>

#include "argio.hh"
#include "TraceTransform.h"

#define MAIN_DEBUG 1

int main(int argc, const char *argv[]) {

	float diff = 0;
	clock_t t1, t2;

	TraceTransform traceTransform;

	std::string inputImageFile;
	std::string outputTraceFile;
	std::string maskFile;

	unsigned int functional = 0;

	bool histeq = false;
	bool color = false;

	//std::cout<<"size of argc = "<<argc<<std::endl;

	if ( argc != 11 ) {

		std::cout<<""<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<"Masked Trace Transform requires 6 arguments!"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<"-------------------------------------------"<<std::endl;
		std::cout<<"Usage: Masked TraceTransform -input -output -func -histeq -color -mask"<<std::endl;
		std::cout<<"-------------------------------------------"<<std::endl;
		std::cout<<"args:  -input	  <path to input image>"<<std::endl;
		std::cout<<"       -output	  <path to output trace .dat file>"<<std::endl;
		std::cout<<"       -func	  <trace functional (0=radon, 1=T3, 2=T20)>"<<std::endl;
		std::cout<<"       -histeq	  <histogram equalization ( 0=no 1=yes )>"<<std::endl;
		std::cout<<"       -color	  <input image is color ( 0=no 1=yes)>"<<std::endl;
		std::cout<<"       -mask	  <mask file>"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<"ex:  TraceTransform -input image.jpg -output trace.dat -func 0 -histeq 1 -color 1 -mask mask.dat"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<""<<std::endl;
		return -1;

  	}

	char* truth = ipGetStringArgument(argv, "-input", NULL);
	char* derived = ipGetStringArgument(argv, "-output", NULL);
	char* mask = ipGetStringArgument(argv, "-mask", NULL);

	inputImageFile.assign( truth );
	outputTraceFile.assign( derived );
	maskFile.assign( mask );

	if ( ipGetIntArgument( argv, "-histeq", 0 ) == 1 ) histeq = true;
	if ( ipGetIntArgument( argv, "-color", 0 ) == 1 ) color = true;

	functional = (unsigned int)ipGetIntArgument( argv, "-func", 0 );
		
	if ( MAIN_DEBUG ) {

	    std::cout<<""<<std::endl;
	    std::cout<<"-----------------------"<<std::endl;
	    std::cout<<" Input Parameters "<<std::endl;
	    std::cout<<"-----------------------"<<std::endl;
	    std::cout<<"input = "<<inputImageFile<<std::endl;
	    std::cout<<"output = "<<outputTraceFile<<std::endl;
	    std::cout<<"mask = "<<maskFile<<std::endl;
	    
	    if ( functional == RADON ) std::cout<<"functional == RADON"<<std::endl;
	    else if ( functional == T3 ) std::cout<<"functional == T3"<<std::endl;
	    else if ( functional == T20 ) std::cout<<"functional == T20"<<std::endl;

	    if ( histeq ) std::cout<<"histeq = true"<<std::endl;
	    else std::cout<<"histeq = false"<<std::endl;

	    if ( color ) std::cout<<"color = true"<<std::endl;
	    else std::cout<<"color = false"<<std::endl;
	    std::cout<<""<<std::endl;

	}
	
	t1 = clock();

	traceTransform.setImage( inputImageFile, color, histeq );
	traceTransform.setTraceFile( outputTraceFile );
	traceTransform.setMaskFile( maskFile );
	traceTransform.initialize();

	if ( functional == RADON ) {

		traceTransform.setFuntional( RADON );

	}
	else if ( functional == T3 ) {

		traceTransform.setFuntional( T3 );

	}
	else {

		traceTransform.setFuntional( T20 );

	}

	traceTransform.calculate();

	t2 = clock();

	diff = ((float)t2 - (float)t1) / 1000.0;

	std::cout<<"running time (sec) = "<<diff<<std::endl;

	return 0;

} // end main() method