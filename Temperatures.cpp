#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int n; // the number of temperatures to analyse
	cin >> n; cin.ignore();
	int tmax = 5527;
	int location;

	if (n == 0) {
		tmax = 0;
	}

	for (int i = 0; i < n; i++) {
		int t; // a temperature expressed as an integer ranging from -273 to 5526
		cin >> t; cin.ignore();

		if (t == 0) {
			tmax = t;
		}

		else {

			if (abs(t) < abs(tmax)) {
				tmax = t;
			}

			if (abs(t) == abs(tmax)) {
				if (t > tmax) {
					tmax = t;
				}
			}
		}
	}

	cout << tmax << endl;
	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

}