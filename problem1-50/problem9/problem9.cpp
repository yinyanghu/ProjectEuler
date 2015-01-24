#include <iostream>
using namespace std;
const int limit = 1000;
int main()
{
	for (int a = 1; a <= limit; ++ a)
		for (int b = a + 1; a + b < limit; ++ b)
		{
			int c = limit - a - b;
			if (a * a + b * b == c * c)
			{
				cout << a * b * c << endl;
			}
			else if (a * a + b * b > c * c) break;
		}
	return 0;
}
