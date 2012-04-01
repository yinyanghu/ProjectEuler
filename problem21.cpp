#include <iostream>
using namespace std;
int calc(int x)
{
	int sum = 0;
	for (int i = 1; i <= (x >> 1); ++ i)
		if (x % i == 0) sum += i;
	return sum;
}
const int n = 10000;
int f[n];
int main()
{
	for (int i = 1; i <= n; ++ i)
		f[i] = calc(i);
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		if (f[i] <= n && f[i] > 0 && f[f[i]] == i && f[i] != i) ans += i;
	cout << ans << endl;
	return 0;
}
