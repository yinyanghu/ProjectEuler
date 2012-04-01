#include <iostream>
using namespace std;
const long long last = 10000000000LL;
int main()
{
	long long ans = 0;
	for (int i = 1; i <= 1000; ++ i)
	{
		long long k = 1;
		for (int j = 1; j <= i; ++ j)
		{
			k = (long long)(k * i) % last;
			if (k == 0) break;
		}
		ans = (ans + k) % last;
	}
	cout << ans << endl;
	return 0;
}
