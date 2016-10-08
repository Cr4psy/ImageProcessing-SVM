

#include "histogramViewer.hpp"
#include "histogramProcessor.hpp"
#include "color.h"



/***********************************/
//CONSTRUCTORS
HistogramViewer::HistogramViewer()
{
}
HistogramViewer::HistogramViewer(Mat inImage)
{
  this->image = inImage;
}

/***********************************/
//SETTERS
void HistogramViewer::setImage(Mat inImage)
{
  this->image=inImage;
}
void HistogramViewer::setHisto(Mat inHisto)
{
  this->histo=inHisto;
}
void HistogramViewer::setNbBins(int inNbBins)
{
  this->nbBins=inNbBins;
}
/***********************************/
//GETTERS


/***********************************/
//FUNCTIONS
void HistogramViewer::process()
{
  HistogramProcessor myHisto;

  myHisto.setImage(image);
  myHisto.setNbBins(nbBins);
  myHisto.process();
  histo=myHisto.getHisto();

  

  visualizeHistogram(image,histo,nbBins);
  

}

void HistogramViewer::visualizeHistogram(const Mat& src, const Mat& hist, int nbins)
{
    
    double maxVal=0;

    minMaxLoc(hist, 0, &maxVal, 0, 0);

    int scale = (600.0/nbins);

    Mat histImg = Mat::zeros(180 , nbins*scale,  CV_8UC3);


    for( int h = 0; h < nbins; h++ )
    {

        float binVal = hist.at<float>(h, 0);

        int intensity = cvRound(binVal*180/maxVal);

        rectangle( histImg, Point(h*scale,180-intensity),
                   Point((h+1)*scale - 1, 180),
                   cv::Scalar(255,0,0),
                   CV_FILLED );

    }

    namedWindow( "Source", 1 );
    imshow( "Source", src );
    cv::startWindowThread();

    namedWindow( "Hue Histogram", 1 );
    imshow( "Hue Histogram", histImg );
    waitKey();

    cv::destroyAllWindows();
    cv::waitKey(1);


    return;
}
