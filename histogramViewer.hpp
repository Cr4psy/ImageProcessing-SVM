#ifndef HISTOGRAMVIEWER_H
#define HISTOGRAMVIEWER_H

#include "histogramProcessor.hpp"

#include "header.hpp"
#include "imageProcessing.hpp" //Main class



class HistogramViewer: public ImageProcessing
{

 public:
  //Constructors
  HistogramViewer();
  HistogramViewer(Mat inImage);
  //Setters
  void setImage(Mat inImage);
  void setHisto(Mat inHisto);
  void setNbBins(int inNbBins);
  //Getters
  
  //Functions
  virtual void process();
  void viewHisto();//Show the histo
  
 private:
  Mat image;
  Mat histo;
  int nbBins;
  void visualizeHistogram(const Mat& image, const Mat& histo, int nbBins);

};

#endif
