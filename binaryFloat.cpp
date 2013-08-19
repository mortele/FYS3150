#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	int  n = 20;
  int* binaryInteger  = new int[n];
	int* binaryFloating = new int[n];
	
	// Check if a floating point number was provided as a command line argument.
  if (argc < 2) {
    cout << "Please provide a floating point number on the command line." << endl;
    return 1;
	}
  int      integer  = atoi(argv[1]);
  double   floating = atof(argv[1]);
  floating = floating - ((double) integer); 
  
  // Convert integer part to binary.
  for (int i = 0; i < n; i++) {
  	binaryInteger[i]  = integer % 2;
  	integer          /= 2;
  }
  
  // Convert floating part to binary.
  for (int i = 0; i < n; i++) {
  	floating *= 2;
  	if (floating > 1) {
  		floating       -= 1;
  		binaryFloating[i]  = 1; 
  	} else {
  		binaryFloating[i]  = 0;
  	}	
  }	
  
	// Dump number in binary form to terminal.
	bool zeros = true;
	for (int i = n-1; i >= 0; i--) {
		if (!(binaryInteger[i] == 0 && zeros == true)) {
			cout << binaryInteger[i];
			zeros = false;
		}
	}
	cout << ".";
	for (int i = 0; i < n; i++) {
		cout << binaryFloating[i];
	}	
	cout << endl;

  // Program run successfully, return 0.
  return 0;
}

