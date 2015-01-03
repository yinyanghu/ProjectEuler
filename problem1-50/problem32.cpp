#include <iostream>
#include <cstring>
//#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
bool flag[10];

bool check(int x)
{
	bool backup[10];
	memcpy(backup, flag, sizeof(flag));
	while (x)
	{
		if (!backup[x % 10]) return false;
		backup[x % 10] = false;
		x /= 10;
	}
	if (!backup[0]) return false;
	for (int i = 1; i <= 9; ++ i)
		if (backup[i]) return false;
	return true;
}

vector<int> ans;

int main()
{
	ans.clear();
	memset(flag, true, sizeof(flag));
	// xx * xxx
	for (int a = 1; a <= 9; ++ a) if (flag[a])
	{
		flag[a] = false;
		for (int b = 1; b <= 9; ++ b) if (flag[b])
		{
			flag[b] = false;
			int x = 10 * a + b;
			for (int c = 1; c <= 9; ++ c) if (flag[c])
			{
				flag[c] = false;
				for (int d = 1; d <= 9; ++ d) if (flag[d])
				{
					flag[d] = false;
					for (int e = 1; e <= 9; ++ e) if (flag[e])
					{
						flag[e] = false;
						int y = c * 100 + d * 10 + e;
						if (check(x * y))
						{
							cout << x << " * " << y << " = " << x * y << endl;
							ans.push_back(x * y);
						}
						flag[e] = true;
					}
					flag[d] = true;
				}
				flag[c] = true;	
			}
			flag[b] = true;
		}
		flag[a] = true;
	}
	
	//x * xxxx
	for (int a = 1; a <= 9; ++ a) if (flag[a])
	{
		flag[a] = false;
		int x = a;
		for (int b = 1; b <= 9; ++ b) if (flag[b])
		{
			flag[b] = false;
			for (int c = 1; c <= 9; ++ c) if (flag[c])
			{
				flag[c] = false;
				for (int d = 1; d <= 9; ++ d) if (flag[d])
				{
					flag[d] = false;
					for (int e = 1; e <= 9; ++ e) if (flag[e])
					{
						flag[e] = false;
						int y = b * 1000 + c * 100 + d * 10 + e;
						if (check(x * y))
						{
							cout << x << " * " << y << " = " << x * y << endl;
							ans.push_back(x * y);
						}
						flag[e] = true;
					}
					flag[d] = true;
				}
				flag[c] = true;	
			}
			flag[b] = true;
		}
		flag[a] = true;
	}
	sort(ans.begin(), ans.end());
	int sum = ans[0];
	for (int i = 1; i < ans.size(); ++ i)
		if (ans[i] != ans[i - 1])
			sum += ans[i];
	cout << sum << endl;
}
