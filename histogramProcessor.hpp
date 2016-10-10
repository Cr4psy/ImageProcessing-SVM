#ifndef HISTOGRAMROCESSOR_H
#define HISTOGRAMROCESSOR_H

#include "header.hpp"
#include "imageProcessing.hpp" //Main Class

class HistogramProcessor: public ImageProcessing
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
