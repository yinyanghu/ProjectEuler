#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

/*
bool check_prime(int x) {
    int UB = int(sqrt(x));
    for (int d = 2; d <= UB; ++ d)
        if (x % d == 0) return false;
    return true;
}
*/

const int N = 100000000;
const int maxP = N + 10;

bool P[maxP];
vector<int> Prime;

void find_all_primes() {
    Prime.clear();
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i < maxP; ++ i)
        if (P[i]) {
            Prime.push_back(i);
            for (int j = i * 2; j < maxP; j += i)
                P[j] = false;
        }
}

bool candidate[N + 1];

void generate_candidate() {
    memset(candidate, false, sizeof(candidate));
    for (int i = 0; i < Prime.size(); ++ i)
        if (Prime[i] - 1 <= N)
            candidate[Prime[i] - 1] = true;
    for (int i = 0; i < Prime.size(); ++ i) {
        int p = Prime[i];
        if (p * p > N) break;
        for (int j = p * p; j <= N; j += p * p)
            candidate[j] = false;
    }
}

bool check(int x) {
    int K = int(sqrt(x));
    for (int d = 1; d <= K; ++ d)
        if (x % d == 0)
            if (!P[d + x / d]) return false;
    return true;
}


int main() {
    find_all_primes();
    cout << "generated all primes" << endl;
    generate_candidate();
    cout << "generated all candidates" << endl;
    long long total = 0;
    for (int i = 1; i <= N; ++ i)
        if (candidate[i] && check(i)) {
        //if (check(i)) {
            //if (!candidate[i])
                //cout << i << endl;
            //cout << i << endl;
            total += (long long)i;
        }
    cout << total << endl;
    return 0;
}