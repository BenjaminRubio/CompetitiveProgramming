#include <bits/stdc++.h>
using namespace std;

pair<int, int> init, coord, destination;
int n;
string wind;

bool arrives(int T) {
    coord = init;
    for (int i = 0; i < T; i++) {
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
    }
    return (abs(destination.first - coord.first) + abs(destination.second - coord.second)) < T;
}

void advances() {
    
}

int main() {
    int x, y;
    cin >> x >> y;
    init = {x, y};
    cin >> x >> y;
    destination = {x, y};
    cin >> n >> wind;
    int tmin = 0;
    int tmax = n;
    while (tmin < tmax) {
        int tmid = (tmin + tmax) / 2;
        if (arrives(tmid)) {
            tmax = tmid;
        } else {
            tmin = tmid + 1;
        }
    }
    if (tmax == n) {
        cout << -1;
    } else {
        cout << tmax;
    }
}