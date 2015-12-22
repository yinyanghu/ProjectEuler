#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//const int N = 50;
const int N = 50000000;

vector<int> Prime;
bool p[N];
void generate_prime() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    Prime.clear();

    for (int i = 2; i < N; ++ i)
        if (p[i]) {
            Prime.push_back(i);
            for (int j = i + i; j < N; j += i)
                p[j] = false;
        }
}

bool flag[N];

int main() {
    generate_prime();
    memset(flag, false, sizeof(flag));

    for (int i = 0; i < Prime.size(); ++ i) {
        int A = Prime[i] * Prime[i];
        if (A >= N) break;
        for (int j = 0; j < Prime.size(); ++ j) {
            int B = Prime[j] * Prime[j] * Prime[j];
            if (A + B >= N) break;
            for (int k = 0; k < Prime.size(); ++ k) {
                int C = Prime[k] * Prime[k] * Prime[k] * Prime[k];
                if (A + B + C >= N) break;
                //cout << A + B + C << endl;
                flag[A + B + C] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < N; ++ i)
        if (flag[i]) ++ ans;
    cout << ans << endl;
    return 0;
}