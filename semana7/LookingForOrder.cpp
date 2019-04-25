#include <bits/stdc++.h>
using namespace std;

int x, y, n;
pair<int, int> bag;
vector<pair<int, int>> coords;
int memo[1 << 24];
map<int, pair<int, int>> parent;

int time(int m) {
    if (!m) return memo[m] = 0;
    if (memo[m] != -1) return memo[m];
    int result = INT_MAX;
    int t;
    for (int i = 0; i < n; i++) {
        if (m & (1 << i)) {
            int m_ = m ^ (1 << i);
            pair<int, int> coord1 = coords[i];
            int distance = coord1.first * coord1.first + coord1.second * coord1.second;
            t = time(m_) + 2 * distance;
            if (result > t) {
                result = t;
                parent[m] = {i + 1, 0};
            }
            for (int j = i + 1; j < n; j++) {
                if (m_ & (1 << j)) {
                    pair<int, int> coord2 = coords[j];
                    distance += (coord1.first - coord2.first) * (coord1.first - coord2.first) + 
                                (coord1.second - coord2.second) * (coord1.second - coord2.second);
                    distance += coord2.first * coord2.first + coord2.second * coord2.second;
                    t = time(m_ ^ (1 << j)) + distance;
                    if (result > t) {
                        result = t;
                        parent[m] = {i + 1, j + 1};
                    }
                }
            }
        }
    }
    return memo[m] = result;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> x >> y >> n;
    bag = {x, y};
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({x - bag.first, y - bag.second});
    }
    int m = (1 << n) - 1;
    cout << time(m) << '\n';
    int i, j;
    cout << 0 << ' ';
    while (m) {
        i = parent[m].first;
        j = parent[m].second;
        cout << i << ' ';
        m = m ^ (1 << (i - 1));
        if (j) {
            cout << j << ' ';
            m = m ^ (1 << (j - 1));
        }
        cout << 0 << ' ';
    }
}