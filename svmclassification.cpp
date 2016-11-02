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
void SVMClassification::setRootPath(string path)
{
  this->rootPath = path;
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
  int nbClass = 3;
  nbLabel=0;
  nbRightLabel=0;

  nbLabelClass.clear();
  nbRightLabelClass.clear();

  for (int i = 0; i < nbClass; i++) {
    nbLabelClass.push_back(0);
    nbRightLabelClass.push_back(0);
  }
 

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
    nbLabelClass[label]+=1;
    if (estimatedLabel == label) {
      nbRightLabel+=1;
      nbRightLabelClass[label]+=1;
    }

    
  }
     
  cout << "Number of data (TEST): "<< nbLabel << "\n";
  cout << "Number of class found correctly :" << nbRightLabel  << "\n";
  cout << "Corrdior : " << nbLabelClass[0] << "  -  " << nbRightLabelClass[0]  << "\n" ;
  cout << "Office : " << nbLabelClass[1] << "  -  " << nbRightLabelClass[1]  << "\n";
  cout << "Toilet : " << nbLabelClass[2] << "  -  " << nbRightLabelClass[2]  << "\n";
                                                         
  accuracy=((float)nbRightLabel/(float)nbLabel)*100;
  cout << BLU "Accuracy : " << accuracy << "%\n" RESET;

  ssResults << nbBins << "\t\t" << percentage << "\t\t\t" << nbLabel << "\t\t" << nbRightLabel << "\t\t" << accuracy << "\t\t"  << nbLabelClass[0] << " - " << nbRightLabelClass[0] << "\t\t\t"  << nbLabelClass[1] << " - " << nbRightLabelClass[1] << "\t\t\t"  << nbLabelClass[2] << " - " << nbRightLabelClass[2] << '\n';
  
  saveResults(name, ssResults.str());
  
}

void SVMClassification::accessData()//Access to the image in the folder and stock in a vector
{
  Dataset myData;
 
  myData.setRootPath(rootPath);
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

   svm.train(histograms,labels, Mat(), Mat(), params);
}

void SVMClassification::createFile(string inName)
{
  name = inName;
  //Creat a new vierge file
  fstream file;

  file.open(inName.c_str(),ios::out);

  file << "Nb bins" << "\t\t" << "% of training data" << "\t" <<  "Nb Data" << "\t\t" <<  "Nb right" << '\t' << "Accuracy" << '\t' << "Corridor (Tot - Good)"  << "\t" <<"Office (Tot - Good)" << "\t" << "Toilet (Tot - Good)"  <<'\n';
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



