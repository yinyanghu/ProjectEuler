#include <iostream>
using namespace std;
const
	int n = 100;
int main()
{
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; ++ i)
	{
		sum1 += i * i;
		sum2 += i;
	}
	int ans = sum2 * sum2 - sum1;
	cout << ans << endl;
	return 0;
}

/*
Answer = 25164150
*/
