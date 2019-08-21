#include <bits/stdc++.h>
using namespace std;

string word1, word2;
int n, w;
char a, b;
vector<pair<char, int>> graph[27];

int main() {
    cin >> word1 >> word2;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
}