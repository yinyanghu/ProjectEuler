#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int limitsize = 100000;
vector<int> final;

void prepare()
{
	bool prime[limitsize + 1];
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

int split(int x)
{
	int ret = 0;
	for (int i = 0; i < final.size() && x != 1; ++ i)
		if (x % final[i] == 0)
		{
			++ ret;
			while (x % final[i] == 0) x /= final[i];
		}
	return ret;
}

int main()
{
	prepare();
	int total = 0;
	for (int i = 100;; ++ i)
	{
		if (split(i) == 4)
		{
			++ total;
			if (total == 4)
			{
				for (int j = i; j >= i - 3; -- j)
					cout << j << endl;
				break;
			}
		}
		else
			total = 0;
	}
	return 0;
}
