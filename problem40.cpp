#include <iostream>
using namespace std;
const int maxn = 1000000;
int len = 0;
int f[maxn + 100];
void add(int x)
{
	int bit;
	for (bit = 1; bit <= x; bit *= 10);
	bit /= 10;
	while (bit)
	{
		f[++ len] = x / bit;
		x %= bit;
		bit /= 10;
	}
}
int main()
{
	for (int i = 1; len <= maxn; ++ i)
		add(i);
	int ans = 1;
	for (int i = 1; i <= maxn; i *= 10)
		ans *= f[i];
	cout << ans << endl;
	return 0;
}
