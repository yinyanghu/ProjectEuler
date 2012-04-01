#include <iostream>
using namespace std;
const int n = 200;
const int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[n + 1];
int main()
{
	f[0] = 1;
	for (int i = 0; i < 8; ++ i)
		for (int j = coin[i]; j <= n; ++ j)
			f[j] += f[j - coin[i]];
	cout << f[n] << endl;
/*
	int ans = 0;
	for (int a = 0; a <= 1; ++ a)
	for (int b = 0; b <= (200 - a * 200) / 100; ++ b)
	for (int c = 0; c <= (200 - a * 200 - b * 100) / 50; ++ c)
	for (int d = 0; d <= (200 - a * 200 - b * 100 - c * 50) / 20; ++ d)
	for (int e = 0; e <= (200 - a * 200 - b * 100 - c * 50 - d * 20) / 10; ++ e)
	for (int f = 0; f <= (200 - a * 200 - b * 100 - c * 50 - d * 20 - e * 10) / 5; ++ f)
	for (int g = 0; g <= (200 - a * 200 - b * 100 - c * 50 - d * 20 - e * 10 - f * 5) / 2; ++ g)
	for (int h = 0; h <= 200 - a * 200 - b * 100 - c * 50 - d * 20 - e * 10 - f * 5 - g * 2; ++ h)
		if (a * 200 + b * 100 + c * 50 + d * 20 + e * 10 + f * 5 + g * 2 + h == 200)
			++ ans;
	cout << ans << endl;
*/
	return 0;
}
