#include <bits/stdc++.h>
using namespace std;

int N;
long long int memo[501][501];

long long int nStairs(int n, int l) {
    if (memo[n][l] != -1) {
        return memo[n][l];
    }
    if (n == 0) {
        return 1;
    }
    if (l >= n) {
        return 0;
    }
    long long int ans = 0;
    for (int i = 1; i <= (n - l); i++) {
        ans += nStairs(n - (i + l), l + i);
    }
    return memo[n][l] = ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            memo[i][j] = -1;
        }
    }
    cout << nStairs(N, 0) - 1;
}