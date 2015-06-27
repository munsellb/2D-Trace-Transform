#include <iostream>
#include <fstream>
#include <string>
#include <cv.h>

#ifndef MATRIXWRITER_H
#define MATRIXWRITER_H

class MatrixWriter {

public:

	MatrixWriter();
	~MatrixWriter();

	bool writeMatrix(std::string fileHandle, CvMat* M);

};

#endif
