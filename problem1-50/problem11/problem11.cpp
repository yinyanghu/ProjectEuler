#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("problem11.txt");
const int n = 20;
int a[n + 1][n + 1];
int main()
{
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			fin >> a[i][j];
	int ans = -1;
	int temp;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
		{
			if (i + 3 <= n)
			{
				temp = a[i][j];
				for (int k = 1; k <= 3; ++ k)
					temp *= a[i + k][j];
				ans = max(temp, ans);
			}
			if (j + 3 <= n)
			{
				temp = a[i][j];
				for (int k = 1; k <= 3; ++ k)
					temp *= a[i][j + k];
				ans = max(temp, ans);
			}
			if (i + 3 <= n && j + 3 <= n)
			{
				temp = a[i][j];
				for (int k = 1; k <= 3; ++ k)
					temp *= a[i + k][j + k];
				ans = max(temp, ans);
			}
			if (i + 3 <= n && j - 3 >= 1)
			{
				temp = a[i][j];
				for (int k = 1; k <= 3; ++ k)
					temp *= a[i + k][j - k];
				ans = max(temp, ans);
			}
		}
	cout << ans << endl;
	return 0;
}
