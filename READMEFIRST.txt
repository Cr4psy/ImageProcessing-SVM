In order to run the codes on the virtual machine, you need to do the following:

- First you need to open a terminal screen and run
sudo apt-get update

The sudo password is el2310

 - Second run:
sudo apt-get install libopencv-dev

 - Third run:
sudo apt-get install cmake


When you go to the cpp_assignment_files folder, create a directory called build. Then in the command line go to the build directory and run: 
cmake ..
When it is done run:
make
You should have the executable ready. 

!! When you want to add additional files for compilation you should modify the CMakeLists.txt, delete the files in the build folder and then run the cmake .. and make commands inside build folder.


