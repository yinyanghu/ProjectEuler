#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int limitsize = 1000000;
vector<int> final;
bool prime[limitsize + 1];
void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= limitsize; ++ i)
	{
		while (i <= limitsize && !prime[i]) ++ i;
		for (int j = (i << 1); j <= limitsize; j += i)
			prime[j] = false;
	}
	final.clear();
	final.push_back(2);
	for (int i = 3; i <= limitsize; i += 2)
		if (prime[i]) final.push_back(i);
}

long long sum[80000];

int main()
{
	prepare();
	sum[0] = 0;
	int n = final.size();
	for (int i = 0; i < n; ++ i)
		sum[i + 1] = sum[i] + final[i];
	int maxlen = 0, ans;
	for (int i = n; i >= 1; -- i)
	{
		for (int j = 1; j < i; ++ j)
			if (sum[i] - sum[j - 1] <= limitsize && prime[sum[i] - sum[j - 1]])
			{
				if (i - j + 1 > maxlen)
				{
					maxlen = i - j + 1;
					ans = sum[i] - sum[j - 1];
				}
				break;
			}
		if (i <= maxlen) break;
	}
	cout << maxlen << endl;
	cout << ans << endl;
	return 0;
}
