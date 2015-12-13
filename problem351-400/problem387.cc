#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxP = 10000000;

bool P[maxP + 1];
vector<int> Primes;

void generate_primes() {
    memset(P, true, sizeof(P));
    Primes.clear();
    P[0] = P[1] = false;
    for (int i = 2; i <= maxP; ++ i)
        if (P[i]) {
            Primes.push_back(i);
            for (int j = i + i; j <= maxP; j += i)
                P[j] = false;
        }
}

bool is_prime(long long x) {
    if (x == 0 || x == 1) return false;
    for (int i = 0; i < Primes.size(); ++ i) {
        long long square = (long long)Primes[i] * (long long)Primes[i];
        if (square > x) break;
        if (x % Primes[i] == 0) return false;
    }
    return true;
}

const long long MAX = 100000000000000LL;
//const long long MAX = 10000LL;

vector<long long> candidate;

// right truncatable Harshad number
void generate_RTHN(long long x, int sd) {
    if (x >= MAX) return;
    if (x % sd != 0) return;
    if (is_prime(x / sd)) candidate.push_back(x);
    for (int y = 0; y < 10; ++ y) {
        long long next = x * 10 + (long long)y;
        generate_RTHN(x * 10 + y, sd + y);
    }
}


int main() {
    generate_primes();
    candidate.clear();
    for (int i = 1; i < 10; ++ i)
        generate_RTHN(i, i);
    long long ans = 0;
    for (int i = 0; i < candidate.size(); ++ i) {
        //cout << candidate[i] << endl;
        for (int j = 0; j < 10; ++ j) {
            long long K = candidate[i] * 10 + j;
            if (K < MAX && is_prime(K)) {
                //cout << K << endl;
                ans += K;
            }
        }
    }
    cout << ans << endl;
    return 0;
}