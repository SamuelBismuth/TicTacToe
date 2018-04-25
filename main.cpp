#include <iostream>

#include "Board.h"
#include "IllegalCoordinateException.h"

using namespace std;

int main() {
	Board board1{4}; // Initializes a 4x4 board
    cout << board1 << endl; /* Shows an empty board:
    ....
	....
	....
	....
	*/
    board1[{1,1}]='X';
    board1[{1,2}]='O';
	cout << board1 << endl;  /* Shows the following board:
	....
	.XO.
	....
	....
	*/
	try {
		board1[{3,4}]='O';   // This should raise an exception
	} catch (const IllegalCoordinateException& ex) {
		cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
    }
    return 0;
}
