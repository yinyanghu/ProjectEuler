#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int n = 100;
const double eps = 1e-10;
vector<double> x;
int main()
{
	x.clear();
	for (int i = 2; i <= n; ++ i)
		for (int j = 2; j <= n; ++ j)
			x.push_back(j * log(i));
	sort(x.begin(), x.end());
	int ans = 1;
	for (int i = 1; i < x.size(); ++ i)
		if (abs(x[i] - x[i - 1]) >= eps)
			++ ans;
	cout << ans << endl;
	return 0;
}
