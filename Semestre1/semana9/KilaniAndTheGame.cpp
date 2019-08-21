#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
string board[MAXN];
int speeds[9];
int depth[MAXN * MAXN];
vector<int> castles[9];
int n_castles[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int n, m, p;
bool changed = true;
int dx[5] = {0, -1, 1, 0 ,0},
    dy[5] = {0, 0, 0, -1, 1};

void bfs(int player) {
    if (!castles[player].empty()) {
        memset(depth, -1, sizeof(int) * n * m);
        queue<int> q;
        for (int v : castles[player]) {
            q.push(v);
            depth[v] = 0;
        }
        castles[player].clear();
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i : {0, 1, 2, 3, 4}) {
                int x = (u / m) + dx[i];
                int y = (u % m) + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != '.') continue;
                int v = x * m + y;
                if (depth[v] == -1) {
                    char * id = &(board[v / m][v % m]);
                    if (*id == '.') {
                        depth[v] = depth[u] + 1;
                        if (depth[v] > speeds[player]) return;
                        q.push(v);
                        *id = player + '1';
                        if (depth[v] == speeds[player]) {
                            changed = true;
                            castles[player].push_back(v);
                        }
                        n_castles[player]++;
                    }
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
    for (int i = 0; i < n * m; i++) {
        char player = board[i / m][i % m];
        if (player != '.' && player != '#') {
            castles[player - '1'].push_back(i);
            n_castles[player - '1']++;
        }
    }
    while (changed) {
        changed = false;
        for (int i = 0; i < p; i++) bfs(i);
    }
    for (int i = 0; i < p; i++) {
        cout << n_castles[i] << ' ';
    }
}