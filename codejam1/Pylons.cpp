#include <bits/stdc++.h>
using namespace std;

int T, R, C;
vector<pair<int, int>> visited;
set<pair<int, int>> s;
string result = "IMPOSSIBLE";

bool possible(pair<int, int> coord) {
    if (visited.size() == R * C) {
        return true;
    }
    int row = coord.first;
    int col = coord.second;
    for (int i = 0; i < R * C; i++) {
        int r = i / C;
        int c = i % C;
        if (row != r and col != c and row - col != r - c and row + col != r + c) {
            if (s.find({r + 1, c + 1}) == s.end()) {
                visited.push_back({r + 1, c + 1});
                s.insert({r + 1, c + 1});
                if (possible({r, c})) {
                    return true;
                }
                s.erase({r + 1, c + 1});
                visited.pop_back();
            }
        }
    }
    return false;
}

int main() {
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cin >> R >> C;
        for (int i = 0; i < R * C; i++) {
            visited.push_back({i / C + 1, i % C + 1});
            s.insert({i / C + 1, i % C + 1});
            if (possible({i / C, i % C})) {
                result = "POSSIBLE";
                break;
            }
            s.erase({i / C + 1, i % C + 1});
            visited.pop_back();
        }
        cout << "Case #" << k << ": " << result << '\n';
        if (result == "POSSIBLE") {
            for (int i = 0; i < visited.size(); i++) {
                cout << visited[i].first << ' ' << visited[i].second << '\n';
            }
        }
        visited.clear();
        s.clear();
    }
}