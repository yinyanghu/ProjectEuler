#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 1000;
struct bigint
{
	int len;
	int x[limitsize];
};

bigint operator * (const bigint &a, const int b)
{
	bigint ret;
	ret.len = a.len;
	memset(ret.x, 0, sizeof(ret.x));
	for (int i = 0; i < ret.len; ++ i)
	{
		ret.x[i] += a.x[i] * b;
		ret.x[i + 1] += ret.x[i] / 10;
		ret.x[i] %= 10;
	}
	while (ret.x[ret.len] != 0)
	{
		ret.x[ret.len + 1] += ret.x[ret.len] / 10;
		ret.x[ret.len ++] %= 10;
	}
	return ret;
}

int print(const bigint &a)
{
	int sum = 0;
	for (int i = 0; i < a.len; ++ i)
		sum += a.x[i];
	return sum;
}

int main()
{
	bigint ans;
	ans.len = 1;
	memset(ans.x, 0, sizeof(ans.x));
	ans.x[0] = 1;
	
	for (int i = 2; i <= 100; ++ i)
		ans = ans * i;
	cout << print(ans) << endl;
	return 0;
}
