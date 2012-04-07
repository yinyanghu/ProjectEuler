/*
 *
 * Memorized Search
 *
 *
 *
 */
#include <iostream>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int limit = 1000000;

const int max_number = 6 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 + 1; 

int factorial[10];

int len[max_number];

int f(int x)
{
	int ret = 0;
	while (x != 0)
	{
		ret += factorial[x % 10];
		x /= 10;
	}
	return ret;
}

vector<int> record;

int main()
{
	factorial[0] = factorial[1] = 1;
	for (int i = 2; i < 10; ++ i)
		factorial[i] = i * factorial[i - 1];

	int ans = 0;

	memset(len, -1, sizeof(len));


	for (int i = 1; i < limit; ++ i)
	{
		if (len[i] == -1)
		{
			record.clear();

			int key;
			for (key = i; len[key] == -1; key = f(key))
			{
				len[key] = 0;
				record.push_back(key);
			}

			bool flag;
			int dist;
			if (len[key] > 0)
			{
				flag = true;
				dist = record.size() + len[key];
			}
			else
			{
				flag = false;
				dist = record.size();
			}

			for (int j = record.size()- 1; j >= 0; -- j)
				if (flag)
					len[record[j]] = dist - j;
				else if (key == record[j])
				{
					flag = true;
					len[record[j]] = dist - j;
				}
		}
		if (len[i] == 60) ++ ans;
	}

	cout << ans << endl;

	return 0;
}



/*
set<int> path;
int main()
{
	factorial[0] = factorial[1] = 1;
	for (int i = 2; i < 10; ++ i)
		factorial[i] = i * factorial[i - 1];

	int ans = 0;



	for (int i = 1; i < limit; ++ i)
	{
		path.clear();	
		
		int count = 0;
		for (int key = i; path.find(key) == path.end(); key = f(key))
		{
			++ count;
			if (count > 60) break;
			path.insert(key);
		}
		if (count == 60) ++ ans;
	}

	cout << ans << endl;

	return 0;
}
*/
