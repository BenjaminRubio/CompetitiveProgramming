#include <bits/stdc++.h>
using namespace std;

int x, y, n;
pair<int, int> bag;
vector<pair<int, int>> coords;
int memo[24][2][(1 << 24) - 1];

int time(int i, int j, int m) {
    pair<int, int> coord1 = coords[i];
    if (!m) return memo[i][j][m] = coord1.first * coord1.first + coord1.second * coord1.second;
    if (j == 2) {
        return memo[i][j][m] = coord1.first * coord1.first + coord1.second * coord1.second + time(0, 0, m);
    }
    int result = INT_MAX;
    for (int b = 1; b < n; b++) {
        if (m & (1 << b)) {
            pair<int, int> coord2 = coords[b];
            int distance = (coord1.first - coord2.first) * (coord1.first - coord2.first);
            distance += (coord1.second - coord2.second) * (coord1.second - coord2.second);
            result = min(result, time(b, j + 1, m ^ (1 << b)) + distance);
        }
    }
    return memo[i][j][m] = result;
}

int main() {
    cin >> x >> y >> n;
    bag = {x, y};
    coords.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({x, y});
    }
}