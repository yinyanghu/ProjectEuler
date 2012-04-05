#include <iostream>

using namespace std;

const int n = 1000000;
const double x = 3.0/7.0;

int a, b; 

double gap = 10.000000;

int ans;

int main() {

	for (int b = n - 50; b <= n; ++ b)
	{
		a = int(b * x);
		double temp = x - (double)a / b;
		if (temp < gap)
		{
			gap = temp;
			ans = a;
		}
	}

	cout << ans << endl;

	return 0;
}
