#include <iostream>
#include <cstring>

using namespace std;

long long n = 100000001;

bool check(long long x)
{
	if (x % 10 != 9) return false;
	x /= 100;

	if (x % 10 != 8) return false;
	x /= 100;

	if (x % 10 != 7) return false;
	x /= 100;

	if (x % 10 != 6) return false;
	x /= 100;

	if (x % 10 != 5) return false;
	x /= 100;

	if (x % 10 != 4) return false;
	x /= 100;
	
	if (x % 10 != 3) return false;
	x /= 100;

	if (x % 10 != 2) return false;
	x /= 100;

	if (x != 1) return false;
	return true;

}


int main()
{
	while (1)
	{
		if ((n % 10 != 3) && (n % 10 != 7))
		{
			n += 2;
			continue;
		}
		long long x = n * n;
		if (check(x)) break;
		n += 2;
	}
	cout << n << '0' << endl;
	cout << n * n << "00" << endl;
	return 0;
}
