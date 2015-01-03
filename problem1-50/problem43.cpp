#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long ans = 0;
bool flag[10];
int bit[9];
const int prime[7] = {2, 3, 5, 7, 11, 13, 17};
bool check()
{
	for (int i = 0; i < 7; ++ i)
		if ((bit[i + 1] * 100 + bit[i + 2] * 10 + bit[i + 3]) % prime[i] != 0) return false;
	return true;
}

void dfs(int depth, long long cur)
{
	if (depth == 10)
	{
		if (check()) ans += cur, cout << cur << endl;
		return;
	}
	int start = (depth) ? 0 : 1;
	for (int i = start; i < 10; ++ i)
		if (flag[i])
		{
			flag[i] = false;
			bit[depth] = i;
			dfs(depth + 1, cur * 10 + i);
			flag[i] = true;
		}
}
int main()
{
	memset(flag, true, sizeof(flag));
	dfs(0, 0);
	cout << "Sum = " << ans << endl;
}
