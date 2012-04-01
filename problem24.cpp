#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int n = 10;
int a[n];

void find(long long x)
{
	bool flag[n];
	memset(flag, true, sizeof(flag));
	long long delta = 1;
	for (int i = 2; i <= n; ++ i)
		delta *= i;
	int ans[n];
	for (int i = 0; i < n; ++ i)
	{
		delta /= n - i;
		int pointer = 0;
		while (!flag[pointer]) ++ pointer;
		while (x > delta)
		{
			x -= delta;
			++ pointer;
			while (!flag[pointer]) ++ pointer;
		}
		ans[i] = pointer;
		flag[pointer] = false;
	}
	for (int i = 0; i < n; ++ i)
		cout << ans[i];
	cout << endl;
}


int main()
{
	find(1000000);
	return 0;
}
