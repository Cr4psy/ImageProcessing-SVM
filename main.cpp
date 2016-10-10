#include "header.hpp" //Basics headers

#include "imageProcessing.hpp" //Main class
#include "svmclassification.hpp"
#include "histogramViewer.hpp"
#include "dataset.h"

void parametersEntry(int mode, string& datasetpath, int& numbins, int& datapercentage, string& nameFile);

int main(int argc, char **argv)
{
  srand(time(NULL));//For random number
  
    cout<< GRN "Hello!! Welcome to the Image Procesing Program!"RESET <<endl;
    while(1)
    {
        int command = -1;
        int numbins = 10;
        int randVal = 0;
        int datapercentage = 30;
        string nameFile;
        string datasetpath;
        Mat image;
        vector<pair<string,int> > trainLabel;
        
        HistogramViewer myView;//Instance of the class to see the histogram
        Dataset myData;//Instance of the class to extract data
        SVMClassification mySvm;//Instance of the class SVMClassification
        
        
        cout<<"Please select the operation to be performed: 0 to read the provided dataset, train the svm and output the class accuracies, 1 to visualize an histogram of an image, -1 to quit: ";
        cin>>command;

        // just quit
        if(command == -1) break;

        // perform dataset reading, training and classification
        if(command == 0)
        {         
          parametersEntry(command, datasetpath, numbins, datapercentage, nameFile);
        
	    /**** Put your code here for this task ****/
            mySvm.createFile(nameFile);//Creat a new file to save data

            //Extract features from image and compute the SV and test it
            mySvm.setNbBins(numbins);
            mySvm.setPercentage((float)datapercentage/100.0);
            mySvm.training();//Train the svm
            mySvm.process();//Test the svm with the training dataset
     	}
        
        // Perform histogram visualization
    	else if(command == 1)
    	{
		/**** Put your code here for this task ****/

          parametersEntry(command, datasetpath, numbins, datapercentage, nameFile);
        
          myData.setRootPath("../dataset/");
          myData.createDataPaths(1);//1 = 100% of the training data
          trainLabel = myData.getTrainingPathsLabels();


          randVal = rand()%trainLabel.size();
          
          image = imread(trainLabel[randVal].first);//Read the image from the file

          myView.setImage(image);
          myView.setNbBins(numbins);
          myView.process();
          
	}
        
    }



return 0;
}




void parametersEntry(int mode, string& datasetpath, int& numbins, int& datapercentage, string& nameFile)
{
  int choice = 0; 

  cout << "Do you want to enter the parameters manually : 0 \n Or do you want to take the predefined : 1 \n Your choice : ";
  cin >> choice;

  if (choice==0) {
                  
                
    cout<<"Please enter the root path of the dataset in format /home/xx/yy/: ";
    cin>>datasetpath;

    cout<<"Please enter the number of bins (10-180): ";
    cin>>numbins;
    
    if (mode == 0) {//If training data
     cout<<"Please enter the percentage of training data to be used (30-100): ";
     cin>>datapercentage;
 
     cout<<"Pleaser enter the name of the file to save the result :";
     cin >>nameFile;
    }
  }
  else{
    datasetpath = "../dataset/";
    numbins = 10;
    datapercentage = 30;
    nameFile = "result.txt";
  }

  cout<<"Paramters : " << "\nPath : "<< datasetpath << "\nNumber of bins : " << numbins << "\n";
  if (mode == 0) {
    cout<<"Percentage : " << datapercentage << "\nFile name : " << nameFile << "\n";
  }


  return;
}
