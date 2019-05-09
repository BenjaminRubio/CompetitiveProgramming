#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
string board[MAXN];
int speeds[9];
vector<vector<int>> g;
int depth[MAXN * MAXN];
vector<int> castles[9];
int n, m, p;

int pos(int i, int j) {
    return i * m + j;
}

void make_graph() {
    g.resize(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '#') {
                if (i > 0 && board[i - 1][j] == '.') {
                    g[pos(i, j)].push_back(pos(i - 1, j));
                }
                if (i < n - 1 && board[i + 1][j] == '.') {
                    g[pos(i, j)].push_back(pos(i + 1, j));
                }
                if (j > 0 && board[i][j - 1] == '.') {
                    g[pos(i, j)].push_back(pos(i, j - 1));
                }
                if (j < m - 1 && board[i][j + 1] == '.') {
                    g[pos(i, j)].push_back(pos(i, j + 1));
                }
            }
        }
    }
}

void bfs(int s, int player) {
    memset(depth, -1, sizeof depth);
    queue<int> q; q.push(s);
    depth[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                if (depth[v] > speeds[player]) return;
                if (board[v / m][v % m] == '.') {
                    q.push(v);
                    board[v / m][v % m] = player + '1';
                    castles[player].push_back(v);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++) cin >> speeds[i];
    for (int i = 0; i < n; i++) cin >> board[i];
    make_graph();
    int cells = n * m;
    for (int i = 0; i < n * m; i++) {
        char player = board[i / m][i % m];
        if (player != '.' && player != '#') castles[player - '1'].push_back(i);
        else if (player == '#') cells--;
    }
    while (true) {
        for (int i = 0; i < p; i++) {
            vector<int> castles_now = castles[i];
            for (int j : castles_now) bfs(j, i);
        }
        int size = 0;
        for (int i = 0; i < p; i++) size += castles[i].size();
        if (size == cells) break;
    }
    for (int i = 0; i < p; i++) {
        cout << castles[i].size() << ' ';
    }
}