#include <iostream>
#include <cstring>

using namespace std;

int n = 1;

int count = 0;

bool check(int x)
{
	static int k[10];
	if (x < 100) return true;
	int len;
	for (len = 0; x != 0; ++ len, x /= 10)
		k[len] = x % 10;

	bool flag = true;
	for (int i = 1; i < len; ++ i)
		if (k[i] < k[i - 1])
		{
			flag = false;
			break;
		}

	if (flag) return true;

	flag = true;
	for (int i = 1; i < len; ++ i)
		if (k[i] > k[i - 1])
		{
			flag = false;
			break;
		}

	if (flag) return true;
	return false;
}


int main()
{
	while (n ++ )
	{
		if (!check(n)) ++ count;
		if (100 * count >= n * 99) break;
	}
	cout << n << endl;
	return 0;
}
