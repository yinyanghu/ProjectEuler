/*
 *
 * x --> #blue disc, y --> #total
 *
 * 2x(x+1) = y(y+1) --> 2x^2 - y^2 - 2x + y = 0
 *
 * Diophantine Quadratic Equation
 *
 * solution: http://www.alpertron.com.ar/QUAD.HTM
 *
 * Method of undetermined coefficients
 *
 * x0 = 1, y0 = 1
 * 
 * x' = 3x + 2y - 2
 * y' = 4x + 3y - 3
 *
 *
 * Diophantine pairs
 *
 */

#include <iostream>

using namespace std;


const long long limit = 1000000000000LL;

int main() {

	long long x = 1;
	long long y = 1;

	long long temp_x, temp_y;

	while (y < limit)
	{
		temp_x = 3 * x + 2 * y - 2;
		temp_y = 4 * x + 3 * y - 3;
		x = temp_x;
		y = temp_y;
	}

	cout << x << endl;

	return 0;
}


/*
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


const long long start = 1000000000000LL;
const long long gen = start >> 1;

set<long long> pool;

int main() {

	pool.clear();
	
	long long temp_x, temp_y;
	for (long long x = gen; ; ++ x)
	{
		temp_x = x * (x - 1);
		pool.insert(temp_x);
		if (x > start)
		{
			temp_y = temp_x >> 1;
			if (pool.find(temp_y) != pool.end())
			{
				cout << x << endl;
				break;
			}
		}
	}

	return 0;
}
*/
