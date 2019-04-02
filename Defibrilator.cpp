#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	string LON;
	cin >> LON; cin.ignore();
	string LAT;
	cin >> LAT; cin.ignore();
	int N;
	cin >> N; cin.ignore();

	//Changer la , par un . pour la transfo en float
	string Temp = "";
	size_t sz = LON.rfind(',', LON.length());
	if (sz != string::npos) {
		Temp += LON.substr(0, sz);
		Temp += ".";
		Temp += LON.substr(sz + 1, LON.length() - sz);
		LON = Temp;
		Temp = "";
	}

	sz = LAT.rfind(',', LAT.length());
	if (sz != string::npos) {
		Temp += LAT.substr(0, sz);
		Temp += ".";
		Temp += LAT.substr(sz + 1, LAT.length() - sz);
		LAT = Temp;
	}

	map<float, string> DistDefib;
	string Delimiter = ";";
	float lonA = stof(LON);
	float latA = stof(LAT);


	for (int i = 0; i < N; i++) {
		string DEFIB;
		getline(cin, DEFIB);

		string place;
		string Extract = "";
		size_t Pos = 0;
		float lonB = 0.0;
		float latB = 0.0;
		int count = 0;
		Temp = "";

		while ((Pos = DEFIB.find(Delimiter)) != string::npos) {
			Extract = DEFIB.substr(0, Pos);
			DEFIB.erase(0, Pos + Delimiter.length());
			if (count == 1)
			{
				place = Extract;
			}
			else if (count == 4)
			{
				size_t sz = Extract.rfind(',', Extract.length());
				if (sz != string::npos) {
					Temp += Extract.substr(0, sz);
					Temp += ".";
					Temp += Extract.substr(sz + 1, Extract.length() - sz);
					Extract = Temp;
					Temp = "";
				}
				lonB = stof(Extract);
			}
			else
			{

			}
			count++;
		}

		if (DEFIB.length() > 0)
		{
			Extract = DEFIB.substr(0, DEFIB.length());
			size_t sz = Extract.rfind(',', Extract.length());
			if (sz != string::npos) {
				Temp += Extract.substr(0, sz);
				Temp += ".";
				Temp += Extract.substr(sz + 1, Extract.length() - sz);
				Extract = Temp;
				Temp = "";
			}
			latB = stof(Extract);
		}

		float x = (lonB - lonA) * cos((latA + latB) / 2);
		float y = (latB - latA);
		float dist = sqrt(pow(x, 2) + pow(y, 2)) * 6371;

		DistDefib[dist] = place;
	}

	pair<float, string> MinDist = *DistDefib.begin();

	cout << MinDist.second << endl;

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	// cout << "answer" << endl;
}