#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int INF = 100000000;

const int N = 12000;
//const int N = 12;
const int UB = N * 2;

int minK[N + 1];

void search(int k, int sum, int prod) {
    if (k > 1) {
        int ones = prod - sum;
        int K = ones + k;
        if (K <= N)
            minK[K] = min(minK[K], prod);
    }
    for (int i = 2; i * prod <= UB; ++ i)
        search(k + 1, sum + i, prod * i);
}

set<int> Uniq;

int main() {
    for (int i = 2; i <= N; ++ i)
        minK[i] = INF;
    search(0, 0, 1);

    Uniq.clear();
    for (int k = 2; k <= N; ++ k)
        Uniq.insert(minK[k]);

    int ans = 0;
    for (set<int>::iterator it = Uniq.begin(); it != Uniq.end(); ++ it) {
        ans += *it;
        //cout << *it << endl;
    }
    cout << ans << endl;
    return 0;
}