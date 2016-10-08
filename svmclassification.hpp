#ifndef SVMCLASSIFICATION_H
#define SVMCLASSIFICATION_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "dataset.h"

using namespace std;
using namespace cv;


class SVMClassification
{

 public:

  SVMClassification();
  void process();
  void setNbBins(int inNbBins);
  void trainSVM(Mat histograms, Mat labels);
  void testSVM();
 private:
  Mat image;
  Dataset myData;
  int nbBins;
  int label;
  vector<pair<string,int> > trainingData;
  vector<pair<string,int> > testData;
  Mat histo;
  Mat histograms;
  Mat histogramsTest;
  Mat labels;
  Mat labelsTest;
  void visualizeHistogram(const Mat& src, const Mat& hist, int nbins);
  void accessData();
};

#endif
