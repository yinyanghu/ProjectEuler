/*
 *
 * f(i, j) : number i, can be written as a sum of j positive integer
 *
 * f(i, j) = f(i - 1, j - 1) + f(i - j, j)
 *
 *
 * Answer = Sigma(i = 2 to 100) f(100, i)
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

const int n = 100;

int f[n + 1][n + 1];

int main() {

	memset(f, 0, sizeof(f));

	for (int i = 1; i <= n; ++ i)
	{
		f[i][1] = f[i][i] = 1;
		for (int j = 2; j< i; ++ j)
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
	}

	int ans = 0;
	for (int i = 2; i <= n; ++ i)
		ans += f[n][i];


	cout << ans << endl;

	return 0;
}

