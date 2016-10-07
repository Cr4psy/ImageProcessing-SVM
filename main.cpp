#include <iostream>
#include <opencv2/opencv.hpp>
#include "dataset.h"

int main(int argc, char **argv)
{
    cout<<"Hello!! Welcome to the Image Procesing Program!"<<endl;
    while(1)
    {
        int command;

        cout<<"Please select the operation to be performed: 0 to read the provided dataset, train the svm and output the class accuracies, 1 to visualize an histogram of an image, -1 to quit: ";
        cin>>command;

        // just quit
        if(command == -1) break;

        // perform dataset reading, training and classification
        if(command == 0)
        {
            

            string datasetpath;
            int numbins;
            int datapercentage;


            cout<<"Please enter the root path of the dataset in format /home/xx/yy/: ";
            cin>>datasetpath;

            cout<<"Please enter the number of bins (10-180): ";
            cin>>numbins;

            cout<<"Please enter the percentage of training data to be used (30-100): ";
            cin>>datapercentage;


	    /**** Put your code here for this task ****/




     	}
        // Perform histogram visualization
    	else if(command == 1)
    	{
		/**** Put your code here for this task ****/
	}
        
    }



return 0;
}
