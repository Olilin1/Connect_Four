## To compile using no external tools other than g++
Extract SimpleConnect_Four and shared_files folders and maintain same relative path. Then while in folder SimpleConnect_Four use command "g++ "../shared_files/*.cpp" *.cpp" to compile. Run a.exe to test program. To write your own AI create a class for it in shared_files and include it into gameLibrary.hpp. (Feel free to completely ignore these instructions if you have used c++ before and feel like some other way would be better. These instructions are only for people who really need them.)

## To compile using QT
Extract the files, run Qmake, build, and run.

## How everything works
The game is handled using the Connectfourgame class. 2 function pointers are used to determine players/ai's and there is also an optional pointer to a function for handling graphics. This means that in order to create new AI's / graphics there should be no modification to the game class. Instead to create an AI one should simply create a function like this
```c++
short name_of_function(std::vector<std::vector<short>>){
    //Logic here
    return column_to_play
}
```
And then use that like so
```c++
game.setPlayer1(name_of_function);
```
or
```c++
game.setPlayer2(name_of_function);
```