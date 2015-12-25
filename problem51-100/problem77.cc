#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN    100

const int M = 5000;
int F[MAXN];

bool p[MAXN];
vector<int> Prime;
void generat_primes() {
    memset(p, true, sizeof(p));
    Prime.clear();
    p[0] = p[1] = false;
    for (int i = 2; i < MAXN; ++ i)
        if (p[i]) {
            Prime.push_back(i);
            for (int j = i + i; j < MAXN; j += i)
                p[j] = false;
        }
}

int main() {
    generat_primes();
    memset(F, 0, sizeof(F));
    F[0] = 1;
    F[1] = 0;
    for (int i = 0; i < Prime.size(); ++ i)
        for (int j = Prime[i]; j < MAXN; ++ j)
            F[j] += F[j - Prime[i]];
    int ans;
    for (int i = 0; i < MAXN; ++ i)
        if (F[i] > M) {
            ans = i;
            break;
        }
    cout << ans << endl;
    return 0;
}