#include <iostream>
using namespace std;
const int limit = 1000000;
int power5(int a)
{
	return a * a * a * a * a;
}
int split(int x)
{
	int ret = 0;
	while (x)
	{
		ret += power5(x % 10);
		x /= 10;
	}
	return ret;
}
int main()
{
	int sum = 0;
	for (int i = 2; i <= limit; ++ i)
		if (split(i) == i)
		{
			sum += i;
			cout << i << endl;
		}	
	cout << "Sum = " << sum << endl;
	return 0;
}
