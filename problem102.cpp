/*
 * Using the area of triangle
 *
 * if origin in triangle, S(ABC) = S(AOB) + S(AOC) + S(BOC)
 *
 */
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct vec
{
	int x, y;
};

vec operator - (const vec &A, const vec &B)
{
	vec temp;
	temp.x = A.x - B.x;
	temp.y = A.y - B.y;
	return temp;
}

ifstream fin("problem102.txt");

vec A, B, C;

inline int abs(int x)
{
	return (x < 0) ? -x : x;
}

int cross_product(const vec &X, const vec &Y)
{
	return abs(X.x * Y.y - X.y * Y.x);
}

int main()
{
	int ans = 0;
	for (int t = 0; t < 1000; ++ t)
	{
		fin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
		int area = cross_product(B - A, C - A);
		if (cross_product(A, B) + cross_product(A, C) + cross_product(B, C) == area)
			++ ans;
	}
	cout << ans << endl;


	return 0;
}


