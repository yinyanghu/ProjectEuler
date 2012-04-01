#include <iostream>
#include <cstring>
using namespace std;

int circle_length(int x)
{
	int flag[x];
	memset(flag, 0, sizeof(flag));
	int a = 1;
	for (int bit = 1;; ++ bit)
	{
		if (a < x)
			a *= 10;
		else
		{
			int b = a % x;
			if (b == 0)
				return 0;
			if (flag[b] != 0)
				return (bit - flag[b]);
			else
				flag[b] = bit;
			a = b * 10;
		}
	}
}

int main()
{
	int maxlen = 0, ans;
	for (int d = 2; d < 1000; ++ d)
	{
		int temp = circle_length(d);
		if (temp > maxlen)
		{
			maxlen = temp;
			ans = d;
		}
	}
	cout << ans << endl;
	return 0;
}
