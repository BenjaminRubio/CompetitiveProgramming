#include <bits/stdc++.h>
using namespace std;

int p, k, m;
const int MAXN = 50;
string matrix[MAXN][MAXN];
vector<vector<int>> g;
bool visited[MAXN * MAXN * MAXN];
vector<vector<int>> groups;

int pos(int i, int j, int l) {
    return p * k * i + k * j + l;
}

void make_graph() {
    g.resize(p * k * m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int l = 0; l < k; l++) {
                char material = matrix[i][j][l];
                if (material != '*') {
                    if (i > 0 && matrix[i - 1][j][l] == material) {
                        g[pos(i, j, l)].push_back(pos(i - 1, j, l));
                    }
                    if (i < m - 1 && matrix[i + 1][j][l] == material) {
                        g[pos(i, j, l)].push_back(pos(i + 1, j, l));
                    }
                    if (j > 0 && matrix[i][j - 1][l] == material) {
                        g[pos(i, j, l)].push_back(pos(i, j - 1, l));
                    }
                    if (j < p - 1 && matrix[i][j + 1][l] == material) {
                        g[pos(i, j, l)].push_back(pos(i, j + 1, l));
                    }
                    if (l > 0 && matrix[i][j][l - 1] == material) {
                        g[pos(i, j, l)].push_back(pos(i, j, l - 1));
                    }
                    if (l < k - 1 && matrix[i][j][l + 1] == material) {
                        g[pos(i, j, l)].push_back(pos(i, j, l + 1));
                    }
                }
            }
        }
    }
}

void dfs(int root, int type) {
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
        groups[type].push_back(cc.size());
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int case_ = 0;
    while (cin >> p >> k >> m) {
        case_++;
        memset(visited, 0, sizeof visited);
        groups.resize(4);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                cin >> matrix[i][j];
            }
        }
        make_graph();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                for (int l = 0; l < k; l++) {
                    char type = matrix[i][j][l];
                    if (type != '*') {
                        dfs(pos(i, j, l), type - 'a');
                    }
                }
            }
        }
        if (case_ > 1) {
            cout << '\n';
        }
        cout << "Case " << case_ << ":\n";
        for (char t : {0, 1, 2, 3}) {
            sort(groups[t].begin(), groups[t].end(), greater<int>());
            cout << char(t + 'a');
            if (groups[t].size() > 0) {
                for (int n : groups[t]) {
                    cout << ' ' << n;
                }
            } else {
                cout << ' ' << 0;
            }
            cout << '\n';
        }
        g.clear();
        groups.clear();
    }
}