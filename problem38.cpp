#include <iostream>
#include <cstring>
using namespace std;
const int limit = 100000;
int check(int x)
{
	int y = 0;
	bool flag[10];
	memset(flag, true, sizeof(flag));
	flag[0] = false;
	int total = 9;
	int ret = 0;
	while (1)
	{
		for (int temp = x * (++ y); temp; temp /= 10)
		{
			if (!flag[temp % 10]) return -1;
			flag[temp % 10] = false;
			-- total;
		}
		for (int i = 1; i < x * y; i *= 10)
			ret *= 10;
		ret += x * y;
		if (total == 0)	return ret;
	}
}
int main()
{
	int ans = -1;
	int temp;
	for (int i = 1; i < limit; ++ i)
		if ((temp = check(i)) != -1)
			if (temp > ans) ans = temp;
	cout << ans << endl;
	return 0;
}
