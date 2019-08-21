#include <bits/stdc++.h>
using namespace std;

int n, m;
string labyrinth[1000];
map<int, int> ccs;
map<int, int> lab_cc;
const int MAXN = 1000;
vector<vector<int>> g;
bool visited[MAXN * MAXN];

int pos(int i, int j) {
    return i * m + j;
}

void make_graph() {
    g.resize(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && labyrinth[i - 1][j] != '*') {
                g[pos(i, j)].push_back(pos(i - 1, j));
            }
            if (i < n - 1 && labyrinth[i + 1][j] != '*') {
                g[pos(i, j)].push_back(pos(i + 1, j));
            }
            if (j > 0 && labyrinth[i][j - 1] != '*') {
                g[pos(i, j)].push_back(pos(i, j - 1));
            }
            if (j < m - 1 && labyrinth[i][j + 1] != '*') {
                g[pos(i, j)].push_back(pos(i, j + 1));
            }
        }
    }
}

void dfs(int root) {
    if (!visited[root]) {
        vector<int> cc;
        stack<int> s;
        s.push(root);
        cc.push_back(root);
        visited[root] = true;
        while (!s.empty()) {
            int u = s.top(); s.pop();
            for (int v : g[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    s.push(v);
                    cc.push_back(v);
                }
            }
        }
        for (int v : cc) {
            lab_cc[v] = ccs.size();
        }
        ccs[ccs.size()] = cc.size();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(visited, 0, sizeof(bool) * n * m);
    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
    }
    make_graph();
    for(int i = 0; i < n * m; i++) {
        if (labyrinth[i / m][i % m] == '*') {
            int k = 1;
            vector<int> ccs_;
            for (int v : g[i]) {
                dfs(v);
                int l = lab_cc[v];
                if (find(ccs_.begin(), ccs_.end(), l) == ccs_.end()) {
                    ccs_.push_back(l);
                    k += ccs[l];
                }
            }
            labyrinth[i / m][i % m] = char(k % 10) + '0';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << labyrinth[i] << '\n';
    }
}