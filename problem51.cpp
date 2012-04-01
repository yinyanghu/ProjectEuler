#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int limitsize = 1000000;
bool prime[limitsize + 1];
void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= limitsize; ++ i)
	{
		while (i <= limitsize && !prime[i]) ++ i;
		for (int j = (i << 1); j <= limitsize; j += i)
			prime[j] = false;
	}
}

int bit[10];
int len;
void split(int x)
{
	len = 0;
	while (x)
	{
		bit[len ++ ] = x % 10;
		x /= 10;
	}
}

int replace(int x)
{
	int ret = 1;
	bool change = false;
	for (int i = 0; i < len; ++ i)
		if (bit[i] == x)
		{
			change = true;
			break;
		}
	if (!change) return ret;
	for (int i = x + 1; i <= 9; ++ i)
	{
		int sum = 0;
		for (int j = len - 1; j >= 0; -- j)
			if (bit[j] == x)
				sum = sum * 10 + i;
			else
				sum = sum * 10 + bit[j];
		if (prime[sum]) ++ ret;
	}
	return ret;
}

int main()
{
	prepare();
	for (int i = 10;; ++ i)
		if (prime[i])
		{
			split(i);
			for (int j = 0; j <= 2; ++ j)
			{
				int total = replace(j);
				if (total == 8)
				{
					cout << i << endl;
					return 0;
				}
			}
		}
	return 0;
}
