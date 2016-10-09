#include "svmclassification.hpp"


/***********************************/
//CONSTRUCTORS
SVMClassification::SVMClassification()
{
}

/***********************************/
//SETTERS
void SVMClassification::setNbBins(int inNbBins)
{
  this->nbBins=inNbBins;
}
void SVMClassification::setPercentage(float inPercentage)
{
  this->percentage=inPercentage;
}

/***********************************/
//GETTERS


/***********************************/
//FUNCTIONS
void SVMClassification::training()
{   
     
  accessData();//Extract the path and class of the dataset and store in a vector

  //labels.create(trainingData.sizeof(),1,int)

     
  /*********************************************/
  //Training data
  for (int i = 0; i <trainingData.size(); i++) {
    image = imread(trainingData[i].first);//Extract image from file
    label =  trainingData[i].second;//Extract the label
    cout << "image path (TRAIN) : " << trainingData[i].first  << "\n";
    cout << "class number (TRAIN) :" << label  << "\n";
    
    //Compute histogram
    myHisto.setImage(image);
    myHisto.setNbBins(nbBins);
    myHisto.process();
    histo=myHisto.getHisto();
    histo = histo.t();//Transpose the histo
    
    //Save the histogram
    histograms.push_back(histo);//Save the histo in an array
    labels.push_back(label);//Save the labels in an array

    //std::cout << histograms.at<float>(1,i)  << "\n";
    //std::cout << labels.at<int>(i)  << "\n";
    //visualizeHistogram(image,histograms.row(i),this->nbBins);
  }
  cout << "Number of data : "<< histograms.size[0]<< "\n";
  cout << "Computation of the SV"  << "\n";

  trainSVM(histograms, labels);

  
}

void SVMClassification::testSVM()
{
  /****************************************************/
  //Test data
  int estimatedLabel = 0;
  nbLabel=0;
  nbRightLabel=0;
  
  for (int i = 0; i < testData.size(); i++) {

    image = imread(testData[i].first);//Extract image from file
    label =  testData[i].second;//Extract the label
    cout << "image path (TEST) : " << testData[i].first  << "\n";
    cout << "class number (TEST) :" << label  << "\n";
    
    //Compute histogram
    myHisto.setImage(image);
    myHisto.setNbBins(nbBins);
    myHisto.process();
    histo=myHisto.getHisto();    
    histo = histo.t();//Transpose histogram's values



    //Compare the right value with the estimatedLabel
    estimatedLabel = svm.predict(histo);
    std::cout << "My prediction : " << estimatedLabel  << "\n";
    nbLabel+=1;
    if (estimatedLabel == label) {
      nbRightLabel+=1;
    }
    
    //Save data
    //histogramsTest.push_back(histo);//Save all the histo value in an array  
    //labelsTest.push_back(label);//Save all the labels in a array
    
  }
     
  cout << "Number of data (TEST): "<< nbLabel << "\n";
  cout << "Number of class found correctly :" << nbRightLabel  << "\n";
  
  
  /*To continue*/
}

void SVMClassification::accessData()//Access to the image in the folder and stock in a vector
{
  Dataset myData;
 
  myData.setRootPath("dataset/");
  myData.createDataPaths(percentage);//1 = 100% of the training data
  trainingData = myData.getTrainingPathsLabels();
  testData = myData.getTestPathsLabels();
  
}
void SVMClassification::trainSVM(Mat histograms,Mat labels)
{  
  
  CvSVMParams params;
  params.svm_type = CvSVM::C_SVC;
  params.kernel_type = CvSVM::POLY;
  params.term_crit = TermCriteria(CV_TERMCRIT_ITER, (int)10000, 1e-6);
  params.p = 1;
  params.degree=3;


  //CvSVM svm;
   svm.train_auto(histograms,labels, Mat(), Mat(), params);
}

//Visu-- Temporary
void SVMClassification::visualizeHistogram(const Mat& src, const Mat& hist, int nbins)
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
