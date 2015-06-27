#include <iostream>
#include <vector>
#include "TraceImage.h"

#ifndef TRACELINE_H
#define TRACELINE_H

class TraceLine {

public:

	TraceLine( int m_tfirst , int m_tlast );
	~TraceLine();

	void setDistance( double m_rho ) { rho = m_rho; }
	void setAngle( double m_phi ) { phi = m_phi; }
	void setTraceImage( TraceImage* m_image ) { image = m_image; }

	double getCalculatedValue() { return calculatedValue; }

	void calculateRadon();
	void calculateT3();
	void calculateT20();

	void init();
	void build();

private:

	TraceImage* image;

	double PIX_FRAC;

	double* line;
	double* trace;

	double rho;
	double phi;

	double rad;
	double deg2rad;
	double rightAngle;

	double cosine;
	double sine;
	
	double tcosine;
	double tsine;

	double calculatedValue;

	int t_first;
	int t_last;
	int increment;
	int pos;

	void dispose();

};

#endif
