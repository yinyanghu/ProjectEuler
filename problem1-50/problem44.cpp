#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 300000000;
const int infinity = 1000000000;
const int maxn = 20000;
bool flag[limitsize + 1];
int f[maxn];
int n;
int main()
{
	memset(flag, false, sizeof(flag));
	for (n = 1; (((n * 3 - 1) * n) >> 1) <= limitsize; ++ n)
	{
		f[n] = ((n * 3 - 1) * n) >> 1;
		flag[f[n]] = true;
	}
	-- n;
	cout << f[n] << endl;
	cout << n << endl;
	int ans = infinity;
	for (int i = 2; i <= n; ++ i)
	{
		for (int j = i - 1; j >= 1; -- j)
		{
			if (f[i] - f[j] >= ans) break;
			if (f[i] + f[j] <= f[n] && flag[f[i] + f[j]] && flag[f[i] - f[j]])
				ans = f[i] - f[j];
		}
	}
	cout << ans << endl;
	return 0;
}
