#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100;
const int INF = 100000000;

// Graph - K(n, n)
class MaxCostBipartiteMatching {
public:
    int N;
    int w[MAXN][MAXN];

    int max_cost() {
        // initialize
        max_match = 0;
        int cost = 0;
        memset(left, -1, sizeof(left));
        memset(right, -1, sizeof(right));

        for (int i = 0; i < N; ++ i) {
            costL[i] = costR[i] = 0;
            for (int j = 0; j < N; ++ j) 
                costL[i] = max(costL[i], w[i][j]);
        }

        augment();

        for (int x = 0; x < N; ++ x)
            cost += w[x][left[x]];

        return cost;
    }


private:
    int costL[MAXN], costR[MAXN];
    int left[MAXN], right[MAXN];
    bool S[MAXN], T[MAXN];

    int slack[MAXN];
    int slackX[MAXN];

    int prev[MAXN];
    int max_match;

    queue<int> Q;

    void augment() {
        if (max_match == N) return;

        memset(S, false, sizeof(S));
        memset(T, false, sizeof(T));
        memset(prev, -1, sizeof(prev));

        int root, x, y;

        Q = queue<int>();

        for (x = 0; x < N; ++ x)
            if (left[x] == -1) {
                Q.push(x);
                root = x;
                prev[x] = -2;
                S[x] = true;
                break;
            }

        for (y = 0; y < N; ++ y) {
            slack[y] = costL[root] + costR[y] - w[root][y];
            slackX[y] = root;
        }

        while (1) {
            while (!Q.empty()) {
                x = Q.front(); Q.pop();
                for (y = 0; y < N; ++ y)
                    if (!T[y] && w[x][y] == costL[x] + costR[y]) {
                        if (right[y] == -1) break;
                        T[y] = true;
                        Q.push(right[y]);
                        add2tree(right[y], x);
                    }
                if (y < N) break;
            }
            if (y < N) break;

            update();

            Q = queue<int>();

            for (y = 0; y < N; ++ y)
                if (!T[y] && slack[y] == 0) {
                    if (right[y] == -1) {
                        x = slackX[y];
                        break;
                    }
                    else {
                        T[y] = true;
                        if (!S[right[y]]) {
                            Q.push(right[y]);
                            add2tree(right[y], slackX[y]);
                        }
                    }
                }

            if (y < N) break;
        }

        if (y < N) {
            ++ max_match;
            for (int cx = x, cy = y, k; cx != -2; cx = prev[cx], cy = k) {
                k = left[cx]; right[cy] = cx; left[cx] = cy;
            }

            augment();
        }
    }

    void update() {
        int delta = INF;
        for (int y = 0; y < N; ++ y)
            if (!T[y])
                delta = min(delta, slack[y]);

        for (int x = 0; x < N; ++ x)
            if (S[x])
                costL[x] -= delta;

        for (int y = 0; y < N; ++ y)
            if (T[y])
                costR[y] += delta;
            else
                slack[y] -= delta;

    }

    void add2tree(int x, int prevX) {
        S[x] = true;
        prev[x] = prevX;
        for (int y = 0; y < N; ++ y)
            if (costL[x] + costR[y] - w[x][y] < slack[y]) {
                slack[y] = costL[x] + costR[y] - w[x][y];
                slackX[y] = x;
            }

    }
};

/*
const int N = 5;
const int A[N][N] = {
{  7,  53, 183, 439, 863},
{497, 383, 563,  79, 973},
{287,  63, 343, 169, 583},
{627, 343, 773, 959, 943},
{767, 473, 103, 699, 303}
};
*/


const int N = 15;
const int A[N][N] = {
{  7,  53, 183, 439, 863, 497, 383, 563,  79, 973, 287,  63, 343, 169, 583},
{627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913},
{447, 283, 463,  29,  23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743},
{217, 623,   3, 399, 853, 407, 103, 983,  89, 463, 290, 516, 212, 462, 350},
{960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350},
{870, 456, 192, 162, 593, 473, 915,  45, 989, 873, 823, 965, 425, 329, 803},
{973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326},
{322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601,  95, 973},
{445, 721,  11, 525, 473,  65, 511, 164, 138, 672,  18, 428, 154, 448, 848},
{414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198},
{184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390},
{821, 461, 843, 513,  17, 901, 711, 993, 293, 157, 274,  94, 192, 156, 574},
{ 34, 124,   4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699},
{815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107},
{813, 883, 451, 509, 615,  77, 281, 613, 459, 205, 380, 274, 302,  35, 805}
};

int main() {
    MaxCostBipartiteMatching solver;

    solver.N = N;
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            solver.w[i][j] = A[i][j];

    cout << solver.max_cost() << endl;
    return 0;
}