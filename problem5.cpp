#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
	long long ans = 1;
	for (int i = 2; i <= 20; ++ i)
		ans = (long long)ans * i / gcd(ans, i);
	cout << ans << endl;
}
