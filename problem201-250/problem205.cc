#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double probA[36 + 1];
double probB[36 + 1];

void diceA(int step, int sum) {
    if (step == 9) {
        probA[sum] += pow(1.0 / 4.0, 9.0);
        return;
    }
    for (int i = 1; i <= 4; ++ i)
        diceA(step + 1, sum + i);
}

void diceB(int step, int sum) {
    if (step == 6) {
        probB[sum] += pow(1.0 / 6.0, 6.0);
        return;
    }
    for (int i = 1; i <= 6; ++ i)
        diceB(step + 1, sum + i);
}

int main() {
    for (int i = 1; i <= 36; ++ i)
        probA[i] = probB[i] = 0.0;
    diceA(0, 0);
    diceB(0, 0);
    double ans = 0.0;
    for (int i = 4; i <= 36; ++ i) {
        double sum = 0.0;
        for (int j = 1; j < i; ++ j)
            sum += probB[j];
        ans += sum * probA[i];
    }
    printf("%.7lf\n", ans);
    return 0;
}