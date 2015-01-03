#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int n = 15;
int f[n + 1][n + 1];
int main()
{
	freopen("problem18.txt", "r", stdin);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j)
			cin >> f[i][j];
	for (int i = 2; i <= n; ++ i)
	{
		f[i][1] += f[i - 1][1];
		f[i][i] += f[i - 1][i - 1];
		for (int j = 2; j < i; ++ j)
			f[i][j] += max(f[i - 1][j - 1], f[i - 1][j]);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		ans = max(ans, f[n][i]);
	cout << ans << endl;
	return 0;
}
