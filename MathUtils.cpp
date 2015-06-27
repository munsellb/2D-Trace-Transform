#include "MathUtils.h"
#include <stdio.h>
#include <string>


//**********************************
//	Constructor
//
//
//**********************************

MathUtils::MathUtils() {

} // end constructor


//**********************************
//	Constructor
//
//
//**********************************

MathUtils::~MathUtils() {

} // end destructor


// ----------------------------------------------
// METHOD: double MathUtils::precision( double value, std::string fmt )
// CREATED:  04-27-2010
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

double MathUtils::precision( double value, std::string fmt ) {

	char buffer[1000];

	sprintf( buffer, fmt.c_str(), value );

	return atof( buffer );

} // end precision() method



double MathUtils::sum( std::vector<double> values ) {

	double sum = 0.0;

	for (unsigned int i=0; i<values.size(); i++) {

		sum += values.at(i);

	}

	return sum;
}
		


int MathUtils::sum( std::vector<int> values ) {

	int sum = 0;

	for (unsigned int i=0; i<values.size(); i++) {

		sum += values.at(i);

	}

	return sum;

}



		
double MathUtils::variance( std::vector<double> values , bool unbiased ) {

	double var = 0.0;

	if ( !values.empty() ) {

		double m = mean( values, unbiased );
	
		for (unsigned int i=0; i<values.size(); i++) {
	
			var += ( values.at(i) - m ) * ( values.at(i) - m );
		
		}

		if ( unbiased ) {

			var = var / ( (double)values.size() - 1.0 );

		}
		else {

			var = var / ( (double)values.size() );

		}

	}

	return var;

}


double MathUtils::variance( std::vector<double> values , std::vector<unsigned int> idx, bool unbiased ) {

	double var = 0.0;

	if ( !values.empty() ) {

		double m = mean( values, idx, unbiased );
	
		for (unsigned int i=0; i<idx.size(); i++) {
	
			var += ( values.at( idx.at(i) ) - m ) * ( values.at( idx.at(i) ) - m );
		
		}

		if ( unbiased ) {

			var = var / ( (double) idx.size() - 1.0 );

		}
		else {

			var = var / ( (double) idx.size() );

		}

	}

	return var;

}



double MathUtils::variance( std::vector<int> values , bool unbiased ) {

	double var = 0.0;

	if ( !values.empty() ) {

		double m = mean( values, unbiased );
	
		for (unsigned int i=0; i<values.size(); i++) {
	
			var += ( ( (double) values.at(i) ) - m ) * ( ( (double) values.at(i) ) - m );
		
		}

		if ( unbiased ) {

			var = var / ( (double)values.size() - 1.0 );

		}
		else {

			var = var / ( (double)values.size() );

		}

	}

	return var;

}


double MathUtils::variance( std::vector<int> values , std::vector<unsigned int> idx, bool unbiased ) {

	double var = 0.0;

	if ( !values.empty() ) {

		double m = mean( values, idx, unbiased );
	
		for (unsigned int i=0; i<idx.size(); i++) {
	
			var += ( values.at( idx.at(i) ) - m ) * ( values.at( idx.at(i) ) - m );
		
		}

		if ( unbiased ) {

			var = var / ( (double) idx.size() - 1.0 );

		}
		else {

			var = var / ( (double) idx.size() );

		}

	}

	return var;

}




double MathUtils::mean ( std::vector<double> values , bool unbiased ) {

	double mean = 0.0;

	if ( !values.empty() ) {

		for (unsigned int i=0; i<values.size(); i++) {
	
			mean += values.at(i);
	
		}
	
		if ( unbiased ) {
	
			mean = mean / ( (double) values.size() - 1.0 );
	
		}
		else {
	
	
			mean = mean / ( (double) values.size() );
	
		}

	}

	return mean;

}

double MathUtils::median ( std::vector<double> values , bool unbiased ) {

	if ( values.size() > 2 ) {

		std::vector<double> dd = sort( values );
		unsigned int size = dd.size();
		unsigned int index = 0;
	
		if ( size % 2 == 0 ) {
	
			double a1 = dd.at( size/2 );
			double a2 = dd.at( ( size/2 + 1 ) );
	
			return ( ( a1 + a2 ) / 2.0 );
	
	
		}
		else {
	
			index = (unsigned int) ( ( ( (double) size ) / 2.0 ) + 0.5 );
			return dd.at(index);
			
		}

	}
	else {

		return 0.0;

	}


}


