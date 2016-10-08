#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <iostream>

using namespace std;


class ImageProcessing
{


 public:
  ImageProcessing();
  virtual void process() = 0;  //pure virtual function, is not implemented in .cpp



 private:



};



#endif
