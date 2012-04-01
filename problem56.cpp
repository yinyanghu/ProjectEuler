#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 300;
struct bigint
{
	int len;
	int x[limitsize];
	int sum()
	{
		int ret = 0;
		for (int i = 0; i < len; ++ i)
			ret += x[i];
		return ret;
	}
	void clear()
	{
		len = 0;
		memset(x, 0, sizeof(x));
	}
	void key(int p)
	{
		clear();
		while (p)
		{
			x[len ++] = p % 10;
			p /= 10;
		}
	}
};

bigint operator * (const bigint &a, const int b)
{
	bigint ret;
	ret.clear();
	ret.len = a.len;
	for (int i = 0; i < ret.len; ++ i)
	{
		ret.x[i] += a.x[i] * b;
		ret.x[i + 1] += ret.x[i] / 10;
		ret.x[i] %= 10;
	}
	while (ret.x[ret.len])
	{
		ret.x[ret.len + 1] += ret.x[ret.len] / 10;
		ret.x[ret.len ++] %= 10;
	}
	return ret;
}

int main()
{
	bigint cur;
	int ans = 0, sum;
	for (int a = 1; a < 100; ++ a)
	{
		cur.key(1);
		for (int b = 1; b < 100; ++ b)
		{
			cur = cur * a;
			if ((sum = cur.sum()) > ans)
				ans = sum;
		}
	}
	cout << ans << endl;
	return 0;
}
