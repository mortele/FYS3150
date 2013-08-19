#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	// Check that an integer, N, was provided on the command line.
	if (argc < 2) {
		cout << "Please provide the integer N (10^N)." << endl;
		return 1;
	}
	int N = atoi(argv[1]);
	N = (int) pow(10,N);
	
	double sUp    = 0;
	double sDown  = 0;
	float  sUpF   = 0;
	float  sDownF = 0;	
	
	// Compute the sums.
	for (int n = 1; n <= N; n++) {
		sUp  += 1.0 / n;
		sUpF += 1.0 / n;
	}
  for (int n = N; n > 0; n--) {
		sDown  += 1.0 / n;
		sDownF += 1.0 / n;
	}
	
	// Dump values to terminal.
  cout << endl << "Single prec.:" << endl;
	cout << "S_up   = " << setprecision(8) << sUpF   << endl;
	cout << "S_down = " << setprecision(8) << sDownF << endl;	
	cout << endl << "Double prec.:" << endl;
	cout << "S_up   = " << setprecision(15) << sUp   << endl;
	cout << "S_down = " << setprecision(15) << sDown << endl;

	// Dump differences to a file.
	ofstream outFile;
  outFile.open("sums.dat", ios::out);
  outFile << setprecision(15) << fabs(sUp  - sDown)  / fabs(sDown)  << endl;
  outFile << setprecision(15) << fabs(sUpF - sDownF) / fabs(sDownF);
	outFile.close();
	
  // Program run successfully, return 0.
  return 0;
}

