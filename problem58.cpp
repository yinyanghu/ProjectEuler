/*
 *
 * (2n + 1)^2
 * (2n + 1)^2 - 2n
 * (2n + 1)^2 - 4n
 * (2n + 1)^2 - 6n
 *
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool check(int x) {
	int k = (int)sqrt(x);
	for (int i = 2; i <= k; ++ i)
		if (x % i == 0) return false;
	return true;
}

int total = 1, count = 0;

int n = 1;

int main() {

	while (1)
	{
		total += 4;
		int k = ((n << 1) + 1) * ((n << 1) + 1) - (n << 1);
		if (check(k)) ++ count;
		k -= (n << 1);
		if (check(k)) ++ count;
		k -= (n << 1);
		if (check(k)) ++ count;

		if (total / 10 >= count)
			break;
		++ n;
	}
	cout << (n << 1) + 1 << endl;
	return 0;
}

