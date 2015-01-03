#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> F[6];

void generate()
{
	for (int i = 0; i < 6; ++ i)
		F[i].clear();

	for (int i = 1; ; ++ i)
	{
		int k = i * (i + 1) / 2;
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[0].push_back(k);
	}

	for (int i = 1; ; ++ i)
	{
		int k = i * i;
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[1].push_back(k);
	}
	
	for (int i = 1; ; ++ i)
	{
		int k = i * (3 * i - 1) / 2;
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[2].push_back(k);
	}

	for (int i = 1; ; ++ i)
	{
		int k = i * (2 * i - 1);
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[3].push_back(k);
	}

	for (int i = 1; ; ++ i)
	{
		int k = i * (5 * i - 3) / 2;
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[4].push_back(k);
	}

	for (int i = 1; ; ++ i)
	{
		int k = i * (3 * i - 2);
		if (k >= 10000)
			break;
		if (k >= 1000)
			F[5].push_back(k);
	}

}

bool flag[6];

int head;

int list[6];

void dfs(int depth, int tail)
{
	if (depth == 6)
	{
		if (tail == head)
		{
			cout << "Feasible Solution:" << endl;
			int sum = 0;
			for (int i = 0; i < 6; ++ i)
			{
				sum += list[i];
				cout << list[i] << endl;
			}
			cout << "Sum = " << sum << endl;
		}
		return;
	}
	for (int i = 1; i < 6; ++ i)
		if (flag[i])
		{
			flag[i] = false;
			for (int j = 0; j < F[i].size(); ++ j)
				if (tail == F[i][j] / 100)
				{
					list[depth] = F[i][j];
					dfs(depth + 1, F[i][j] % 100);
				}
			flag[i] = true;

		}
}


int main()
{

	generate();
	
	memset(flag, true, sizeof(flag));
	flag[0] = false;
	for (int i = 0; i < F[0].size(); ++ i)
	{
		list[0] = F[0][i];
		head = F[0][i] / 100;
		dfs(1, F[0][i] % 100);
	}

	

	return 0;

}
