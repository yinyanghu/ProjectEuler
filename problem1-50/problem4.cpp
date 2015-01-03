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
		len = 0;
		memset(x, 0, sizeof(x));
	}
};
bool check(const bigint &temp)
{
	int left = 0;
	int right = temp.len - 1;
	while ((left < right) && (temp.x[left] == temp.x[right]))
	{
		++ left; -- right;
	}
	return (left >= right);
}

bigint change(int p, int base)
{
	bigint ret;
	ret.clear();
	while (p)
	{
		ret.x[ret.len ++] = p % base;
		p /= base;
	}
	return ret;
}

int main()
{
	int ans = 0;
	for (int i = 999; i > 99; -- i)
		for (int j = 999; j > 99; -- j)
		{
			int cur = i * j;
			if (cur > ans)
			{
				bigint temp = change(cur, 10);
				if (check(temp)) ans = cur;
			}
		}
	cout << ans << endl;
	return 0;
}

/*
Answer = 906609
*/
