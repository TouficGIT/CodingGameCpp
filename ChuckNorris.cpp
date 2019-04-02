#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	string MESSAGE;
	getline(cin, MESSAGE);

	string bitString;
	string::iterator it; // itérateur sur un string

	for (int i = 0; i < MESSAGE.size(); i++)
	{
		char letter = MESSAGE[i];
		bitset<7> bit(letter);
		bitString += bit.to_string();
	}

	string out = "";
	int is_zero = -1;
	string temp = "";

	for (it = bitString.begin(); it != bitString.end(); it++)
	{
		int new_is_zero = (*it == '0');
		if (new_is_zero == is_zero)
		{
			temp += "0";
		}

		else
		{
			is_zero = new_is_zero;
			if (out.length() > 0)
			{
				out += " ";
			}

			out += temp;

			if (is_zero)
			{
				temp = "00 0";
			}

			else
			{
				temp = "0 0";
			}
		}
	}


	if (temp.length() > 0)
	{
		if (out.length() > 0)
		{
			out += " ";
		}

		out += temp;
	}

	cout << out << endl;

}