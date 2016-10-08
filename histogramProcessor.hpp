#ifndef HISTOGRAMROCESSOR_H
#define HISTOGRAMROCESSOR_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/opencv.hpp>


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
  Mat getHisto();
  //Functions
  virtual void process();
  
 private:
  //Variables
  Mat image;
  Mat histo;
  int nbBins;
  
  //Functions
  Mat calculateHistogram(Mat img, int numbins);
  
};

#endif
