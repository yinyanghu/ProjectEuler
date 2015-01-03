#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define Mod			389
#define hash(a,b,c)	(a*881+b*79+c)%Mod
#define maxlength	500

using namespace std;

int a[maxlength];
int d[maxlength];
int m[maxlength];

bool hash[Mod];
vector<int> hashtable[Mod];

/* Continued fraction expansion */
int CFE(int S)
{
	memset(hash, true, sizeof(hash));
	for (int i = 0; i < Mod; ++ i)
		hashtable[i].clear();

	m[0] = 0;
	d[0] = 1;
	a[0] = int(sqrt(S));

	int k = hash(m[0], d[0], a[0]);
	hash[k] = false;
	hashtable[k].push_back(0);

	for (int i = 1; ; ++ i)
	{
		m[i] = d[i - 1] * a[i - 1] - m[i - 1];
		d[i] = (S - m[i] * m[i]) / d[i - 1];
		a[i] = (a[0] + m[i]) / d[i];
		
		k = hash(m[i], d[i], a[i]);
		if (!hash[k])
		{
			for (int j = 0; j < hashtable[k].size(); ++ j)
			{
				int ptr = hashtable[k][j];
				if (m[i] == m[ptr] && d[i] == d[ptr] && a[i] == a[ptr])
					return (i - ptr);
			}
		}
		hash[k] = false;
		hashtable[k].push_back(i);
	}
}

int main()
{
	int ans = 0;	
	for (int i = 2; i <= 10000; ++ i)
	{
		int k = int(sqrt(i));
		if (k * k == i) continue;
		int period = CFE(i);
		cout << i << " = " << period << endl;
		if ((period & 1) == 1) ++ ans;
	}
	cout << ans << endl;
	return 0;
}

/*
Wikipedia:
http://en.wikipedia.org/wiki/Continued_fraction
http://en.wikipedia.org/wiki/Periodic_continued_fraction
http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion

*/


/*
// Diophantine Equation X^2 - D * Y^2 = 1
int Diophantine(int D)
{
	long long y = 1;
	while (1)
	{
		//printf("%d\n", y);
		long long k = D * y * y + 1;
		long long x = (long long)sqrt(k);
		if (x * x == k)
			return x;
		++ y;
	}
}

int main()
{
	int N = 600;
	int ans = 0;
	for (int D = 2; D <= N; ++ D)
	//int D = 53;
	{
		int temp = int(sqrt(D));
		if (temp * temp == D) continue;
		int ret = Diophantine(D);
		if (ret > ans) ans = ret;
		printf("%d: %d\n", D, ret);
	}
	printf("%d\n", ans);
	return 0;
}
*/
