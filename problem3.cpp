#include <iostream>
using namespace std;
long long num = (long long)(600851475143.0);
int main()
{
	
	int prime = 1;
	while (num != 1)
	{
		++ prime;
		while (num % prime == 0) num = num / prime;
	}
	cout << prime << endl;
	return 0;
}

/*
Answer = 6857
*/
