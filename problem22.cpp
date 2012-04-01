#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
const int limitsize = 10000;

int n = 0;
string s[limitsize];
void init()
{
	freopen("problem22.txt", "r", stdin);
	while (cin >> s[n]) ++ n;
	sort(s, s + n);
}

void work()
{
	int ans = 0;
	for (int i = 0; i < n; ++ i)
	{
		int sum = 0;
		for (int j = 0; j < s[i].size(); ++ j)
			sum += int(s[i][j]) - 64;
		ans += sum * (i + 1);
	}
	cout << ans << endl;
}

int main()
{
	init();
	work();
	return 0;
}
