## To compile using no external tools other than g++
Extract SimpleConnect_Four and shared_files folders and maintain same relative path. Then while in folder SimpleConnect_Four use command "g++ "../shared_files/*.cpp" *.cpp" to compile. Run a.exe to test program. To write your own AI create a class for it in shared_files and include it into gameLibrary.hpp. (Feel free to completely ignore these instructions if you have used c++ before and feel like some other way would be better. These instructions are only for people who really need them.)

## To compile using QT
Extract the files, run Qmake, build, and run.