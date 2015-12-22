#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//const int N = 4;
const int N = 100;

inline int gcd(int x, int y) {
    for (int k; y; k = x, x = y, y = k % y);
    return x;
}

inline bool is_squre(int x) {
    int k = (int)sqrt(x);
    return k * k == x;
}

int F[N + 1][N + 1];

inline int calc(int a, int b, int c, int d) {
    int twoA = a * b + b * c + c * d + d * a;
    return (twoA - F[a][b] - F[b][c] - F[c][d] - F[d][a] + 2) >> 1;
}

int main() {
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            F[i][j] = F[j][i] = gcd(i ,j);

    int ans = 0;

    for (int a = 1; a <= N; ++ a)
        for (int b = 1; b <= N; ++ b)
            for (int c = 1; c <= N; ++ c)
                for (int d = 1; d <= N; ++ d)
                    if (is_squre(calc(a, b, c, d))) ++ ans;
    cout << ans << endl;

    return 0;
}