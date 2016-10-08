All:dataset.h dataset.cpp histogramProcessor.cpp histogramProcessor.hpp testHistogramProcessor.cpp 
	g++ testHistogramProcessor.cpp histogramProcessor.cpp histogramProcessor.hpp dataset.h dataset.cpp $(pkg-config opencv --cflags --libs)
