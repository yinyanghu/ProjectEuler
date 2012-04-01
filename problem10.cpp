#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int limit = 2000000;
bool prime[limit];
void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i < int(sqrt(limit)) + 1; ++ i)
		if (prime[i])
			for (int j = 2; i * j < limit; ++ j)
				prime[i * j] = false;
}

int main()
{
	prepare();
	long long ans = 0;
	for (int i = 1; i < limit; ++ i)
		if (prime[i]) ans += i;
	cout << ans << endl;
	return 0;
}
