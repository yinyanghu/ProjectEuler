#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int L = 1500000;
const int limitX = int(sqrt(L));
const int limitXY = L / 2;

int C[L + 1];

inline int gcd(int x, int y) {
    while (y != 0) {
        int k = x; x = y; y = k % y;
    }
    return x;
}

inline void update(int l) {
    int mul = l;
    for (int i = l; i <= L; i += l)
        ++ C[i];
}

void find_triple() {
    for (int m = 2; m <= limitX; ++ m) {
        for (int n = 1; n < m; ++ n)
            if (((m - n) & 1) && gcd(m, n) == 1) {
                int l = 2 * m * (m + n);
                if (l > L) break;
                update(l);
            }
    }
}

int main() {
    int ans = 0;
    memset(C, 0, sizeof(C));
    find_triple();
    for (int i = 1; i <= L; ++ i)
        if (C[i] == 1)
            ++ ans;
    printf("%d\n", ans);
    return 0;
}