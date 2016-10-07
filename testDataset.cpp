#include "dataset.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

//Write that to compile :
//g++ testDataset.cpp dataset.h dataset.cpp $(pkg-config opencv --cflags --libs)


using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
  Mat image;
  Dataset myData;
  vector<pair<string,int> > trainLabel;

    
  myData.setRootPath("dataset/");
  myData.createDataPaths(1);//1 = 100% of the training data
  std::cout << myData.getRootPath()  << "\n";
  trainLabel = myData.getTrainingPathsLabels();
  std::cout << trainLabel.size()  << "\n";

  for (int i = 0; i < trainLabel.size(); i++) {
    cout << "image path : " << trainLabel[i].first  << "\n";
    cout << "class number :" << trainLabel[i].second  << "\n";
  }

  image = imread(trainLabel[1].first);

  namedWindow("Display window", WINDOW_AUTOSIZE );
  imshow( "Display window", image );

  waitKey(0);

  
  
  return 0;
}
