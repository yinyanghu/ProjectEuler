#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 80;

int A[N][N];

void input_matrix() {
    //FILE *file = fopen("test.txt", "r");
    FILE *file = fopen("matrix.txt", "r");

    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j)
            fscanf(file, "%d", &A[i][j]);

    fclose(file);
}

const int V = N * N;
int E;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

struct {
    int x, y, cost;
} edge[4 * V];

int start[V];

void build_graph() {
    E = 0;
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < N; ++ j) {
            int v = i * N + j;
            start[v] = E;
            for (int k = 0; k < 4; ++ k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    int u = x * N + y;
                    edge[E].x = v;
                    edge[E].y = u;
                    edge[E].cost = A[x][y];
                    ++ E;
                }
            }
        }
}

const int INF = 1000000000;

int dist[V];
queue<int> Q;
bool inQ[V];

void SPFA() {
    for (int i = 1; i < V; ++ i)
        dist[i] = INF;
    dist[0] = A[0][0];

    memset(inQ, false, sizeof(inQ));
    Q.push(0);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        inQ[x] = false;
        for (int i = start[x]; i < E && edge[i].x == x; ++ i) {
            int y = edge[i].y;
            //cout << x << " " << y << endl;
            if (dist[x] + edge[i].cost < dist[y]) {
                dist[y] = dist[x] + edge[i].cost;
                if (!inQ[y]) {
                    inQ[y] = true;
                    Q.push(y);
                }
            }
        }
        /*
        for (int i = 0; i < V; ++ i)
            cout << dist[i] << " ";
        cout << endl;
        */
    }

    cout << dist[V - 1] << endl;
}

int main() {
    input_matrix();
    build_graph();
    SPFA();
    return 0;
}