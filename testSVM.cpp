#include "svmclassification.hpp"
//g++ testSVM.cpp imageProcessing.hpp imageProcessing.cpp histogramProcessor.cpp histogramProcessor.hpp dataset.h dataset.cpp svmclassification.cpp svmclassification.hpp header.hpp color.h $(pkg-config opencv --cflags --libs)

int main(int argc, char *argv[])
{


  SVMClassification mySvm;

  mySvm.createFile("results.txt");

  //Modification Nb Bins

 
  mySvm.setNbBins(10);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();//Test the SVM
  
  mySvm.setNbBins(20);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();
  
  mySvm.setNbBins(30);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();

  mySvm.setNbBins(60);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();

    mySvm.setNbBins(90);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();
  
    mySvm.setNbBins(120);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();

  mySvm.setNbBins(180);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();

  //Modification of % data

  mySvm.setNbBins(30);
  mySvm.setPercentage(0.3);     
  mySvm.training();
  mySvm.process();

  mySvm.setNbBins(30);
  mySvm.setPercentage(0.5);     
  mySvm.training();
  mySvm.process();

  mySvm.setNbBins(30);
  mySvm.setPercentage(0.7);     
  mySvm.training();
  mySvm.process();

   mySvm.setNbBins(30);
  mySvm.setPercentage(0.9);     
  mySvm.training();
  mySvm.process();

  mySvm.setNbBins(30);
  mySvm.setPercentage(1);     
  mySvm.training();
  mySvm.process();
  
  return 0;
}
