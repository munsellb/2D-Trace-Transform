PP=g++

OPENCV_INC=-I/usr/local/include/opencv

CFLAGS=-c -O3 $(OPENCV_INC)

LIBS = -lm -lcv -lcvaux -lcxcore -lhighgui


all:ttransform cleanproj

ttransform: ttransform.o TraceTransform.o TraceLine.o TraceImage.o MatrixWriter.o MathUtils.o Histogram.o 
	$(PP) -o ttransform ttransform.o TraceTransform.o TraceLine.o TraceImage.o MatrixWriter.o MathUtils.o Histogram.o $(LIBS)

ttransform.o: ttransform.cpp
	$(PP) $(CFLAGS) ttransform.cpp

TraceTransform.o: TraceTransform.cpp
	$(PP) $(CFLAGS) TraceTransform.cpp

TraceLine.o: TraceLine.cpp
	$(PP) $(CFLAGS) TraceLine.cpp
	
TraceImage.o: TraceImage.cpp
	$(PP) $(CFLAGS) TraceImage.cpp

MatrixWriter.o: MatrixWriter.cpp
	$(PP) $(CFLAGS) MatrixWriter.cpp

MathUtils.o: MathUtils.cpp
	$(PP) $(CFLAGS) MathUtils.cpp

Histogram.o: Histogram.cpp
	$(PP) $(CFLAGS) Histogram.cpp
	

cleanproj:

	@echo finishing up - cleaning up object files ...
	rm *.o 

clean:
	@echo cleaning project 
	rm ttransform Makefile~ *.o *.c~ *.h~ *.cpp~
