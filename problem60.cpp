#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

#define prime_limit		500000
#define prime_size		1500

using namespace std;

bool isprime[prime_limit];

bool graph[prime_size][prime_size];

vector<int> prime;

int n;

int get_prime()
{
	memset(isprime, true, sizeof(isprime));
	for (int x = 2; x < prime_limit; ++ x)
		if (isprime[x])
			for (int i = x + x; i < prime_limit; i += x)
				isprime[i] = false;

	prime.clear();
	for (int x = 2; x < prime_limit; ++ x)
		if (isprime[x])
			prime.push_back(x);

	return prime_size;
}


bool check_prime(int x)
{
	int k = int(sqrt(x));
	for (int i = 0; prime[i] <= k; ++ i)
		if (x % prime[i] == 0) return false;
	return true;
}

void create_graph()
{
	memset(graph, false, sizeof(graph));
	int p, q;
	for (int i = 0; i < n - 1; ++ i)
		for (int j = i + 1; j < n; ++ j)
		{
			p = q = 1;
			while (p <= prime[i]) p *= 10;
			while (q <= prime[j]) q *= 10;
			if (check_prime(prime[i] * q + prime[j]) && check_prime(prime[j] * p + prime[i]))
				graph[i][j] = graph[j][i] = true;
		}
}

bool find_clique()
{
	for (int a = 0; a < n - 4; ++ a)
		for (int b = a + 1; b < n - 3; ++ b)
			if (graph[a][b])
			for (int c = b + 1; c < n - 2; ++ c)
				if (graph[a][c] && graph[b][c])
				for (int d = c + 1; d < n - 1; ++ d)
					if (graph[a][d] && graph[b][d] && graph[c][d])
					for (int e = d + 1; e < n; ++ e)
						if (graph[a][e] && graph[b][e] && graph[c][e] && graph[d][e])
						{
							cout << prime[a] << endl;
							cout << prime[b] << endl;
							cout << prime[c] << endl;
							cout << prime[d] << endl;
							cout << prime[e] << endl;
							cout << prime[a] + prime[b] + prime[c] + prime[d] + prime[e] << endl;
							return true;
						}
	return false;
}

int main()
{
	n = get_prime();
	create_graph();
	if (find_clique())
		cout << "Congratulation!" << endl;
	else
		cout << "@_@" << endl;
	return 0;
}
