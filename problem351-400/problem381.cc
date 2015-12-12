#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

// return <gcd(a, b), <x, y>> such that ax + by = gcd(a, b)
pair< int, pair<int, int> > extended_euclidean(int a, int b) {
    if (b == 0) return make_pair(a, make_pair(1, 0));
    pair< int, pair<int, int> > next = extended_euclidean(b, a % b);
    int y = next.second.first, x = next.second.second;
    y = y - (a / b) * x;
    return make_pair(next.first, make_pair(x, y));
} 

// p is prime, return b such that a * b = 1 (mod p)
int modular_inverse(int a, int p) {
    pair< int, pair<int, int> > tuple = extended_euclidean(a, p);
    if (tuple.first != 1) return -1;
    int ret = tuple.second.first;
    while (ret < 0) ret += p;
    return ret;
}

const int N = 100000000;

bool P[N];
vector<int> Primes;

void generate_primes() {
    memset(P, true, sizeof(P));
    Primes.clear();
    P[0] = P[1] = false;
    for (int i = 2; i < N; ++ i)
        if (P[i]) {
            Primes.push_back(i);
            for (int j = i + i; j < N; j += i)
                P[j] = false;
        }
}

int main() {
    generate_primes();
    cout << "generated primes" << endl;
    long long ans = 0;
    for (int i = 2; i < Primes.size(); ++ i) {
        long long p = Primes[i];
        long long x = p - 1;
        long long sum = x;
        for (int k = 1; k <= 4; ++ k) {
            long long y = modular_inverse(p - k, p);
            x = (x * y) % p;
            sum = (sum + x) % p;
        }
        ans += sum;
    }
    cout << ans << endl;

    return 0;
}