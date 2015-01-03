#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 1000 + 50;
struct bigint
{
	int len;
	int x[limitsize];
};

bigint operator + (const bigint &a, const bigint &b)
{
	bigint ret;
	memset(ret.x, 0, sizeof(ret.x));
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
	if (ret.x[ret.len] != 0) ++ ret.len;
	return ret;
}



int main()
{
	bigint a, b, c;
	memset(a.x, 0, sizeof(a.x));
	memset(b.x, 0, sizeof(b.x));
	a.len = b.len = a.x[0] = b.x[0] = 1; 
	for (int i = 3;; ++ i)
	{
		c = a + b;
		if (c.len == 1000)
		{
			cout << i << endl;
			break;
		}
		a = b; b = c;
	}
	return 0;
}
