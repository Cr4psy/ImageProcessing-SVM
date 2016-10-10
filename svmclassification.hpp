#ifndef SVMCLASSIFICATION_H
#define SVMCLASSIFICATION_H

#include "dataset.h" //Use the class dataset in accessData
#include "histogramProcessor.hpp" //Declare a variable from this class

#include "imageProcessing.hpp" //Main class

using namespace std;
using namespace cv;


class SVMClassification: public ImageProcessing
{

 public:
  //Constructor
  SVMClassification();
  
  //Setters
  void setPercentage(float inPercentage);
  void setNbBins(int inNbBins);
  
  //Functions
  virtual void process();//Use to test the SV
  void training();//Use to train the SV
  void createFile(string inName);
  
 private:
  //Functions
  void trainSVM(Mat histograms, Mat labels);
  void accessData();
  void saveResults(string inName, string inData);

  
  //Variables
  CvSVM svm;
  HistogramProcessor myHisto;
 
  int nbBins;
  int label;
  int nbLabel;
  int nbRightLabel;
  float percentage;
  float accuracy;
  string name;
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
