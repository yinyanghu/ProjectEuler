#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N = 1 << 30;
    cout << N << endl;
    int ans = 0;
    for (int k = 1; k <= N; ++ k) {
        long long one, two, three;
        one = (long long)k;
        two = ((long long)k) << 1;
        three = one + two;
        if ((one ^ two ^ three) == 0) ++ ans;
    }
    cout << ans << endl;
    return 0;
}