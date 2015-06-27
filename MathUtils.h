#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

#ifndef MATHUTILS_H
#define MATHUTILS_H

#define DEBUG 0
#define MAXX(x,y) ((x) > (y) ? (x) : (y))
#define PI 3.14159265358979

class MathUtils {
		
	public:	
		MathUtils();
		~MathUtils();
		
		double variance( std::vector<double> values , bool unbiased = false);
		double variance( std::vector<int> values , bool unbiased = false );

		double variance( std::vector<double> values , std::vector<unsigned int> idx, bool unbiased = false);
		double variance( std::vector<int> values , std::vector<unsigned int> idx, bool unbiased = false );

		double mean ( std::vector<double> values , bool unbiased = false);
		double mean ( std::vector<int> values, bool unbiased = false );

		double median( std::vector<double> values, bool unbiased = false );

		double mean ( std::vector<double> values , std::vector<unsigned int> idx, bool unbiased = false);
		double mean ( std::vector<int> values, std::vector<unsigned int> idx, bool unbiased = false );

		std::vector<double> derivative( std::vector<double> values );
		std::vector<double> derivative( std::vector<int> values );

		int sum( std::vector<int> values );
		double sum( std::vector<double> values );

		double min ( std::vector<double> values );
		int min ( std::vector<int> values );
		unsigned int min( std::vector<unsigned int> values );

		double max ( std::vector<double> values );
		int max ( std::vector<int> values );
		unsigned int max( std::vector<unsigned int> values );

		std::vector<double> sort( std::vector<double> values, bool descend = false );
		std::vector<int> sort( std::vector<int> values, bool descend = false );
		std::vector<unsigned int> sort( std::vector<unsigned int> values, bool descend = false );

		std::vector<double> norm( std::vector<double> values );

		double precision( double value, std::string fmt );

};

#endif

