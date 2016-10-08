#ifndef HISTOGRAMROCESSOR_H
#define HISTOGRAMROCESSOR_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;



class HistogramProcessor
{

 public:
  //Constructors
  HistogramProcessor();
  HistogramProcessor(int inNbBins, Mat inImage);
  //Setters
  void setImage(Mat inImage);
  void setNbBins(int inNbBins);
  //Getters
  int getNbBins();
  Mat getImage();
  //Functions
  virtual void process();
  
 private:
  Mat image;
  int nbBins;
  
};

#endif
