#include "Histogram.h"



//**********************************
//	Constructor
//
//
//**********************************

Histogram::Histogram() {

} // end constructor


//**********************************
//	Destructor
//
//
//**********************************

Histogram::~Histogram() {

} // end destructor

// ----------------------------------------------
// METHOD: Histogram::calculate(vector <double> data, unsigned int numBins)
// CREATED:  01-13-2009
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void Histogram::calculate( std::vector <double> d, unsigned int m_numBins) {
	
	std::vector <double> bin_values;
	numBins = m_numBins;
	double value;

	std::vector<double> data = sort( d );
	
	// initialize bins to zero
	for (unsigned int i=0; i < numBins; i++) {

		bins.push_back( 0 );
		hist.push_back( bin_values);
	}
	
	minBinValue = (int) ( min( data ) );
	maxBinValue = (int) ( max( data ) + 0.50 );

	std::cout<<"max bin value = "<<maxBinValue<<std::endl;
	std::cout<<"min bin value = "<<minBinValue<<std::endl;
	
	binWidth = (int) ( ( ( maxBinValue - minBinValue ) / ((double)numBins) ) + 0.50 );
	
	if ( binWidth == 0 ) binWidth = 1;
	
	// populate hist with triangle data
	for (unsigned int h=0; h<data.size(); h++)  {

		value = data.at(h);
		
		for (unsigned int b=0; b<bins.size(); b++)  {

			if (b==0) {

				if ( value < ( (double) ( minBinValue + binWidth ) ) )  {

					bins.at(b)++;
					hist.at(b).push_back(value);
					break;
				}

			}
			else{
				if ( ( value >= ( (double) ( minBinValue + ( b*binWidth )))) &&  ( value < ( (double) ( minBinValue + ( ( b+1 )*binWidth ))))) {

					bins.at(b)++;
					hist.at(b).push_back(value);
					break;

				}

			}

		}

	}


} //End of CalcHist() method

// ----------------------------------------------
// METHOD: int Histogram::peakBin()
// CREATED:  01-13-2009
// DESCRIPTION: 
//
//.
//
//
// TODO:
//
int Histogram::getPeakBin() {

	unsigned int mx = max( bins );

	for ( unsigned int i=0; i<bins.size(); i++ ) {

		if ( bins.at(i) == mx ) return ( (int) i );

	}

	return -1;
		
} // end peakBin() method


// ----------------------------------------------
// METHOD: int Histogram::binValue( unsigned int binNumber )
// CREATED:  01-13-2009
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

double Histogram::getBinValue( unsigned int binNumber ) {

	double value = 0.0;

	value = (double) ( minBinValue + ( binWidth * binNumber ) );

	return value;
		
} // end binValue method



