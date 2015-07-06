#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//functions

//print the board depending on the number of rows and columns
void printBoard (int nRows, int nCol){

    for (int i = 0; i < nRows; i++)//loops nRows times
    {
        for (int j = 0; j < i; j++)
        {
           cout << " ";
        }
        //cout << i << " ";
		for(int k = 0; k<nCol; k++)
		{
			cout<<"- " ;
		}
    cout<<endl;
    }

}

int main ()
{
    int nRows, nCol;
    string mystr;
    cout << "Enter the number of rows: ";
    getline (cin, mystr);
    stringstream(mystr) >> nRows;
    cout << "Enter the number of columns: ";
    getline (cin, mystr);
    stringstream(mystr) >> nCol;
    printBoard(nRows, nCol);

	return 0;
}
