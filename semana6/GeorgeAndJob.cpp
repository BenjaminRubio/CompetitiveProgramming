#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int p[5000];
long long int memo[5000][5000] {0};

long long int maxSum(int i, int k) {
    if (k == 0 || i >= N - k * M + 1) {
        return 0;
    }
    if (memo[i][k] != -1) {
        return memo[i][k];
    }
    long long int ans = 0;
    long long int sum = 0;
    for (int j = i; j < i + M; j++) {
        sum += p[j];
    }
    ans = max(ans, maxSum(i + M, k - 1) + sum);
    ans = max(ans, maxSum(i + 1, k));
    return memo[i][k] = ans;
}

int main() {
    cin >> N >> M >> K;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < N; i++) {
        int p_;
        cin >> p_;
        p[i] = p_;
    }
    cout << maxSum(0, K);
}