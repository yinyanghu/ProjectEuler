#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 100;
struct bigint
{
	int len;
	int x[limitsize];
	void clear()
	{
		memset(x, 0, sizeof(x));
		len = 0;
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

bool palindrome(const bigint &a)
{
	int l = 0, r = a.len - 1;
	while (l < r)
	{
		if (a.x[l] != a.x[r]) return false;
		++ l; -- r;
	}
	return true;
}

bool check(int x)
{
	bigint cur, reverse;
	cur.key(x);
	reverse.len = cur.len;
	for (int i = 0; i < cur.len; ++ i)
		reverse.x[i] = cur.x[cur.len - i - 1];
	int total;

	for (total = 1, cur = cur + reverse; !palindrome(cur) && total < 50; ++ total)
	{
		reverse.len = cur.len;
		for (int i = 0; i < cur.len; ++ i)
			reverse.x[i] = cur.x[cur.len - i - 1];		
		cur = cur + reverse;
	}
	return (total == 50);
}

int main()
{
	int ans = 0;
	for (int i = 10; i < 10000; ++ i)
		if (check(i))
		{
			++ ans;
			cout << i << endl;
		}
	cout << ans << endl;
	return 0;
}

