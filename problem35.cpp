#include <iostream>
#include <cstring>
using namespace std;
const int n = 1000000;

bool prime[n];

void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i < n; ++ i)
	{
		while (i < n && !prime[i]) ++ i;
		for (int j = 2; i * j < n; ++ j)
			prime[i * j] = false;
	}
}

bool check(int x)
{
	int bit;
	for (bit = 1; bit < x; bit *= 10);
	bit /= 10;
	int cur = x;
	while (1)
	{
		cur = cur / 10 + (cur % 10) * bit;
		if (cur == x) break;
		if (!prime[cur]) return false;
	}
	return true;
}

int main()
{
	prepare();
	int ans = 0;
	for (int i = 1; i < n; ++ i)
		if (prime[i] && check(i)) ++ ans;
	cout << ans << endl;
	return 0;
}
