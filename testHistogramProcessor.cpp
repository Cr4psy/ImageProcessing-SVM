#include "histogramProcessor.hpp"
#include "dataset.h"


int main(int argc, char *argv[])
{
  Mat image;

  HistogramProcessor myHisto;

  
  //myHisto.process();
  
   Dataset myData;
   vector<pair<string,int> > trainLabel;

    
  myData.setRootPath("dataset/");
  myData.createDataPaths(1);//1 = 100% of the training data
  std::cout << myData.getRootPath()  << "\n";
  trainLabel = myData.getTrainingPathsLabels();
  std::cout << trainLabel.size()  << "\n";

  image = imread(trainLabel[1].first);

  myHisto.setImage(image);
  //myHisto.process();
  
  namedWindow("Display window", WINDOW_AUTOSIZE );
  imshow( "Display window", myHisto.getImage() );

  waitKey(0);
  
  return 0;
}
