#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int N, M;
vector<int> coins;
ll memo[251][51];

ll coinChanges(int n, int i) {
    if (n == 0) {
        return 1;
    }
    if (i == M) {
        return 0;
    }
    ll &m = memo[n][i];
    if (m != -1) {
        return m;
    }
    ll ans = 0;
    if (coins[i] <= n) {
        ans += coinChanges(n - coins[i], i);
    }
    ans += coinChanges(n, i + 1);
    return m = ans;
}

int main() {
    cin >> N >> M;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    cout << coinChanges(N, 0);
}