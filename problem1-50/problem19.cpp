#include <iostream>
using namespace std;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int year)
{
	if (year % 100 == 0)
		return (year % 400 == 0);
	return (year % 4 == 0);
}
int main()
{
	int total = 3, ans = 0;
	for (int year = 1901; year <= 2000; ++ year)
	{
		bool leap = check(year);
		for (int month = 0; month < 12; ++ month)
		{
			if (total == 0) ++ ans;
			total += day[month];
			if (leap && month == 1) ++ total;
			total %= 7;
		}
	}
	cout << ans << endl;
	return 0;
}
