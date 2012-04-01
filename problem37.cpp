#include <iostream>
#include <cstring>
using namespace std;
const int n = 1000000;

bool prime[n + 1];

void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++ i)
	{
		while (i <= n && !prime[i]) ++ i;
		for (int j = 2; i * j <= n; ++ j)
			prime[i * j] = false;
	}
}

bool check(int x)
{
	int bit;
	for (bit = 1; bit < x; bit *= 10);
	bit /= 10;
	int cur = x;
	while (bit != 1)
	{
		cur %= bit;
		bit /= 10;
		if (!prime[cur]) return false;
	}
	cur = x;
	while (1)
	{
		cur /= 10;
		if (cur == 0) break;
		if (!prime[cur]) return false;
	}
	return true;
}

int main()
{
	prepare();
	check(3797);
	int ans = 0;
	for (int i = 10; i <= n; ++ i)
		if (prime[i] && check(i))
		{
			ans += i;
			cout << i << endl;
		}
	cout << "Sum = " << ans << endl;
	return 0;
}
