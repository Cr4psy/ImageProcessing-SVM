#ifndef SVMCLASSIFICATION_H
#define SVMCLASSIFICATION_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "dataset.h"
#include "histogramProcessor.hpp"

using namespace std;
using namespace cv;


class SVMClassification
{

 public:
  //Constructor
  SVMClassification();
  
  //Setters
  void setPercentage(float inPercentage);
  void setNbBins(int inNbBins);
  
  //Functions
  void process();//Not used yet
  void training();//Use to train the SV
  void testSVM();//Use to test the SV

  
 private:
  //Functions
  void trainSVM(Mat histograms, Mat labels);
  void visualizeHistogram(const Mat& src, const Mat& hist, int nbins);
  void accessData();

  
  //Variables
  CvSVM svm;
  HistogramProcessor myHisto;
 
  int nbBins;
  int label;
  int nbLabel;
  int nbRightLabel;
  float percentage;
  vector<pair<string,int> > trainingData;
  vector<pair<string,int> > testData;
  Mat image;
  Mat histo;
  Mat histograms;
  Mat histogramsTest;
  Mat labels;
  Mat labelsTest;
 
  
};

#endif
