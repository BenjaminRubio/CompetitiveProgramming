#include <bits/stdc++.h>
using namespace std;

int N;
double len {0};
vector<double> positions;
vector<double> velocities;

// https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
int log2(int x) 
{ 
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
}

bool meets(double time) {
    double m {0};
    double M {len};
    for (int i = 0; i < N; i++) {
        if (positions[i] - velocities[i] * time > m) {
            m = positions[i] - velocities[i] * time;
        }
        if (positions[i] + velocities[i] * time < M) {
            M = positions[i] + velocities[i] * time;
        }
    }
    if (m <= M) {
        return true;
    }
    return false;
}

double binarySearch() {
    double first = 0;
    double last = len;
    int n = log2(len / 0.00000001);
    for (int i = 0; i < n; i++) {
        double mid = (last + first) / 2;
        if (meets(mid)) {
            last = mid;
        } else {
            first = mid;
        }
    }
    return (first + last) / 2.0;   
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        positions.push_back(num);
        if (num > len) {
            len = num;
        }
    }
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        velocities.push_back(num);
    }
    cout << setprecision(10) << binarySearch() << '\n';
}