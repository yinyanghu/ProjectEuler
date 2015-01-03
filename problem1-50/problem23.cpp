#include <iostream>
#include <cstring>
using namespace std;

const int limit = 28123;
bool f[limit + 1];

bool check(int x)
{
	int sum = 0;
	for (int i = 1; i <= (x >> 1); ++ i)
		if (x % i == 0) sum += i;
	return sum > x;
}

bool flag[limit + 1];

int main()
{
	memset(flag, true, sizeof(flag));
	for (int i = 1; i <= limit; ++ i)
		f[i] = check(i);
	for (int i = 1; i <= limit; ++ i)
		if (f[i])
			for (int j = 1; j <= limit - i; ++ j)
				if (f[j])
					flag[i + j] = false;
	int ans = 0;
	for (int i = 1; i <= limit; ++ i)
		if (flag[i]) ans+= i;
	cout << ans << endl;
	return 0;
}
