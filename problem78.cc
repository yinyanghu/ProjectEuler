#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100000;
const int MOD = 1000000;

int P[N + 1];

vector<int> Pentagonal;

void solve() {
    P[0] = 1;
    Pentagonal.clear();
    for (int n = 1; n <= N; ++ n) {
        Pentagonal.push_back(n * (3 * n - 1) / 2);
        Pentagonal.push_back(-n * (3 * -n - 1) / 2);
        P[n] = 0;
        for (int i = 0; i < Pentagonal.size() && Pentagonal[i] <= n; ++ i) {
            int sign = (i % 4 <= 1) ? 1 : -1;
            P[n] = (P[n] + sign * P[n - Pentagonal[i]]) % MOD;
        }
        if (P[n] == 0) {
            cout << n << endl;
            break;
        }
    }
}


int main() {
    solve();
    return 0;
}