#include "svmclassification.hpp"
//g++ testSVM.cpp histogramProcessor.cpp histogramProcessor.hpp dataset.h dataset.cpp svmclassification.cpp svmclassification.hpp $(pkg-config opencv --cflags --libs)

int main(int argc, char *argv[])
{


  SVMClassification mySvm;

  mySvm.createFile("results.txt");
  
  mySvm.setNbBins(10);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.testSVM();
  
  mySvm.setNbBins(30);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.testSVM();

    mySvm.setNbBins(90);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.testSVM();

    mySvm.setNbBins(180);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.testSVM();

  

    mySvm.setNbBins(30);
  mySvm.setPercentage(0.3);     
  mySvm.training();
  mySvm.testSVM();

    mySvm.setNbBins(30);
  mySvm.setPercentage(0.5);     
  mySvm.training();
  mySvm.testSVM();

      mySvm.setNbBins(30);
  mySvm.setPercentage(0.7);     
  mySvm.training();
  mySvm.testSVM();

       mySvm.setNbBins(30);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.testSVM();
  
  return 0;
}
