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
    g.resize(p);
    
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
    
}