#include <iostream>
using namespace std;
const int limit = 1000000;
bool check(int x, int base)
{
	int bit[100];
	int len = 0;
	while (x)
	{
		bit[len ++] = x % base;
		x /= base;
	}
	int l = 0, r = len - 1;
	while (l < r)
	{
		if (bit[l] != bit[r]) return false;
		++ l; -- r;
	}
	return true;
}
int main()
{
	int sum = 0;
	for (int i = 1; i < limit; ++ i)
		if (check(i, 10) && check(i, 2))
		{
			cout << i << endl;
			sum += i;
		}
	cout << "Sum = " << sum << endl;
	return 0;
}
