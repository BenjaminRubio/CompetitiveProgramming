#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int C[1001];
int D[1001];
int dpnum[1001][1001];
pair<int, int> dpmax[1001][1001];

pair<int, pair<int, int>> ways(int i, int j) {
    if (dpnum[i][j] != -1) return make_pair(0, dpmax[i][j]);
    if (i == j) {
        dpnum[i][j] = abs(C[i] - D[i]) <= K;
        dpmax[i][j] = make_pair(C[i], D[i]);
        return make_pair(dpnum[i][j], dpmax[i][j]);
    }
    int maxC, maxD;
    int result = 0;
    pair<int, pair<int, int>> next = ways(i + 1, j);
    result += next.first;
    maxC = max(C[i], next.second.first);
    maxD = max(D[i], next.second.second);
    if (abs(maxC - maxD) <= K) result++;
    next = ways(i, j - 1);
    result += next.first;
    maxC = max(C[j], next.second.first);
    maxD = max(D[j], next.second.second);
    dpnum[i][j] = result;
    dpmax[i][j] = make_pair(maxC, maxD);
    return make_pair(result, make_pair(maxC, maxD));
}

int main() {
    cin >> T;
    for (int k = 1; k <= T; k++) {
        memset(dpnum, -1, sizeof dpnum);
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> D[i];
        }
        cout << "Case #" << k << ": " << ways(0, N - 1).first << '\n';
    }
}