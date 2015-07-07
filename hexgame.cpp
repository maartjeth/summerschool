/*
* Authors: Jaco & Tom
* This is the introduction to the game Hex. Running this file will start the game.
*
* !! This code is not finished yet; game should be implemented in While loop.
*/


#include <iostream>
#include <string>

using namespace std;

void runGame(){
    
}

int main (){
//  The user can choose to start with 'y' or quit with 'n'. Any other command will ask again to start the game.
    cout << "Welcome to Hex! \n";
start:
    cout << "Do you want to start a new game? (y/n) \n";
    string mystr;
    bool gameRunning;
    getline (cin, mystr);
    if (mystr == "y"){
        gameRunning = true;
        cout << "Type '?' to check if game is running; type 'exit' to shut down. \n";
    }
    else if(mystr == "n"){
        gameRunning = false;
        cout << "Too bad...";
    }
    else{
        cout << "Command unknown; please use 'y' or 'n'... \n";
        goto start;
    }
//  If the user starts the game using 'y', the game will run (i.e. runGame();).
//  The user can check if the game is still running with '?' and can quit the game with 'exit'.
    while (gameRunning){
        getline (cin, mystr);
        if (mystr == "exit"){
            gameRunning = false;
            cout << "The game will shut down.";
        }
        else if(mystr == "?"){
            gameRunning = true;
            cout << "Game still running \n";
            //runGame();
            // << Here the actual game should be implemented (possibly instead of checking if the game still runs). >>
        }
        else{
            gameRunning = true;
            cout << "Command unknown \n";
            //runGame();
        }

    }
	return 0;
}
