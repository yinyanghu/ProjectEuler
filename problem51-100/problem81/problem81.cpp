#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("problem81.txt");

const int n = 80;

int a[n][n];

int f[n][n];

inline int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {

	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			fin >> a[i][j];

	f[0][0] = a[0][0];

	for (int i = 1; i < n; ++ i)
		f[0][i] = f[0][i - 1] + a[0][i];

	for (int i = 1; i < n; ++ i)
		f[i][0] = f[i - 1][0] + a[i][0];
	
	for (int i = 1; i < n; ++ i)
		for (int j = 1; j < n; ++ j)
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
		
	cout << f[n - 1][n - 1] << endl;
	

	return 0;
}
