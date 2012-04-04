#include <iostream>
#include <cstring>

using namespace std;

const int n = 1000000;
const int sqrt = 1000;

int factor[n + 1];
int phi[n + 1];

int best_phi, best_n;

int main() {

	memset(factor, -1, sizeof(factor));
	for (int i = 2; i <= sqrt; ++ i)
		if (factor[i] == -1)
			for (int j = i << 1; j <= n; j += i)
				factor[j] = i;

	memset(phi, 0, sizeof(phi));

	for (int i = 2; i <= sqrt; ++ i)
		if (factor[i] == -1)
		{
			phi[i] = i - 1;
			int last = i - 1;
			for (int x = i * i; x <= n; x *= i)
			{
				last *= i;
				phi[x] = last;
			}
		
		}
	for (int i = sqrt + 1; i <= n; ++ i)
		if (factor[i] == -1)
			phi[i] = i - 1;

	for (int i = 2; i <= n; ++ i)
		if (phi[i] == 0)
		{
			int x;
			for (x = i; (x % factor[i]) == 0; x /= factor[i]);
			phi[i] = phi[i / x] * phi[x];
		}
	


//	for (int i = 499999; i <= 500010; ++ i)
//		cout << phi[i] << endl;

	best_n = 2; best_phi = phi[best_n];
		
	for (int i = 3; i <= n; ++ i)
		if ((long long)best_n * phi[i] < (long long)i * best_phi)
		{
			best_n = i;
			best_phi = phi[i];
		}
	
	cout << best_n << endl;
	cout << best_phi << endl;

	return 0;

}
