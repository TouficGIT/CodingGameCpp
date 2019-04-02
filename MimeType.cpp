#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	int N; // Number of elements which make up the association table.
	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();

	map<string, string> mtMap;
	map<string, string>::iterator it; // itérateur it pour parcourir mtMap
	string Extension; // l'extension extraite du nom du fichier

	for (int i = 0; i < N; i++) {
		string EXT; // file extension
		string MT; // MIME type.
		cin >> EXT >> MT; cin.ignore();
		transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
		mtMap[EXT] = MT; // On associe une extension à 1 MIME
	}


	for (int i = 0; i < Q; i++) {
		string output = "UNKNOWN";
		string FNAME; // One file name per line.
		getline(cin, FNAME);
		transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);

		size_t j = FNAME.rfind('.', FNAME.length());
		if (j != string::npos) {
			Extension = FNAME.substr(j + 1, FNAME.length() - j);

			it = mtMap.find(Extension);
			if (it != mtMap.end())
			{
				output = it->second;
			}
		}
		cout << output << endl;
	}

}