#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


struct poker_type {
	int x;
	char color;
};


poker_type A[5], B[5];

ifstream fin("problem54.txt");

inline int poker(char x) {
	if (x >= '2' && x <= '9') return int(x) - int('0');
	if (x == 'T') return 10;
	if (x == 'J') return 11;
	if (x == 'Q') return 12;
	if (x == 'K') return 13;
	return 14;
}


inline poker_type map(string A) {
	poker_type ret;
	ret.x = poker(A[0]);
	ret.color = A[1];
	return ret;
}

bool compare(const poker_type &A, const poker_type &B) {
	if (A.x < B.x) return true;
	if (A.x > B.x) return false;
	return A.color < B.color;
}



/*
 *
 * High Card = 1
 * One Pair = 2
 * Two Pair = 3
 * Three of a Kind = 4
 * Straight = 5
 * Flush = 6
 * Full Horse = 7
 * Four of a Kind = 8
 * Straight Flush = 9
 * Royal Flush = 10
 *
 */

int rank(int id) {

	poker_type *X;

	if (id == 0)
		X = A;
	else
		X = B;

	int count_value[15];
	
	memset(count_value, 0, sizeof(count_value));

	for (int i = 0; i < 5; ++ i)
		++ count_value[X[i].x];


	bool same_color = true;


	for (int i = 1; i < 5; ++ i)
		if (X[i].color != X[i - 1].color)
		{
			same_color = false;
			break;
		}


	bool consecutive = true;

	for (int i = 1; i < 5; ++ i)
		if (X[i - 1].x + 1 != X[i].x)
		{
			consecutive = false;
			break;
		}

	bool flag1 = same_color;

	bool flag2 = consecutive;
	
	if (flag1 && flag2 && X[0].x == 10) return 10;

	if (flag1 && flag2) return 9;

	flag1 = false;
	int temp = 0;
	
	for (int i = 2; i <= 14; ++ i)
	{
		if (count_value[i] == 4)
			return 8;
		else if (count_value[i] == 3)
			flag1 = true;
		else if (count_value[i] == 2)
			++ temp;
	}

	if (flag1 && temp == 1) return 7;

	if (same_color) return 6;

	if (consecutive) return 5;

	if (flag1) return 4;
	
	if (temp == 2) return 3;

	if (temp == 1) return 2;
	
	return 1;

}


bool check(int rank) {


	if (rank == 9 || rank == 5)
		return (A[4].x > B[4].x);

	int count_A[15];	
	int count_B[15];
	memset(count_A, 0, sizeof(count_A));
	memset(count_B, 0, sizeof(count_B));
	for (int i = 0; i < 5; ++ i)
	{
		++ count_A[A[i].x];
		++ count_B[B[i].x];
	}

	if (rank == 8)
	{
		int AA, BB, aa, bb;
		for (int i = 2; i <= 14; ++ i)
		{
			if (count_A[i] == 4)
				AA = i;
			else
				aa = i;
			if (count_B[i] == 4)
				BB = i;
			else
				bb = i;
		}
		return (AA > BB || (AA == BB && aa > bb));
	}

	if (rank == 7)
	{
		int AA, BB, aa, bb;
		for (int i = 2; i <= 14; ++ i)
		{
			if (count_A[i] == 3)
				AA = i;
			else if (count_A[i] == 2)
				aa = i;
			if (count_B[i] == 3)
				BB = i;
			else if (count_B[i] == 2)
				bb = i;
		}

		return (AA > BB || (AA == BB && aa > bb));
	}
	
	if (rank == 6 || rank == 1)
	{
		for (int i = 4; i >= 0; ++ i)
			if (A[i].x > B[i].x)
				return true;
			else if (A[i].x < B[i].x)
				return false;
	}


	if (rank == 4)
	{
		int boxA[3], boxB[3];
		int pointerA = 0, pointerB = 0;

		int AA, BB;
		for (int i = 2; i <= 14; ++ i)
		{
			if (count_A[i] == 3)
				AA = i;
			else if (count_A[i] == 1)
				boxA[pointerA ++] = i;
			if (count_B[i] == 3)
				BB = i;
			else if (count_B[i] == 1)
				boxB[pointerB ++] = i;
		}
		if (AA > BB) return true;
		if (AA < BB) return false;
		for (int i = 1; i >= 0; ++ i)
			if (boxA[i] > boxB[i])
				return true;
			else if (boxA[i] < boxB[i])
				return false;
	}

	if (rank == 3)
	{
		int boxA[3], boxB[3], AA, BB;
		int pointerA = 0, pointerB = 0;
		for (int i = 2; i <= 14; ++ i)
		{
			if (count_A[i] == 2)
				boxA[pointerA ++] = i;
			else
				AA = i;
			if (count_B[i] == 2)
				boxB[pointerB ++] = i;
			else
				BB = i;
		}
		for (int i = 1; i >= 0; ++ i)
			if (boxA[i] > boxB[i])
				return true;
			else if (boxA[i] < boxB[i])
				return false;
		if (AA > BB) return true;
		if (AA < BB) return false;
	}
			

	if (rank == 2)
	{
		int boxA[3], boxB[3];
		int pointerA = 0, pointerB = 0;

		int AA, BB;
		for (int i = 2; i <= 14; ++ i)
		{
			if (count_A[i] == 2)
				AA = i;
			else if (count_A[i] == 1)
				boxA[pointerA ++] = i;
			if (count_B[i] == 2)
				BB = i;
			else if (count_B[i] == 1)
				boxB[pointerB ++] = i;
		}
		if (AA > BB) return true;
		if (AA < BB) return false;
		for (int i = 2; i >= 0; ++ i)
			if (boxA[i] > boxB[i])
				return true;
			else if (boxA[i] < boxB[i])
				return false;
	}
	
}
	

int main() {

	int ans = 0;
	string temp[10];
	while (fin >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6] >> temp[7] >> temp[8] >> temp[9])
	{

		for (int i = 0; i < 5; ++ i)
		{
			A[i] = map(temp[i]);
			B[i] = map(temp[i + 5]);
		}
		
		sort(A, A + 5, compare);
		sort(B, B + 5, compare);

		int rank_A = rank(0);
		int rank_B = rank(1);

		
		if (rank_A > rank_B || (rank_A == rank_B && check(rank_A)))
			++ ans;
	}

	cout << ans << endl;
	return 0;
}
