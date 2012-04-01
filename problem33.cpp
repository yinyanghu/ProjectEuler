#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-10;
struct node
{
	double key;
	int a, b;
} fraction;

vector<node> list;

bool cmp(node x, node y)
{
	return x.key + eps < y.key;
}

bool prime(int x)
{
	for (int i = 2; i <= int(sqrt(x)) + 1; ++ i)
		if (x % i == 0) return false;
	return true;
}

int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}

bool check(int a, int b)
{
	return (b % 10 == a % 10 || b % 10 == a / 10 || a % 10 == b / 10 || a / 10 == b / 10);
}

int main()
{
	list.clear();
	for (fraction.b = 2; fraction.b <= 9; ++ fraction.b)
		for (fraction.a = 1; fraction.a < fraction.b; ++ fraction.a)
		{
			fraction.key = double(fraction.a) / fraction.b;
			list.push_back(fraction);
		}
	for (fraction.b = 11; fraction.b <= 99; ++ fraction.b)
		if (!prime(fraction.b))
			for (fraction.a = 10; fraction.a < fraction.b; ++ fraction.a)
				if (gcd(fraction.a, fraction.b) != 1 && check(fraction.a, fraction.b))
				{
					fraction.key = double(fraction.a) / fraction.b;
					for (int i = 0; i < list.size(); ++ i)
						if (abs(list[i].key - fraction.key) < eps)
						{
							list.push_back(fraction);
							break;
						}
				}
	sort(list.begin(), list.end(), cmp);
	for (int i = 0; i < list.size(); ++ i)
		cout << list[i].a << "/" << list[i].b << "   " << list[i].key << endl;
	return 0;
}
/*

19/95
1/5

1/4
16/64

2/5
26/65

49/98
4/8

Answer = 100

*/
