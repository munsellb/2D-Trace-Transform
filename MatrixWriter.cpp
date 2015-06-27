#include "MatrixWriter.h"
#include <iomanip>




// **********************************************
//
// 				Constructor
//
// **********************************************

MatrixWriter::MatrixWriter() {

} // end constructor


// **********************************************
//
// 				Destructor
//
// **********************************************

MatrixWriter::~MatrixWriter() {

} // end destructor


// ----------------------------------------------
// METHOD: bool MatrixWriter::writeMatrix(std::string fileHandle, CvMat* M)
// CREATED:  06-27-2008
// DESCRIPTION:
//
//
//
// TODO:
//

bool MatrixWriter::writeMatrix(std::string fileHandle, CvMat* M) {

    // open file socket
    std::ofstream fout;
    fout.open(fileHandle.c_str(), std::ios::out);

    if (fout.fail()) return false;

    for(unsigned int i=0; i<M->rows; i++) {

      for (unsigned int j=0; j<M->cols; j++) {

	if ( j == (M->cols-1) ) {

	    fout<<std::setprecision(30)<<cvGetAt(M,i,j).val[0]<<std::endl;

	}
	else {

	    fout<<std::setprecision(30)<<cvGetAt(M,i,j).val[0]<<" ";

	}

      }
	    
    }

    fout.close();
    fout.clear();

    return true;

} // end writeMatrix() method
