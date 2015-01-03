/*
 *
 * Wikipedia: Continued fraction
 *
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

const int n = 100;

struct Bigint {
	int len;
	int x[400];
	Bigint() {
		len = 0;
		memset(x, 0, sizeof(x));
	}
	Bigint(int key) {
		memset(x, 0, sizeof(x));
		for (len = 0; key != 0; key /= 10, ++ len)
			x[len] = key % 10;
	}
};

Bigint operator + (const Bigint &A, const Bigint &B) {
	int carry = 0;
	Bigint ret;
	
	ret.len = (A.len > B.len ? A.len : B.len);
	for (int i = 0; i < ret.len; ++ i)
	{
		ret.x[i] = A.x[i] + B.x[i] + carry;
		carry = ret.x[i] / 10;
		ret.x[i] %= 10;
	}
	while (carry != 0) {
		ret.x[ret.len ++] = carry % 10;
		carry /= 10;
	}
	return ret;
}

Bigint operator * (const Bigint &A, const int B) {
	int carry = 0;
	Bigint ret;

	ret.len = A.len;
	for (int i = 0; i < ret.len; ++ i)
	{
		ret.x[i] = A.x[i] * B + carry;
		carry = ret.x[i] / 10;
		ret.x[i] %= 10;
	}
	while (carry != 0) {
		ret.x[ret.len ++] = carry % 10;
		carry /= 10;
	}
	return ret;
}


void print(const Bigint& A) {
	for (int i = A.len - 1; i >= 0; -- i)
		cout << A.x[i];
}


int a[n];


Bigint h[n], k[n];

int main() {

	a[0] = 2;
	int p = 0;
	for (int i = 1; i < n; ++ i)
		if ((i - 2) % 3 == 0)
		{
			++ p;	
			a[i] = (p << 1);

		}
		else
			a[i] = 1;

	h[0] = 2; h[1] = 3;
	k[0] = 1; k[1] = 1;

	for (int i = 2; i < n; ++ i)
	{
		h[i] = h[i - 1] * a[i] + h[i - 2];
		k[i] = k[i - 1] * a[i] + k[i - 2];
	}

	for (int i = 2; i < n; ++ i)
	{
		print(h[i]);
		cout << " / ";
		print(k[i]);
		cout << endl;
	}
	
	int ans = 0;
	for (int i = 0; i < h[n - 1].len; ++ i)
		ans += h[n - 1].x[i];
		
	cout << "Answer = " << ans << endl;

	return 0;
}

