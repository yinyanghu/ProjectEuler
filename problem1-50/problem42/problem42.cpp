#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int limitsize = 10000;
bool flag[limitsize + 1];
int main()
{
	freopen("problem42.txt", "r", stdin);
	memset(flag, false, sizeof(flag));
	for (int i = 1; (i * (i + 1) >> 1) <= limitsize; ++ i)
		flag[i * (i + 1) >> 1] = true;
	int ans = 0;
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (int i = 0; i < s.size(); ++ i)
			sum += int(s[i]) - 64;
		if (flag[sum]) ++ ans;
	}
	cout << ans << endl;
	return 0;
}
