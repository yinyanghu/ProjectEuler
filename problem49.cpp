#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int limitsize = 10000;
bool prime[limitsize + 1];
int linker[24][4];
int temp[4];
bool flag[4];
int n = 0;
void permutation(int depth)
{
	if (depth == 4)
	{
		for (int i = 0; i < 4; ++ i)
			linker[n][i] = temp[i];
		++ n;
		return;
	}
	for (int i = 0; i < 4; ++ i)
		if (flag[i])
		{
			flag[i] = false;
			temp[depth] = i;
			permutation(depth + 1);
			flag[i] = true;
		}
}
void prepare()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= limitsize; ++ i)
	{
		while (i <= limitsize && !prime[i]) ++ i;
		for (int j = (i << 1); j <= limitsize; j += i)
			prime[j] = false;
	}
	
	memset(flag, true, sizeof(flag));
	permutation(0);
}


int bit[4];

int final[24];
void generate()
{
	for (int i = 0; i < n; ++ i)
		final[i] = bit[linker[i][0]] * 1000 + bit[linker[i][1]] * 100 + bit[linker[i][2]] * 10 + bit[linker[i][3]];
}

long long check()
{
	for (int i = 0; i < 22; ++ i) if (prime[final[i]])
		for (int j = i + 1; j < 23; ++ j) if (prime[final[j]])
		{
			int delta = final[j] - final[i];
			if (delta == 0) continue;
			for (int k = j + 1; k < 24; ++ k)
				if (prime[final[k]] && final[k] - final[j] == delta)
					return (long long)final[i] * 10000 * 10000 + final[j] * 10000 + final[k];
		}
	return -1;	
}

int main()
{
	prepare();
	long long ans;
	for (bit[0] = 1; bit[0] <= 9; ++ bit[0])
		for (bit[1] = bit[0]; bit[1] <= 9; ++ bit[1])
			for (bit[2] = bit[1]; bit[2] <= 9; ++ bit[2])
				for (bit[3] = bit[2]; bit[3] <= 9; ++ bit[3])
				{
					generate();
					if ((ans = check()) != -1)
						cout << ans << endl;
				}
	return 0;
}
