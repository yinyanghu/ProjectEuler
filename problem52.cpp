#include <iostream>
#include <cstring>
using namespace std;

int bit[10];

void split(int x)
{
	memset(bit, 0, sizeof(bit));
	while (x)
	{
		++ bit[x % 10];
		x /= 10;
	}
}

bool check(int x)
{
	static int temp[10];
	memset(temp, 0, sizeof(temp));
	while (x)
	{
		++ temp[x % 10];
		if (temp[x % 10] > bit[x % 10]) return false;
		x /= 10;
	}
	for (int i = 0; i < 10; ++ i)
		if (temp[i] != bit[i]) return false;
	return true;
}

int main()
{
	for (int i = 1;; ++ i)
	{
		split(i);
		bool correct = true;
		for (int j = 2; j <= 6; ++ j)
			if (!check(i * j))
			{
				correct = false;
				break;
			}
		if (correct)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
