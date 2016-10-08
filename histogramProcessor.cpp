#include "histogramProcessor.hpp"
#include "color.h"
/***********************************/
//CONSTRUCTORS
HistogramProcessor::HistogramProcessor()
{
  std::cout << "No image detected ! "  << "\n";
}
HistogramProcessor::HistogramProcessor(int inNbBins, Mat inImage)
{
  std::cout << "One image detected!"  << "\n";
  this-> image = inImage;
  this-> nbBins = inNbBins;
}



/***********************************/
//SETTERS
void HistogramProcessor::setImage(Mat inImage)
{
  std::cout << "One image detected!"  << "\n";
  this->image=inImage;
}
void HistogramProcessor::setNbBins(int inNbBins)
{
  this->nbBins = inNbBins;
}



/***********************************/
//GETTERS
int HistogramProcessor::getNbBins()
{
  return this->nbBins;
}
Mat HistogramProcessor::getImage()
{
  return this->image;
}


/***********************************/
//FUNCTIONS
void HistogramProcessor::process()
{
      std::cout << "HistogramProcessor in process"  << "\n";
      if (image.empty()) {//Check if there is an image
        std::cout << RED "Image empty..." RESET << "\n";
        return;
      }

      
      std::cout <<GRN "Image ok" RESET << "\n";
      namedWindow("Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", image );

      waitKey(0);
  
  return;
  
}


