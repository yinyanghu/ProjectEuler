#include <iostream>
using namespace std;
const int n = 1001;
int main()
{
	int ans = 1;
	int cur = 1;
	int delta = 0;
	while (cur < n * n)
	{
		delta += 2;
		for (int i = 0; i < 4; ++ i)
		{
			cur += delta;
			ans += cur;
		}
	}
	cout << ans << endl;
	return 0;
}
// 1 3 5 7 9 13 17 21 25 31 37 43 49 ...
