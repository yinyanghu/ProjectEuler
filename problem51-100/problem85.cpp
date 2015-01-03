/*
 *
 * If you imagine a rectangular grid measuring a units across and b units down.
 * There are a + 1 vertical lines and b + 1 horizontal lines.
 * Each rectangle formed on this grid is made up of two vertical lines and two horizontal lines.
 * As there are C(a + 1, 2)=a(a + 1)/2 ways of picking two vertical lines.
 * And, similarly, b(b + 1)/2, ways of picking two horizontal lines.
 * Hence, there are a(a + 1)b(b + 1)/4 rectangles on an a by b rectangular grid.
 *
 *
 */

#include <iostream>

using namespace std;

const int limit = 2000000;

int ans, diff = 1000000000;

int abs(int x)
{
	return (x < 0) ? -x : x;
}

int main()
{
	for (int i = 1; i <= 2000; ++ i)
	{
		for (int j = 1; j <= 2000; ++ j)
		{
			long long k = (i * (i + 1) >> 1) * (j * (j + 1)) >> 1;
			if (abs(k - limit) < diff)
			{
				diff = abs(k - limit);
				ans = i * j;
			}
			if (k >= limit) break;
		}
	}

	cout << ans << endl;
	cout << diff << endl;

	return 0;
			
}


/*
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 2010;
const int maxm = 2010;
const int limit = 2000000;

int f[maxn + 1][maxn + 1];

int abs(int x)
{
	return (x < 0) ? -x : x;
}

int main()
{
	int min_dist = 1000000000;
	int ans;
	for (int i = 1; ; ++ i)
	{
		f[1][i] = (i * (i + 1)) >> 1;
		if (abs(f[1][i] - limit) < min_dist)
		{
			min_dist = abs(f[1][i] - limit);
			ans = i;
		}
		if (f[1][i] >= limit) break;
	}

	for (int i = 2; ; ++ i)
	{
		f[i][1] = f[i - 1][1] + i;
		if (abs(f[i][1] - limit) < min_dist)
		{
			min_dist = abs(f[i][1] - limit);
			ans = i;
		}
		if (f[i][1] >= limit) break;
		for (int j = 2; ; ++ j)
		{
			f[i][j] = f[i - 1][j] + (((j + 1) * j) >> 1) * i;
			if (abs(f[i][j] - limit) < min_dist)
			{
				min_dist = abs(f[i][j] - limit);
				ans = i * j;
			}
			if (f[i][j] >= limit) break;
		}
	}


	cout << ans << endl;
	cout << min_dist << endl;

	return 0;
}
*/
