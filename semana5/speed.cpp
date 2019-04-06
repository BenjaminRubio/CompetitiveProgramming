#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<double> distances;
vector<double> velocities;
double cmin {1000};
double cmax {1e10};

bool arrives(double c) {
    double time {0};
    for (int i = 0; i < n; i++) {
        time += distances[i] / (velocities[i] + c);
    }
    if (time <= t) {
        return true;
    }
    return false;
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        double d, v;
        cin >> d >> v;
        distances.push_back(d);
        velocities.push_back(v);
        cmin = min(cmin, v);
    }
    cmin = -cmin;
    for (int i = 0; i < 80; i++) {
        double cmid = (cmin + cmax) / 2.0;
        if (arrives(cmid)) {
            cmax = cmid;
        } else {
            cmin = cmid;
        }
    }
    cout  << setprecision(9) << (cmin + cmax) / 2.0;
}