#include<iostream>
#include <cmath>
using namespace std;

int abs(int x)
{
	return (x >= 0) ? x : -x;
}

bool prime(int x)
{
	for (int i = 2; i <= int(sqrt(abs(x))) + 1; ++ i)
		if (abs(x) % i == 0) return false;
	return true;
}

int check(int a, int b)
{
	for (int n = 0; ; ++ n)
		if (!prime(n * n + n * a + b)) return n - 1;
}

int main()
{
	int ans = -1, n;
	for (int b = -999; b < 1000; ++ b)
		if (prime(b))
			for (int a = -999; a < 1000; ++ a)
			{
				int temp = check(a, b);
				if (temp > ans)
				{
					n = a * b;
					ans = temp;
				}
			}
	cout << n << endl;
	return 0;
}
