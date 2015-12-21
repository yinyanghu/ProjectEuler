#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 10000000;
//const int N = 100;

set< pair<int, int> > S;

int factor[N + 1];

pair<int, int> two[N + 1];


void solve() {
    memset(factor, 0, sizeof(factor));
    for (int i = 2; i <= N; ++ i)
        if (factor[i] == 0) {
            factor[i] = 1;
            for (int j = i + i; j <= N; j += i) {
                ++ factor[j];
                if (factor[j] == 1)
                    two[j].first = i;
                else
                    two[j].second = i;
            }
        }

    long long ans = 0;
    for (int x = N; x >= 6; -- x)
        if (factor[x] == 2)
            if (S.find(two[x]) == S.end()) {
                S.insert(two[x]);
                ans += (long long)x;
            }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}