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
Mat HistogramProcessor::getHisto()
{
  return this->histo;
}

/***********************************/
//FUNCTIONS
void HistogramProcessor::process()
{
      std::cout << "Processing..."  << "\n";
      if (image.empty()) {//Check if there is an image
        std::cout << RED "Image empty..." RESET << "\n";
        return;
      }

      
      histo=calculateHistogram(this->image, this->nbBins);//Compute the histogram

      /* std::cout <<GRN "Histogram" RESET << "\n";
      namedWindow("Display window", WINDOW_AUTOSIZE );
      imshow( "Display window", histo );

      waitKey(0);
      */
  return;
  
}


Mat HistogramProcessor::calculateHistogram(Mat img, int numbins)
{
    Mat hsv;
    Mat hist;
    // Convert the color from bgr to hsv
    cvtColor(img, hsv, CV_BGR2HSV);

    // Quantize the hue
    int hbins = numbins;
    int histSize[] = {hbins};

    // hue varies from 0 to 179, see cvtColor
    float hranges[] = { 0, 180 };

    const float* histRange = {hranges};

    int channels[] = {0};

    // we compute the histogram from the 0-th channel
    calcHist( &hsv, 1,channels, Mat(), // do not use mask
              hist, 1, &hbins, &histRange, true,false );

     return hist;
	
}




