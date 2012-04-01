#include <iostream>
#include <cstdio>
using namespace std;
const int n = 1000;
int f[n];
int main()
{
	freopen("problem8.txt", "r", stdin);
	for (int i = 0; i < n; ++ i)
	{
		char ch;
		cin >> ch;
		f[i] = ch - '0';
	}
	int ans = 0;
	for (int i = 0; i < n - 4; ++ i)
	{
		int k = 1;
		for (int j = i; j < i + 5; ++ j)
			k *= f[j];
		ans = (k > ans) ? k : ans;
	}
	cout << ans << endl;
	return 0;
}

/*
Answer = 40824
*/
