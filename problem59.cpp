/*
 *
 *
 * 1. Most common words in English ---> the
 * 2. Frequency analysis
 * 3. Letter frequency
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("problem59.txt");

vector<int> text;

int key[3];

int main() {


	text.clear();
	int temp;
	while (fin >> temp)
		text.push_back(temp);

	for (key[0] = int('a'); key[0] <= int('z'); ++ key[0])
		for (key[1] = int('a'); key[1] <= int('z'); ++ key[1])
			for (key[2] = int('a'); key[2] <= int('z'); ++ key[2])
			{
				int count = 0;
				for (int i = 0; i < text.size(); ++ i)
					if ((text[i] ^ key[i % 3]) == int(' ')) ++ count;


				if (count / (double)text.size() > 0.15)
				{
					int ans = 0;
					for (int i = 0; i < text.size(); ++ i)
					{
						int k = text[i] ^ key[i % 3];
						ans += k;
						cout << char(k);
					}
					cout << endl << endl;
					cout << "KEY = " << char(key[0]) << char(key[1]) << char(key[2]) << "!" << endl;
					cout << "total ASCII = " << ans << endl;
				}
			}
	return 0;

}

