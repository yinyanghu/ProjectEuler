#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	for (int i = 1;; ++ i)
	{
		long long k = (long long)(i + 1) * i;
		bool check = false;
		for (long long h = int(sqrt(k >> 2)); (long long)(2 * h * (2 * h - 1)) <= k; ++ h)
			if ((long long)(2 * h * (2 * h - 1)) == k)
				check = true;
		if (!check) continue;
		check = false;
		for (long long p = int(sqrt(k / 3)); (long long)(p * (3 * p - 1)) <= k; ++ p)
			if ((long long)(p * (3 * p - 1)) == k)
				check = true;
		if (check)
		{
			cout << i << endl;
			cout << (k >> 1) << endl;
		}
	}
}
