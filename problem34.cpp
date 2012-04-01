#include <iostream>
using namespace std;
const int limit = 10000000;
int f[10];
int check(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += f[x % 10];
		x /= 10;
	}
	return sum;
}
int main()
{
	f[0] = 1;
	for (int i = 1; i <= 9; ++ i)
		f[i] = f[i - 1] * i;
	int ans = 0;
	for (int i = 3; i <= limit; ++ i)
		if (check(i) == i)
		{
			cout << i << endl;
			ans += i;
		}
	cout << "Sum = " << ans << endl;
	return 0;
}
