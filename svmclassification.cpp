#include "svmclassification.hpp"
#include "histogramProcessor.hpp"

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

/***********************************/
//GETTERS


/***********************************/
//FUNCTIONS
void SVMClassification::process()
{
     HistogramProcessor myHisto;
     
     accessData();

  //labels.create(trainingData.sizeof(),1,int)

     
     /*********************************************/
     //Training data
     for (int i = 0; i <trainingData.size(); i++) {
    cout << "image path (TRAIN) : " << trainingData[i].first  << "\n";
    cout << "class number (TRAIN) :" << trainingData[i].second  << "\n";
  

    image = imread(trainingData[i].first);//Extract image from file
    label =  trainingData[i].second;
    
    //Compute histogram
    myHisto.setImage(image);
    myHisto.setNbBins(nbBins);
    myHisto.process();
    histo=myHisto.getHisto();

    //Save the histogram
    histo = histo.t();
    histograms.push_back(histo);

    //Save the class
    labels.push_back(label);

    
    //std::cout << histograms.at<float>(1,i)  << "\n";
    //std::cout << labels.at<int>(i)  << "\n";
    //visualizeHistogram(image,histograms.row(i),this->nbBins);
    }
     cout << "Number of data : "<< histograms.size[0]<< "\n";
     cout << "Computation of the SV"  << "\n";
     trainSVM(histograms, labels);

     

     /****************************************************/
     //Test data
     for (int i = 0; i < testData.size(); i++) {
       cout << "image path (TEST) : " << testData[i].first  << "\n";
       cout << "class number (TEST) :" << testData[i].second  << "\n";
  

    image = imread(testData[i].first);//Extract image from file
    label =  testData[i].second;
    
    //Compute histogram
    myHisto.setImage(image);
    myHisto.setNbBins(nbBins);
    myHisto.process();
    histo=myHisto.getHisto();

    //Save the histogram
    histo = histo.t();
    histogramsTest.push_back(histo);

    //Save the class
    labelsTest.push_back(label);

    
    //std::cout << histograms.at<float>(1,i)  << "\n";
    //std::cout << labels.at<int>(i)  << "\n";
    //visualizeHistogram(image,histograms.row(i),this->nbBins);
    }
     
     cout << "Number of data (TEST): "<< histogramsTest.size[0]<< "\n";
     cout << "Find the classes"  << "\n";

       
     /*To continue"
    

}

void SVMClassification::testSVM()
{
  /*TO CONTINUE
}

void SVMClassification::accessData()//Access to the image in the folder and stock in a vector
{
  Dataset myData;
 
  myData.setRootPath("dataset/");
  myData.createDataPaths(0.1);//1 = 100% of the training data
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


   CvSVM svm;
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
