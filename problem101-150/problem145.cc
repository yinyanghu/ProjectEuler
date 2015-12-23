#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int N = 1000000000;
//const int N = 1000;

int digit[10];

int main() {
    int ans = 0;
    for (int x = 1; x < N; ++ x) {
        if (x % 10 == 0) continue;
        int d = 0;
        for (int xx = x; xx; xx /= 10)
            digit[d ++] = xx % 10;
        int y = 0; 
        for (int i = 0; i < d; ++ i)
            y = y * 10 + digit[i];
        int xy = x + y;
        bool check = true;
        for (; xy; xy /= 10)
            if (((xy % 10) & 1) == 0) {
                check = false;
                break;
            }
        if (check) ++ ans;
    }
    cout << ans << endl;
    return 0;
}

