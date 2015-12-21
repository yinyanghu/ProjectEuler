#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const long long N = 1000000000000LL;
//const long long N = 1000LL;

vector<long long> lst;

bool add_three(int b) {
    long long base = b;
    long long x = 1 + base;
    base = base * (long long)b;
    x = x + base;

    if (x >= N) return false;

    while (x < N) {
        lst.push_back(x);
        base = base * (long long)b;
        x = x + base;
    }

    return true;
}

int main() {
    for (int b = 2; ; ++ b)
        if (!add_three(b)) break;
    sort(lst.begin(), lst.end());

    vector<long long>::iterator last = unique(lst.begin(), lst.end());

    //cout << lst.size() << endl;
    long long ans = 1; // include 1
    for (vector<long long>::iterator it = lst.begin(); it != last; ++ it) {
        //cout << *it << endl;
        ans += *it;
    }
    cout << ans << endl;

    return 0;
}