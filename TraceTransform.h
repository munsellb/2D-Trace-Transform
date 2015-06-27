#include <string>
#include "MathUtils.h"
#include "TraceImage.h"
#include "TraceLine.h"

#ifndef TRACETRANSFORM_H
#define TRACETRANSFORM_H

#define RADON 0
#define T3 1
#define T20 2

class TraceTransform {

public:

    TraceTransform();
    ~TraceTransform();

    void setImage( std::string m_imageFile , bool m_isRGB = false , bool m_histeq = false );
    void setTraceFile( std::string m_traceFile ) { traceFile = m_traceFile; }
    void setFuntional( unsigned int m_functional ) { functional = m_functional; }

    void initialize();
    void calculate();


private:

    std::string traceFile;

    TraceImage image;
    TraceLine* traceLine;

    unsigned int functional;
    unsigned int numAngles;		

    int rFirst, rLast;						
    int rSize;	

    std::vector<double> rhoVector;						
					    
    CvMat* traceMat;

    void dispose( CvMat* matrix );

};

#endif
