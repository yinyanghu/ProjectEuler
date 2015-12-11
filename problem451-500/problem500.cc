#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

#define maxP    8000000


bool P[maxP];
vector<int> Primes;

void generate_primes() {
    memset(P, true, sizeof(P));
    Primes.clear();
    P[0] = P[1] = false;
    for (int i = 2; i < maxP; ++ i)
        if (P[i]) {
            Primes.push_back(i);
            for (int j = i + i; j < maxP; j += i)
                P[j] = false;
        }
    cout << "total # primes = " << Primes.size() << endl;
}

const int M = 500500;
const int MOD = 500500507;

void solve() {
    cout << "M = " << M << endl;

    long long ans = 1;
    int factors = 0;
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > H;

    for (int i = 0; i < M; ++ i)
        H.push(make_pair((long long)Primes[i], Primes[i]));

    while (factors < M) {
        int cost = H.top().first;
        int key = H.top().second;
        //cout << cost << " " << key << endl;
        H.pop();
        H.push(make_pair((long long)cost * (long long)cost, key));
        ans = (ans * cost) % MOD;
        ++ factors;
    }
    cout << ans << endl;
}


int main() {
    generate_primes();
    solve();
    return 0;
}