double MathUtils::mean ( std::vector<double> values , std::vector<unsigned int> idx, bool unbiased ) {

	double mean = 0.0;

	if ( !values.empty() ) {

		for (unsigned int i=0; i<idx.size(); i++) {
	
			mean += values.at( idx.at(i) );
	
		}
	
		if ( unbiased ) {
	
			mean = mean / ( (double) idx.size() - 1.0 );
	
		}
		else {
	
	
			mean = mean / ( (double) idx.size() );
	
		}

	}

	return mean;

}


double MathUtils::mean ( std::vector<int> values, bool unbiased ) {

	double mean = 0.0;

	if ( !values.empty() ) {

		for (unsigned int i=0; i<values.size(); i++) {
	
			mean += ( (double) values.at(i) );
	
		}
	
		if ( unbiased ) {
	
			mean = mean / ( (double) values.size() - 1.0 );
	
		}
		else {
	
	
			mean = mean / ( (double) values.size() );
	
		}

	}

	return mean;

}


double MathUtils::mean ( std::vector<int> values, std::vector<unsigned int> idx, bool unbiased ) {

	double mean = 0.0;

	if ( !values.empty() ) {

		for (unsigned int i=0; i<idx.size(); i++) {
	
			mean += ( (double) values.at( idx.at(i) ) );
	
		}
	
		if ( unbiased ) {
	
			mean = mean / ( (double) idx.size() - 1.0 );
	
		}
		else {
	
	
			mean = mean / ( (double) idx.size() );
	
		}

	}

	return mean;

}

		
std::vector<double> MathUtils::derivative( std::vector<double> values ) {

	std::vector<double> d;
	d.clear();

	if ( values.size() > 2 ) {

		double dr;
	
		if (DEBUG) std::cout<<"dr = [ ";
	
		for (unsigned int i=0; i<values.size()-1; i++) {
	
			dr = values.at(i+1) - values.at(i);
			
			if (DEBUG) std::cout<<dr<<" ";
	
			d.push_back(dr);
	
		}
	
		if (DEBUG) std::cout<<"]"<<std::endl;

	}

	return d;

}


		
std::vector<double> MathUtils::derivative( std::vector<int> values ) {

	std::vector<double> d;
	d.clear();

	if ( values.size() > 2 ) {

		double dr;
	
		if (DEBUG) std::cout<<"dr = [ ";
	
		for (unsigned int i=0; i<values.size()-1; i++) {
	
			dr = (double) ( values.at(i+1) - values.at(i) );
			
			if (DEBUG) std::cout<<dr<<" ";
	
			d.push_back(dr);
	
		}
	
		if (DEBUG) std::cout<<"]"<<std::endl;

	}

	return d;

}


double MathUtils::min ( std::vector<double> values ) {

	std::vector<double> data = sort( values );

	return data.at(0);

}

		
int MathUtils::min ( std::vector<int> values ) {

	std::vector<int> data = sort( values );

	return data.at(0);

}

		
unsigned int MathUtils::min( std::vector<unsigned int> values ) {

	std::vector<unsigned int> data = sort( values );

	return data.at(0);

}

		
double MathUtils::max ( std::vector<double> values ) {

	std::vector<double> data = sort( values, true );

	return data.at(0);

}


		
int MathUtils::max ( std::vector<int> values ) {

	std::vector<int> data = sort( values, true );

	return data.at(0);

}

		
unsigned int MathUtils::max( std::vector<unsigned int> values ) {

	std::vector<unsigned int> data = sort( values, true );

	return data.at(0);

}

		
std::vector<double> MathUtils::sort( std::vector<double> values, bool descend ) {

	std::vector<double> data;
	data.clear();
	data = values;

	if ( descend ) {

		std::sort( data.begin(), data.end(), std::greater<double>() );
	}
	else {

		std::sort( data.begin(), data.end() );

	}

	return data;

}


		
std::vector<int> MathUtils::sort( std::vector<int> values, bool descend ) {

	std::vector<int> data;
	data.clear();
	data = values;

	if ( descend ) {

		std::sort( data.begin(), data.end(), std::greater<int>() );
	}
	else {

		std::sort( data.begin(), data.end() );

	}

	return data;

}


		
std::vector<unsigned int> MathUtils::sort( std::vector<unsigned int> values, bool descend ) {

	std::vector<unsigned int> data;
	data.clear();
	data = values;

	if ( descend ) {

		std::sort( data.begin(), data.end(), std::greater<unsigned int>() );
	}
	else {

		std::sort( data.begin(), data.end() );

	}

	return data;

}


std::vector<double> MathUtils::norm( std::vector<double> values ) {

	std::vector<double> data;
	data.clear();
	
	double mx = max( values );

	for (unsigned int i=0; i<values.size(); i++) {
	
		data.push_back( values.at(i) / mx ) ;

	}

	return data;

}


