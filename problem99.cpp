#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

ifstream fin("problem99.txt");

int main() {

	int a, b;
	int ans;
	double maximal = 0;

	for (int i = 1; fin >> a >> b; ++ i)
	{
		double temp = b * log(a);
		if (temp > maximal)
		{
			maximal = temp;
			ans = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}

