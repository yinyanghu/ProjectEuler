#include <iostream>
using namespace std;
const int million = 1000000;
const int n = 100;
bool flag[n + 1][n + 1];
int f[n + 1][n + 1];
int main()
{
	flag[0][0] = false;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i)
	{
		f[i][0] = f[i][i] = 1;
		flag[i][0] = flag[i][i] = false;
		for (int j = 1; j < i; ++ j)
		{
			flag[i][j] = flag[i - 1][j] || flag[i - 1][j - 1];
			if (!flag[i][j])
			{
				f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
				if (f[i][j] > million) flag[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= i; ++ j)
			if (flag[i][j]) ++ ans;
	cout << ans << endl;
	return 0;
}
