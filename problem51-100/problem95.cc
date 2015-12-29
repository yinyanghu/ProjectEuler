#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int N = 1000000;

int F[N + 1];
int Cycle[N + 1];


inline int factors(int x) {
    int k = (int)sqrt(x);
    int ret = 1;
    for (int i = 2; i < k; ++ i)
        if (x % i == 0)
            ret += i + x / i;
    if (k * k == x)
        ret += k;
    if (ret > N) return -1;
    return ret;
}

inline int find_cycle(int x) {
    int len = 1;
    vector<int> change;
    for (int i = F[x]; i != x; i = F[i]) {
        if (Cycle[i] != -1) {
            len = 0;
            break;
        }
        Cycle[i] = 0;
        change.push_back(i);
        ++ len;
    }
    if (len == 0) {
        Cycle[x] = 0;
        for (int i = 0; i < change.size(); ++ i)
            Cycle[change[i]] = -1;
        return 0;
    }
    Cycle[x] = len;
    for (int i = 0; i < change.size(); ++ i)
        Cycle[change[i]] = len;
    return len;
}

int main() {
    memset(F, -1, sizeof(F));
    F[1] = 0;
    for (int i = 2; i <= N; ++ i)
        if (F[i] == -1)
            F[i] = factors(i);

    cout << "[OK] compute F[]" << endl;
    memset(Cycle, -1, sizeof(Cycle));
    Cycle[1] = 0;
    int maxCycle = -1;
    int ans;
    for (int i = 1; i <= N; ++ i)
        if (Cycle[i] == -1) {
            int k = find_cycle(i);
            if (k > maxCycle) {
                maxCycle = k;
                ans = i;
            }
        }

    cout << ans << endl;
    cout << maxCycle << endl;

    //cout << F[12496] << endl;
    //cout << F[14536] << endl;
    return 0;
}