#include <bits/stdc++.h>
using namespace std;

int h, w;
char picture[500][500];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int dfs() {
    int compacts = 0;
    vector<int> visited(h * w, 1);

    for (int i = 0; i < h * w; i++) {
        if (picture[i / w][i % w] != '*') continue;
        if (not visited[i]) continue;
        compacts++;

        stack<int> s;

        s.emplace(i);
        visited[i] = 0;

        while (not s.empty()) {
            int u = s.top();
            s.pop();

            for (int j = 0; j < 4; j++) {
                int ux = u / w;
                int uy = u % w;
                int vx = ux + dx[j];
                int vy = uy + dy[j];
                if (vx < 0 || vx >= h || vy < 0 || vy >= w) continue;
                if (picture[vx][vy] != '*') continue;
                int v = vx * w + vy;
                if (visited[v]) {
                    s.emplace(v);
                    visited[v] = 0;
                }
            }
        }
    }
    return compacts;
}

int main() {

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> picture[i][j];
        }
    }

    if (dfs() != 1) {
        cout << "NO";
        return 0;
    }

    bool is, left, up, right, down;

    for (int i = 0; i < h * w; i++) {
        int row = i / w;
        int col = i % w;
        if (picture[row][col] != '*') continue;
        is = true;
        left = false;
        up = false;
        right = false;
        down = false;
        for (int j = 0; j < h * w; j++) {
            int r = j / w;
            int c = j % w;
            if (picture[r][c] != '*') continue;
            if (r != row && c != col) {
                is = false;
                break;
            }
            if (r == row && c > col) right = true;
            if (r == row && c < col) left = true;
            if (r > row && c == col) up = true;
            if (r < row && c == col) down = true;
        }
        if (is && up && right && left && down) {
            is = true;
            break;
        }
        else is = false;
    }
    if (is) cout << "YES";
    else cout << "NO";
}