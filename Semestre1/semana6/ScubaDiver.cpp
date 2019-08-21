#include <bits/stdc++.h>
using namespace std;

int T, O, N, K;
int memo[1024][22][80];
int oxi[1024];
int nit[1024];
int wgh[1024];

int minWeight(int i, int o, int n) {
    if (o == O && n == N) {
        return 0;
    }
    if (i == K) {
        return 999999999;
    }
    if (memo[i][o][n] != -1) {
        return memo[i][o][n];
    }
    int ans = 999999999;
    ans = min(ans, minWeight(i + 1, o, n));
    ans = min(ans, minWeight(i + 1, min(o + oxi[i], O), min(n + nit[i], N)) + wgh[i]);
    return memo[i][o][n] = ans;
}

int main() {
    cin >> T;
    while (T--) {
        memset(memo, -1, sizeof memo);
        cin >> O >> N;
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> oxi[i];
            cin >> nit[i];
            cin >> wgh[i];
        }
        cout << minWeight(0, 0, 0) << '\n';
    }
}