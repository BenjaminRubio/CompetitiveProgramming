#include <bits/stdc++.h>
using namespace std;

string n;
int memo[101][101][11];

int nElevens(int i, int j, int r) {
    if (j == n.size()) {
        return 0;
    }
    if (memo[i][j][r] != -1) {
        return memo[i][j][r];
    }
    if (i == n.size() - 1) {
        if (n[j] != ' ') {
            int d = n[j] - '0';
            if ((d + r) % 11 == 0) {
                return memo[i][j][r] = 1;
            }
            return memo[i][j][r] = 0;
        }
        return memo[i][j][r] = nElevens(i, j + 1, r);
    }
    if (n[j] != ' ') {
        int d = n[j] - '0';
        if (!i && !d) {
            return memo[i][j][r] = nElevens(i, j + 1, r);
        }
        int r_ = d;
        for (int p = i; p < n.size() - 1; p++) {
            r_ = (r_ * 10) % 11;
        }
        n[j] = ' ';
        int result = nElevens(i + 1, j, (r_ + r) % 11) + nElevens(i, j + 1, r);
        n[j] = d + '0';
        return memo[i][j][r] = result;
    }
    return memo[i][j][r] = nElevens(i, j + 1, r);
}

int main() {
    while (cin >> n) {
        memset(memo, -1, sizeof memo);
        cout << nElevens(0, 0, 0) << '\n';
    }
}