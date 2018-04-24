#include <iostream>

#include "Board.h"

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
    return 0;
}
