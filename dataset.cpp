#include "dataset.h"

Dataset::Dataset()
{
}
Dataset::Dataset(string rootPath)
{
    this->rootPath = rootPath;
    readDescriptionFile();
}
string Dataset::getRootPath()
{
    return this->rootPath;
}
void Dataset::setRootPath(string path)
{
    this->rootPath = rootPath;
}
bool Dataset::readDescriptionFile()
{
    string root = this->rootPath;

    root +="description.txt";

    cout<<root<<endl;

    ifstream istream(root.data());

    if(!istream) return false;

    pair<int,string> dataPair;

    string classLabel;
    int labelno,numtraining,numtest;

    while(istream>>classLabel>>labelno>>numtraining>>numtest)
    {

        dataPair.first = labelno;
        dataPair.second = classLabel;

        this->classNumberNames.push_back(dataPair);

        dataPair.first = numtraining;


        this->classNumTrainingNames.push_back(dataPair);

        dataPair.first = numtest;


        this->classNumTestNames.push_back(dataPair);

        //cout<<dataPair.first<<" "<<dataPair.second<<endl;


    }

    istream.close();

    return true;
}
bool Dataset::createDataPaths(float percentage)
{
    if(this->classNumberNames.size() == 0)
    {
        cout<<"Error!! You must first read the description file!!"<<endl;
        return false;
    }


    // Lets read the training and test samples
    for(size_t i = 0; i < classNumberNames.size(); i++)
    {
        int classLabel = classNumberNames[i].first;
        string className = classNumberNames[i].second;
        int numTrainingSamples = this->classNumTrainingNames[i].first;
        numTrainingSamples *= percentage;
        int numTestSamples = this->classNumTestNames[i].first;

        string path = this->rootPath;

        path+="training/";
        path+=className;
        path+="/";

        for(size_t j = 0; j < numTrainingSamples; j++)
        {
            stringstream sstream;

            sstream<<path<<"image"<<j<<".png";

            pair<string,int> pathlabelPair;

            pathlabelPair.first = sstream.str();

            pathlabelPair.second = classLabel;

            this->trainingPathsAndLabels.push_back(pathlabelPair);

            //cout<<sstream.str()<<endl;

        }

        path = this->rootPath;

        path+="test/";
        path+=className;
        path+="/";


        for(size_t j = 0; j < numTestSamples; j++)
        {
            stringstream sstream;

            sstream<<path<<"image"<<j<<".png";

            pair<string,int> pathlabelPair;

            pathlabelPair.first = sstream.str();

            pathlabelPair.second = classLabel;

            this->testPathsAndLabels.push_back(pathlabelPair);

            //cout<<sstream.str()<<endl;

        }


    }

    return true;

}
vector<pair<string,int> > Dataset::getTestPathsLabels()
{
    return this->testPathsAndLabels;
}
vector<pair<string,int> > Dataset::getTrainingPathsLabels()
{
    return this->trainingPathsAndLabels;
}
