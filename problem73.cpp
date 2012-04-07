/*
 *
 * Stern-Brocot Tree
 * http://mathworld.wolfram.com/Stern-BrocotTree.html
 * Wikipedia: Stern-Brocot Tree
 *
 * Farey Sequence
 * http://mathworld.wolfram.com/FareySequence.html
 * Wikipedia: Farey sequence
 *
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

const int limit = 12000;
int a = 1;
int b = 3;
int c = 4000;
int d = 11999;

int ans = 0;

int main()
{
	while (!(c == 1 && d == 2))
	{
		++ ans;
		int k = (limit + b) / d;
		int e = k * c - a;
		int f = k * d - b;
		a = c;
		b = d;
		c = e;
		d = f;
	}
	cout << ans << endl;
	return 0;
}




/*
 * Brute Force Method
const int limit = 12000;

inline int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
	int ans = 0;
	for (int d = 3; d <= limit; ++ d)
	{
		int left = d / 3 + 1;
		int right = ((d & 1) == 0) ? (d >> 1) - 1 : (d >> 1);
		for (int n = left; n <= right; ++ n)
			if (gcd(n, d) == 1) ++ ans;

	}

	cout << ans << endl;


	return 0;
}
*/
