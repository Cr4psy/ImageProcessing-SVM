# ImageProcessing-SVM
Project in C++
Anthony Clerc - 2016

The aim of the project is to classify different images, fot more informations, see "Description.txt".

The program is made of different classes that are described below. This classes are used in the main.cpp file, which gives different options to the user, such as; training a classifier and test it or visualize a histogram.
In order to simplify the use of several classes and the library openCV, the program can be build through a make file inside buld folder.

################################################
CLASS :

###
ImageProcessing :
This is an abstract class which define the class shape for all the others processing classes. It is made of a pure virtual class called process.

###
DataSet :
The class dataset extract the path and the label of the images contained in a specific folder.

    Functions :
    - createDataPaths(int percentage) : Create a vector with the different path and label, with the percentage given of data. 

    Getters :
    - getTestPathsLabels : Return a vector of all the images path and label of the test data
    - getTrainingPathsLabels : Return a vector of all the images path and label of the training data
    - getRootPath : Return the path where the class will look for the images


###
HistogramProcessor :
This class analyse an image and return a color histogram with a given number of bins. This class is derived frome ImageProcessing.

     Functions :
     - process : Compute the histogram of the given image with the number of bins set previously.

     Getters :
     - getNbBins : Return the number of bins defined.
     - getImage : Return the image defined.
     - getHisto : Return the histogram computed with process().

     Setters :
     - setImage : Give the image that will be analysed.
     - setNbBins : Set the number of bins for the histogram.


###
HistogramViewer :
This class shows the histogram previously computed in ImageProcessing with the related image. This class is derived frome ImageProcessing.


     Functions :
     - process : The function process use the class "HistogramProcessor" to compute the histogram and then shows through the function "viewHisto".
     - viewHisto : Show the histogram with the image.

     Setters :
     - setImage : Define the image that will be analysed and displayed.
     - setHisto : Set the histogram, if computed at another time.
     - setNbBins : Define the number of bins for the histogram.

###
SVMClassification :
This class train a SVM classifier and test it.

     Functions :

     Getters :

     Setters :



################################################




