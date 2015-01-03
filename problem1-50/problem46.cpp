#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int limitsize = 10000000;
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

bool check(int x)
{
	for (int i = 0; i < final.size(); ++ i)
	{
		int k = x - final[i];
		if ((k & 1) == 0)
		{
			int temp = int(sqrt(k >> 1));
			if (temp * temp == (k >> 1)) return true;
		}
	}
	return false;
}

int main()
{
	prepare();
	for (int i = 3; i <= limitsize; i += 2)
		if (!prime[i] && !check(i))
		{
			cout << i << endl;
			break;
		}
	return 0;
}
