#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("problem13.txt");
const int limitsize = 300;
struct bigint
{
	int len;
	int c[limitsize];
	bigint()
	{
		len = 0;
		memset(c, 0, sizeof(c));
	}
	bigint(const char *str)
	{
		len = strlen(str) - 1;
		memset(c, 0, sizeof(c));
		for (int i = len; i >= 0; -- i)
			c[i] = str[len - i] - '0';
	}
	void print(int bit)
	{
		for (int i = len; i > len - bit; -- i)
			cout << c[i];
		cout << endl;
	}
};

bigint operator + (const bigint& a, const bigint& b)
{
	bigint res;
	res.len = max(a.len, b.len);
	int k = 0;
	for (int i = 0; i <= res.len; ++ i)
	{
		res.c[i] = a.c[i] + b.c[i] + k;
		k = res.c[i] / 10;
		res.c[i] %= 10;
	}
	while (k != 0)
	{
		res.c[++ res.len] = k % 10;
		k /= 10;
	}
	return res;
}

int main()
{
	char ch[50];
	bigint ans;
	for (int i = 0; i < 100; ++ i)
	{
		for (int j = 0; j < 50; ++ j)
			fin >> ch[j];
		bigint temp(ch);
		ans = ans + temp;
	}
	ans.print(10);
	return 0;
}
