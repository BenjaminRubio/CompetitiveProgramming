#include <bits/stdc++.h>
using namespace std;

pair<int, int> init, coord, destination;
int n;
string wind;
vector<pair<int, int>> vectors;

bool arrives(int T) {
    coord = init;
    coord.first += (T / n) * vectors[n].first + vectors[T % n].first;
    coord.second += (T / n) * vectors[n].second + vectors[T % n].second; 
    return abs(destination.first - coord.first) + abs(destination.second - coord.second) <= T;
}

int main() {
    int x, y;
    cin >> x >> y;
    init = {x, y};
    cin >> x >> y;
    destination = {x, y};
    cin >> n >> wind;
    coord = {0, 0};
    vectors.push_back(coord);
    for (int i = 0; i < n; i++) {
        if (wind[i] == 'U') {
            coord.second += 1;
        }
        if (wind[i] == 'R') {
            coord.first += 1;
        }
        if (wind[i] == 'D') {
            coord.second -= 1;
        }
        if (wind[i] == 'L') {
            coord.first -= 1;
        }
        vectors.push_back(coord);
    }
    int tmin = 0;
    int tmax = INT_MAX;
    coord.first += init.first;
    coord.second += init.second;
    int delta = abs(destination.first - init.first) + abs(destination.second - init.second);
    int delta_ciclo = abs(destination.first - coord.first) + abs(destination.second - coord.second) - delta;
    if (delta_ciclo == n) {
        cout << -1;
        return 0;
    }
    while (tmin < tmax) {
        int tmid = (tmin + tmax) / 2;
        if (arrives(tmid)) {
            tmax = tmid;
        } else {
            tmin = tmid + 1;
        }
    }
    cout << tmax;
}