#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int ans, len;
bool flag[10];
bool prime(int x)
{
	for (int i = 2; i <= int(sqrt(x)) + 1; ++ i)
		if (x % i == 0) return false;
	return true;
}
void dfs(int depth, int cur)
{
	if (ans != -1) return;
	if (depth == len)
	{
		if (prime(cur)) ans = cur;
		return;
	}
	for (int i = len; i; -- i)
		if (flag[i])
		{
			flag[i] = false;
			dfs(depth + 1, cur * 10 + i);
			flag[i] = true;
		}
}
int main()
{
	for (len = 9; len >= 1; -- len)
	{
		ans = -1;
		memset(flag, true, sizeof(flag));
		dfs(0, 0);
		cout << ans << endl;
	}
}
