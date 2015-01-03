#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 500;
struct bigint
{
	int len;
	int x[limitsize];
	void clear()
	{
		len = 0;
		memset(x, 0, sizeof(x));
	}
	void key(int p)
	{
		while (p)
		{
			x[len ++] = p % 10;
			p /= 10;
		}
	}
	/*
	void print()
	{
		for (int i = len - 1; i >= 0; -- i)
			cout << x[i];
		cout << endl;
	}
	*/
};

bigint operator + (const bigint &a, const bigint &b)
{
	bigint ret;
	ret.clear();
	ret.len = max(a.len, b.len);
	for (int i = 0; i < ret.len; ++ i)
	{
		ret.x[i] += a.x[i] + b.x[i];
		if (ret.x[i] >= 10)
		{
			++ ret.x[i + 1];
			ret.x[i] -= 10;
		}
	}
	if (ret.x[ret.len]) ++ ret.len;
	return ret;
}

void swap(bigint &a, bigint &b)
{
	bigint k = a; a = b; b = k;
}

int main()
{
	int ans = 0;
	bigint a, b;
	a.key(1); b.key(1);
	for (int i = 1; i <= 1000; ++ i)
	{
		a = a + b;
		swap(a, b);
		a = a + b;
		if (a.len > b.len) ++ ans;
	}
	cout << ans << endl;
	return 0;
}

