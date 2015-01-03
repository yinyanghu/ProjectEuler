#include <iostream>
using namespace std;
const int limit = 500;
bool check(int x)
{
	int k = 1;
	for (int i = 2; x != 1; ++ i)
		if (x % i == 0)
		{
			int p = 0;
			while (x % i == 0)
			{
				x /= i;
				++ p;
			}
			k *= (p + 1);
		}
	return (k > limit);
}
int main()
{
	int total = 0;
	for (int n = 1; ; ++ n)
	{
		total += n;
		if (check(total))
		{
			cout << total << endl;
			return 0;
		}
	}
	return 0;
}
