#ifndef DATASET_H
#define DATASET_H
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;

typedef vector<pair<string,int> > PathsLabels;

class Dataset
{
public:

    Dataset();

    // Call this constructor to initialize an object with rootPath. rootPath is the path where you have the description.txt
    Dataset(string rootPath);
    
    
    void setRootPath(string path);
    string getRootPath();
    //  Call this function to fill the test and training pathlabel vectors!!
    bool createDataPaths(float percentage);

    // Returns a vector of path and label pairs for testing. You can use the paths to read the images and labels to calculate the accuracy of SVM. You should first call the createDataPaths function to fill the vectors
    vector<pair<string,int> > getTestPathsLabels();

    // Returns a vector of path and label pairs for training. You can use the paths to read the images and labels to prepare labels Mat for SVM. You should first call the createDataPaths function to fill the vectors
    vector<pair<string,int> > getTrainingPathsLabels();


private:

    bool readDescriptionFile();

    string rootPath;

    vector<pair<int,string> > classNumberNames;
    vector<pair<int,string> > classNumTrainingNames;
    vector<pair<int,string> > classNumTestNames;

    vector<pair<string,int> > trainingPathsAndLabels;

    vector<pair<string,int> > testPathsAndLabels;



};

#endif // DATASET_H
