#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct word_type {
	string s;
	string re;
	int len;
};


vector<word_type> list;

ifstream fin("problem98.txt");

int n;

string permutate(string A, int len) {
	char k;
	for (int i = 0; i < len - 1; ++ i)
		for (int j = i; j < len; ++ j)
			if (A[i] > A[j])
			{
				k = A[i]; A[i] = A[j]; A[j] = k;
			}
	return A;
}


bool compare(const word_type &A, const word_type &B) {
	return A.re < B.re;
}


bool is_square(int x) {
	int temp = (int)sqrt(x);
	return x == temp * temp;
}



int weight[26];
bool flag[10];

int ans = 0;

string another;

int calc(const string &A) {
	int ret = 0;
	for (int i = 0; i < A.size(); ++ i)
		ret = ret * 10 + weight[A[i] - 'A'];
	return ret;
}

void trying(const string &A, int x) {

	if (x == A.size())
	{
		int aa = calc(A);
		int bb = calc(another);
		if (weight[A[0] - 'A'] != 0 && weight[another[0] - 'A'] && is_square(aa) && is_square(bb))
		{
			if (aa > ans)
				ans = aa;
			if (bb > ans)
				ans = bb;
		}
		return;

	}
	if (weight[A[x] - 'A'] != -1)
	{
		trying(A, x + 1);
		return;
	}
	for (int i = 0; i < 10; ++ i)
		if (flag[i])
		{
			flag[i] = false;
			weight[A[x] - 'A'] = i;
			trying(A, x + 1);
			weight[A[x] - 'A'] = -1;
			flag[i] = true;
		}

}

void check(const string &A, const string &B) {

	
	memset(weight, -1, sizeof(weight));
	memset(flag, true, sizeof(flag));

	another = B;

	trying(A, 0);

}

int main() {
	

	list.clear();


	word_type temp;
	while (fin >> temp.s)
	{
		temp.len = temp.s.size();
		temp.re = permutate(temp.s, temp.len);
		list.push_back(temp);
	}

	sort(list.begin(), list.end(), compare);

	bool lock = false;

	for (int i = 1; i < list.size(); ++ i)
		if (!lock && list[i].re == list[i - 1].re)
		{
			check(list[i - 1].s, list[i].s);
			lock = true;
		}
		else if (list[i].re != list[i - 1].re)
			lock = false;

	cout << ans << endl;

	return 0;
}

