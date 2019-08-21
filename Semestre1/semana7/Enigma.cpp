#include <bits/stdc++.h>
using namespace std;

string enigma;
int N;
int memo[1000][1000];
map<pair<int, int>, pair<int, int>> parent;

int minimumMultiple(int i, int r) {
    if (memo[i][r] != -1) {
        return memo[i][r];
    }
    if (enigma[i] != '?') {
        int d = enigma[i] - '0';
        if (i == enigma.size() - 1) {
            if ((r + d) % N == 0) {
                return memo[i][r] = d;
            }
            return memo[i][r] = 10;
        }
        int r_ = d;
        for (int p = i; p < enigma.size() - 1; p++) {
            r_ = (r_ * 10) % N;
        }
        int next = minimumMultiple(i + 1, (r + r_) % N);
        if (next != 10) {
            parent[{i, r}] = {i + 1, (r + r_) % N};
            return memo[i][r] = d;
        }
        return memo[i][r] = 10;
    }
    if (i == enigma.size() - 1) {
        int min = 0;
        if (!i) {
            min = 1;
        }
        for (int d = min; d < 10; d++) {
            if ((r + d) % N == 0) {
                return memo[i][r] = d;
            }
        }
        return memo[i][r] = 10;
    }
    int min = 0;
    if (!i) {
        min = 1;
    }
    for (int d = min; d < 10; d++) {
        int r_ = d;
        for (int p = i; p < enigma.size() - 1; p++) {
            r_ = (r_ * 10) % N;
        }
        int next = minimumMultiple(i + 1, (r + r_) % N);
        if (next != 10) {
            parent[{i, r}] = {i + 1, (r + r_) % N};
            return memo[i][r] = d;
        }
    }
    return memo[i][r] = 10;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> enigma) {
        memset(memo, -1, sizeof memo);
        cin >> N;
        int result = minimumMultiple(0, 0);
        if (result == 10) {
            cout << "*\n";
        } else {
            pair<int, int> coord = {0, 0};
            for (int i = 0; i < enigma.size(); i++) {
                cout << memo[coord.first][coord.second];
                coord = parent[coord];
            }
            cout << '\n';
        }
    }
}