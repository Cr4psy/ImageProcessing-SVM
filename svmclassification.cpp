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
  histograms.release();//Erase arrays
  labels.release();
  
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

void SVMClassification::process()//Test the SVM with test data set and save the result in a  text file
{
  /****************************************************/
  //Test data

  int estimatedLabel = 0;
  stringstream ssResults;
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
  accuracy=((float)nbRightLabel/(float)nbLabel)*100;
  cout << BLU "Accuracy : " << accuracy << "%\n" RESET;

  ssResults << nbLabel << '\t' << nbRightLabel << '\t' << accuracy << '\t' << nbBins << '\t' << percentage << '\n';
  
  saveResults(name, ssResults.str());
  
  /*To continue*/
}

void SVMClassification::accessData()//Access to the image in the folder and stock in a vector
{
  Dataset myData;
 
  myData.setRootPath("../dataset/");
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

   svm.train_auto(histograms,labels, Mat(), Mat(), params);
}

void SVMClassification::createFile(string inName)
{
  name = inName;
  //Creat a new vierge file
  fstream file;

  file.open(inName.c_str(),ios::out);

  file.close();
}

void SVMClassification::saveResults(string inName, string inData)
{
  //Append data to a file
  ofstream file;

  file.open(inName.c_str(),ios::app);

  file << inData;
      
  file.close();

}



