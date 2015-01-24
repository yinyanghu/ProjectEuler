#include <iostream>
#include <cstring>

using namespace std;

const long long trunc = 10000000000LL;


long long ans = 1;

int main() {

	
	for (int i = 1; i <= 7830457; ++ i)
		ans = (ans << 1) % trunc;

	ans = (ans * 28433 + 1) % trunc;

	cout << ans << endl;
	

	return 0;
}

