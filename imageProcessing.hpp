#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "header.hpp" //All the necessary headers



class ImageProcessing
{

 public:
  ImageProcessing();//Constructor
  virtual void process() = 0;  //pure virtual function, is not implemented in .cpp

};



#endif
