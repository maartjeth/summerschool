/*
*This is the introduction of the game Hex. If the user enters 'n' the windows will shut down and if the user
*enters 'y' the game will remain running, i.e. runGame(), until the user types 'exit'.
*
*!!This code is not finished yet, some parts are still missing.
*/


#include <iostream>
#include <string>

using namespace std;
int main (){
    cout << "Welcome to Hex! \nDo you want to start a new game? (y/n)";
    string mystr;
    bool gameRunning;
    getline (cin, mystr);
    if (mystr == "y"){
        gameRunning = true;
    }
    else{
        gameRunning = false;
        cout << "The game will shut down.";
    }
    while (gameRunning){
        //runGame();
    }
	return 0;
}
