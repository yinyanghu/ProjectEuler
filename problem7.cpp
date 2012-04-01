#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const
	int limit = 1000000;
	int ans = 10001;
bool flag[limit];
void makelist()
{
	memset(flag, true, sizeof(flag));
	for (int i = 2; i < sqrt(limit); ++ i)
	{
		while (!flag[i]) ++ i;
		for (int j = 2; i * j <= limit; ++ j) flag[i * j] = false;
	}
}

int main()
{
	makelist();
	int total = 0;
	for (int i = 2; i < limit; ++ i)
		if (flag[i])
		{
			++ total;
			if (total == ans)
			{
				cout << i << endl;
				return 0;
			}
		}
	return 0;
}

/*
Answer = 104743
*/
