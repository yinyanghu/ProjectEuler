#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10000000;

vector<int> Prime;

bool p[N];
void generate_primes() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (int i = 2; i < N; ++ i)
        if (p[i]) {
            Prime.push_back(i);
            for (int j = i + i; j < N; j += i)
                p[j] = false;
        }
}

bool check_permutation(int x, int y) {
    vector<int> bitsX, bitsY;
    while (x) {
        bitsX.push_back(x % 10);
        x /= 10;
    }
    while (y) {
        bitsY.push_back(y % 10);
        y /= 10;
    }
    if (bitsX.size() != bitsY.size()) return false;
    sort(bitsX.begin(), bitsX.end());
    sort(bitsY.begin(), bitsY.end());
    int n = bitsX.size();
    for (int i = 0; i < n; ++ i)
        if (bitsX[i] != bitsY[i]) return false;
    return true;
}


int phi[N];

void find_phi() {
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 0; i < Prime.size(); ++ i)
        phi[Prime[i]] = Prime[i] - 1;

    for (int i = 2; i < N; ++ i)
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

    double ansMin = (double)N;
    int ans;

    for (int i = 2; i < N; ++ i)
        if (check_permutation(i, phi[i])) {
            double k = (double)i / (double)phi[i];
            if (k < ansMin) {
                ans = i; ansMin = k;
            }
        }

    cout << ans << endl;
    cout << phi[ans] << endl;
    cout << ansMin << endl;
}

int main() {
    generate_primes();
    find_phi();
    return 0;
}