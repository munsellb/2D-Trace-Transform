#include "MathUtils.h"

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#define DEBUG 0

class Histogram : public MathUtils {
	
	public:	
		Histogram();
		~Histogram();
		
		void calculate( std::vector <double> data, unsigned int m_numBins);

		int getPeakBin();
		double getBinValue( unsigned int binNumber );
		
		std::vector <unsigned int> getHist() { return bins; }
		std::vector < std::vector<double> > getHistValues() { return hist; }
		
		int getMinBinValue() { return minBinValue; }
		int getMaxBinValue() { return maxBinValue; }

	private:

		std::vector <unsigned int> bins;
		std::vector < std::vector<double> > hist;

		int maxBinValue;
		int minBinValue;
		int binWidth;

		unsigned int numBins;
		
};

#endif
