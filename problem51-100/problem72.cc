#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000000;

vector<int> Prime;

bool p[N + 1];

void generate_primes() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (int i = 2; i <= N; ++ i)
        if (p[i]) {
            Prime.push_back(i);
            for (int j = i + i; j <= N; j += i)
                p[j] = false;
        }
}


int phi[N + 1];

void find_phi() {
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 0; i < Prime.size(); ++ i)
        phi[Prime[i]] = Prime[i] - 1;

    for (int i = 2; i <= N; ++ i)
        if (phi[i] == 0) {
            for (int j = 0; j < Prime.size(); ++ j)
                if (i % Prime[j] == 0) {
                    int k = i / Prime[j];
                    if (k % Prime[j] == 0)
                        phi[i] = phi[k] * Prime[j];
                    else
                        phi[i] = phi[k] * (Prime[j] - 1);
                    break;
                }
        }

    long long ans = 0;
    for (int i = 2; i <= N; ++ i) {
        ans += (long long)phi[i];
        //cout << phi[i] << endl;
    }

    cout << ans << endl;
}

int main() {
    generate_primes();
    find_phi();
    return 0;
}