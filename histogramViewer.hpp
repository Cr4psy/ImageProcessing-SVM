#ifndef HISTOGRAMVIEWER_H
#define HISTOGRAMVIEWER_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class HistogramViewer
{

 public:
  HistogramViewer();
  HistogramViewer(Mat inImage);
  //Setters
  void setImage(Mat inImage);
  void setHisto(Mat inHisto);
  void setNbBins(int inNbBins);
  
  //Functions
  virtual void process();
  
 private:
  Mat image;
  Mat histo;
  int nbBins;
  void visualizeHistogram(const Mat& image, const Mat& histo, int nbBins);


};

#endif
