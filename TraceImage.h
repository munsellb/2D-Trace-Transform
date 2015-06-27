#include <string>
#include "MathUtils.h"
#include "cv.h"
#include "highgui.h"

#ifndef TRACEIMAGE_H
#define TRACEIMAGE_H

#define IMG_NORM 128
#define LOAD_IMG_DEBUG 0

class TraceImage {

public:

      TraceImage();
      ~TraceImage();

      void setImage( std::string m_imageFile , bool m_isRGB = false , bool m_histeq = false );
      void setImage( std::string m_imageFile , std::string m_maskFile, bool m_isRGB = false , bool m_histeq = false );

      int getNumberOfRows() { return M; }
      int getNumberOfColumns() { return N; }

      int getXOrigin() { return xOrigin; }
      int getYOrigin() { return yOrigin; }

      double getPixelValue( unsigned int m, unsigned int n );

      void printSelf();

	
private: 

    std::string imageFile;
    std::string maskFile;

    bool histeq;
    bool isRGB;
    bool hasMask;

    int M, N;						/* input image size */
    int xOrigin, yOrigin;			/* center of image */

    IplImage* inputImage;

    void load();
    void dispose( IplImage* image );

};

#endif
