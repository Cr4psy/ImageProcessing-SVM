#include "svmclassification.hpp"
//g++ testSVM.cpp histogramProcessor.cpp histogramProcessor.hpp dataset.h dataset.cpp svmclassification.cpp svmclassification.hpp $(pkg-config opencv --cflags --libs)

int main(int argc, char *argv[])
{


  SVMClassification mySvm;


  mySvm.setNbBins(10);

  mySvm.process();


  
  return 0;
}
