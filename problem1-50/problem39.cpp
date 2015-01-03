#include <iostream>
using namespace std;
int find(int x)
{
	int ret = 0;
	for (int a = 1; a <= x / 2; ++ a)
		for (int b = a; a + b < x && x - a - b >= b; ++ b)
			if ((a * 2 + b * 2 > x) && (a * a + b * b == (x - a - b) * (x - a - b)))
				++ ret;
	return ret;
}
int main()
{
	int temp;
	int max_solution = 0, ans;
	for (int p = 12; p <= 1000; ++ p)
		if ((temp = find(p)) > max_solution)
		{
			max_solution = temp;
			ans = p;
		}
	cout << ans << endl;
}
