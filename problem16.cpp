#include <iostream>
#include <cstring>
using namespace std;
const int limitsize = 1000;
struct bigint
{
	int len;
	int c[limitsize];
	bigint()
	{
		memset(c, 0, sizeof(c));
	}
};
bigint ans;
void multiply()
{
	int k = 0;
	for (int i = 0; i < ans.len; ++ i)
	{
		ans.c[i] = (ans.c[i] << 1) + k;
		k = ans.c[i] / 10;
		ans.c[i] %= 10;
	}
	while (k != 0)
	{
		ans.c[++ ans.len - 1] = k % 10;
		k /= 10;
	}
}
int main()
{
	ans.len = 1; ans.c[0] = 1;
	for (int i = 1; i <= 1000; ++ i)
		multiply();
	int total = 0;
	for (int i = 0; i < ans.len; ++ i)
		total += ans.c[i];
	cout << total << endl;
	return 0;
}
