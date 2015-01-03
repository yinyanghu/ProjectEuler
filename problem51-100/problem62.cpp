#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> hash;

long long permutation(long long x) {
	int a[20];
	int bit;
	for (bit = 0; x != 0; ++ bit, x /= 10)
		a[bit] = x % 10;	

	for (int i = 0; i < bit - 1; ++ i)
		for (int j = i; j < bit; ++ j)
			if (a[i] > a[j])
			{
				int k = a[i]; a[i] = a[j]; a[j] = k;
			}
	
	long long ret = 0;
	for (int i = bit - 1; i >= 0; -- i)
		ret = ret * 10 + a[i];
	return ret;
}

bool check() {
	sort(hash.begin(), hash.end());
	int count = 1;
	for (int i = 1; i < hash.size(); ++ i)
	{
		if (hash[i] == hash[i - 1])
			++ count;
		else
			count = 1;
		if (count == 5) return true;
	}
	return false;
}
	

int main() {

	hash.clear();
	long long n = 0;
	long long k;

	while (!check())
	{
		++ n;
		k = permutation(n * n * n);
		if (k != 0) hash.push_back(k);
	}

	long long ans;
	
	for (long long i = 1; i <= n; ++ i)
		if (k == permutation(i * i * i))
		{
			ans = i * i * i;
			break;
		}
	cout << ans << endl;
}

