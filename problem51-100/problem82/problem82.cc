#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 80;

int A[N][N];

int F[N][N];

void read_matrix() {
    FILE *inf = fopen("matrix.txt", "r");

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            fscanf(inf, "%d", &A[i][j]);

    fclose(inf);
}

void solve() {
    for (int i = 0; i < N; ++ i)
        F[i][0] = A[i][0];

    for (int j = 1; j < N; ++ j) {
        for (int i = 0; i < N; ++ i)
            F[i][j] = F[i][j - 1] + A[i][j];
        for (int k = 0; k < N; ++ k) {
            for (int i = k - 1; i >= 0; -- i)
                F[i][j] = min(F[i][j], F[i + 1][j] + A[i][j]);
            for (int i = k + 1; i < N; ++ i)
                F[i][j] = min(F[i][j], F[i - 1][j] + A[i][j]);
        }
    }

    int ans = 1000000000;
    for (int i = 0; i < N; ++ i)
        ans = min(ans, F[i][N - 1]);
    cout << ans << endl;
}

int main() {
    read_matrix();
    solve();
    return 0;
}