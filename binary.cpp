#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	int  n = 20;
  int* binary = new int[n];

	// Check if an integer number was provided as a command line argument.
  if (argc < 2) {
    cout << "Please provide an integer number on the command line." << endl;
    return 1;
	}
  int number = atoi(argv[1]);
  
  // Convert number to binary form.
  for (int i = 0; i < n; i++) {
  	binary[i]  = number % 2;
  	number    /= 2;
  }

	// Dump number in binary form to terminal.
	bool zeros = true;
	for (int i = n-1; i >= 0; i--) {
		if (!(binary[i] == 0 && zeros == true)) {
			cout << binary[i];
			zeros = false;
		}
	}
	cout << endl;

  // Program run successfully, return 0.
  return 0;
}

