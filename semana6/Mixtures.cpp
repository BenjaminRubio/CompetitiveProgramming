#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> memo[100][100];
vector<int> colors;

pair<int, int> minSmoke(int m, int M) {
    int col;
    if (m == M) {
        col = colors[m];
        return {0, col};
    }
    if (M - m == 1) {
        col = (colors[m] + colors[M]) % 100;
        return {colors[m] * colors[M], col};
    }
    if (memo[m][M] != make_pair(-1, -1)) {
        return memo[m][M];
    }
    pair<int, int> ans = make_pair(INT_MAX, 0);
    for (int i = m; i < M; i++) {
        pair<int, int> firstHalf = minSmoke(m, i);
        pair<int, int> secondHalf = minSmoke(i + 1, M);
        int posMin = firstHalf.first + secondHalf.first + firstHalf.second * secondHalf.second;
        if (ans.first > posMin) {
            ans = {posMin, (firstHalf.second + secondHalf.second) % 100};
        }
    }
    return memo[m][M] = ans;
}

int main() {
    while (cin >> N) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                memo[i][j] = make_pair(-1, -1);
            }
        }
        for (int i = 0; i < N; i++) {
            int col;
            cin >> col;
            colors.push_back(col);
        }
        cout << minSmoke(0, N - 1).first << '\n';
        colors.clear();
    }
}