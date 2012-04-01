#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 1000000;
int ans = 0, record;
int f[limitsize];
int find(long long x)
{
	int len = 1;
	for (; x != 1; ++ len)
	{
		x = (x % 2 == 1) ? x * 3 + 1 : (x >> 1);
		if (x < limitsize && f[x] != 0) return (len + f[x]);
	}
	return len;
}
int main()
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i < limitsize; ++ i)
	{
		f[i] = find(i);
		if (f[i] > ans)
		{
			ans = f[i];
			record = i;
		}
	}
	cout << record << endl;
	return 0;
}
