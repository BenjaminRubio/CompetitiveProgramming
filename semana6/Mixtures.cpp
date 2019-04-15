#include <bits/stdc++.h>
using namespace std;

int N;
int memo[100];

int minSteps(int i) {
    if (memo[i] != -1) {
        return memo[i];
    }
    int ans = 0;
    return memo[i] = ans;
}

int main() {
    while (cin >> N) {
        memset(memo, -1, sizeof memo);

    }
}