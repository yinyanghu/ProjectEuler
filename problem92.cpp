#include <iostream>
#include <cstring>

using namespace std;

const int limit = 10000000;

int f[limit];

int trying(int x) {
	if (f[x] != -1) return f[x];
	
	int next = 0;
	for (int k = x; k != 0; k /= 10)
		next += (k % 10) * (k % 10);
	f[x] = trying(next);
	return f[x];
}

int main() {

	memset(f, -1, sizeof(f));
	f[1] = 1; f[89] = 89;
	for (int i = 1; i <= limit; ++ i)
		if (f[i] == -1)
			trying(i);

	int total = 0;

	for (int i = 1; i <= limit; ++ i)
		if (f[i] == 89) ++ total;

	cout << total << endl;

	return 0;
}
