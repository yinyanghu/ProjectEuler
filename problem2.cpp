#include <iostream>
using namespace std;
const
	int limit = 4000000;
int main()
{
	int a = 1, b = 2;
	int c = a + b;
	int ans = 2;
	while (c <= limit)
	{
		if (c % 2 == 0) ans += c;
		a = b; b = c;
		c = a + b;
	}
	cout << ans << endl;
	return 0;
}

/*
Answer = 4613732
*/
