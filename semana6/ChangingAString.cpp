#include <bits/stdc++.h>
using namespace std;

int N, o1, o2, o3;
int index_ = 0;
int memo[1001][1001];
string input, word;
map<pair<int, int>, pair<string, char>> parent;

int minSteps(int i, int j) {
    int &m = memo[i][j];
    if (m != -1) {
        return m;
    }
    if (j == word.size() && i == input.size()) {
        return 0;
    }
    int ans = 1001;
    if (i < input.size() && j < word.size()) {
        if (input[i] == word[j]) {
            return m = minSteps(i + 1, j + 1);
        }
        ans = min(ans, minSteps(i + 1, j + 1) + 1);
    }
    if (i < input.size()) {
        ans = min(ans, minSteps(i + 1, j) + 1);
    }
    if (j < word.size()) {
        ans = min(ans, minSteps(i, j + 1) + 1);
    }
    return m = ans;
}

void path(int i, int j) {
    if (i == input.size()) {
        for (int k = j; k < word.size(); k++) {
            cout << "INSERT " << i + (index_++) + 1 << ' ' << word[j + (k - j)] << '\n';
        }
        return;
    }
    if (j == word.size()) {
        for(int k = i; k < input.size(); k++) {
            cout << "DELETE " << i + index_ + 1 << '\n';
        }
        return;
    }
    if (input[i] == word[j]) {
        path(i + 1, j + 1);
        return;
    }
    int A, B, C;
    A = minSteps(i + 1, j) + 1;
    B = minSteps(i, j + 1) + 1;
    C = minSteps(i + 1, j + 1) + 1;
    if(A == minSteps(i, j)) {
        cout << "DELETE " << i + index_ + 1 << '\n';
        index_--;
        path(i + 1, j);
    } else if (B == minSteps(i, j)) {
        cout << "INSERT " << i + index_ + 1 << ' ' << word[j] << '\n';
        index_++;
        path(i, j + 1);
    } else {
        cout << "REPLACE " << i + index_ + 1 << ' ' << word[j] << '\n';
        path(i + 1, j + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> input >> word;
    memset(memo, -1, sizeof memo);
    int steps = minSteps(0, 0);
    cout << steps << '\n';
    path(0, 0);
}