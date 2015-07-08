/*
Auteur: Jaco ter Hoeve
Dit programma print het hexbord aan de hand van een integer array.
*/

#include <iostream>

using namespace std;

//Deze functie print het aantal spaties dat gelijk is aan het rijnummer
void indent(int row){
    for(int i = 0; i <row; i++){
            cout << " ";
    }
}

void drawBoard(int arr[], int size, int nRows, int nCol){
    int row, col;
    int currRow = 0;
    int currCol = 0;
    cout << "    ";//het eerste kolomnummer wordt met 4 spaties ingesprongen
    for (int i = 0; i < nCol; i++){//de kolomnummers worden boven de kolommen geplaatst
        cout << i << "  ";
    }
    cout << "\n\n" << currRow << "   ";//het eerste rij nummer wordt geprint

    for (int i = 0; i<size; i++){
            row = (i+1)/(nCol);
            if(arr[i] == 1){
                cout<< "o  ";//symbool voor speler 1
                //als row groter is dan currRow moet een nieuwe rij begonnen worden
                if (row > currRow){
                    currRow = row;
                    cout << "\n\n";
                    indent(row);
                    if (currRow < nRows){
                         if (currRow <10){//10 heeft twee tekens, dus een spatie minder
                            cout<< currRow << "   ";
                         }
                         else {
                            cout<< currRow << "  ";
                         }
                    }
                }
            }
            else if(arr[i] == -1){
                cout << "x  ";//symbool voor speler -1
            }
            else{
                cout << "-  ";
            }
    }
}

int main()
{
    int nRows = 11;
    int nCol = 11;
    int arraySize = nRows * nCol;//aantal indexen
    int blockArray [] = {  1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};
    drawBoard(blockArray, arraySize, nRows, nCol);
    return 0;
}
