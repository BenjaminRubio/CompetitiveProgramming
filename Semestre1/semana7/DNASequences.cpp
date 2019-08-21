#include <bits/stdc++.h>
using namespace std;

int K;
string word1, word2;
int memo[1000][1000];

int longestCommonSubsequence(int i, int j) {
    if (i == word1.size() || j == word2.size()) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    int ans = max(longestCommonSubsequence(i + 1, j), longestCommonSubsequence(i, j + 1));
    int n = 0;
    int i_ = i;
    int j_ = j;
    while (i_ < word1.size() && j_ < word2.size() && word1[i_] == word2[j_]) {
        n++;
        i_++;
        j_++;
    }
    for (int k = K; k <= n; k++) {
        ans = max(ans, k + longestCommonSubsequence(i + k, j + k));
    }
    return memo[i][j] = ans;
}

int main() {
    while (cin >> K && K) {
        memset(memo, -1, sizeof memo);
        cin >> word1;
        cin >> word2;
        cout << longestCommonSubsequence(0, 0) << '\n';
    }
}