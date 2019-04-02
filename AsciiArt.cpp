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
	int L;
	cin >> L; cin.ignore();
	int H;
	cin >> H; cin.ignore();
	string T;
	getline(cin, T);
	string ROW;

	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	transform(T.begin(), T.end(), T.begin(), ::toupper);

	int ia = (int) 'A';
	int iz = (int) 'Z';



	for (int i = 0; i < H; i++) {
		getline(cin, ROW);
		string ret = "";

		for (int j = 0; j < T.size(); j++)
		{
			int c = (int)T[j];

			if (c < ia || c > iz)
			{
				ret += ROW.substr(L * (iz - ia + 1), L);
			}
			else
			{
				ret += ROW.substr(L * (c - ia), L);
			}
		}

		cout << ret << endl;
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
}