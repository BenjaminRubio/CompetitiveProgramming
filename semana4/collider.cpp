#include <bits/stdc++.h>
using namespace std;

int N;
double len {0};
vector<vector<double>> dataSet;

// https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
int log2(int x) 
{ 
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
}

bool collides(double time) {
    double newPos1;
    double newPos2;
    for (int i = 0; i < N - 1; i++) {
        newPos1 = dataSet[i][0] + dataSet[i][1] * time;
        newPos2 = dataSet[i + 1][0] + dataSet[i + 1][1] * time;
        if (newPos1 >= newPos2) {
            return true;
        }
    }
    return false;
}

double binarySearch() {
    double first = 0;
    double last = len;
    int n = log2(len / 0.0000000001);
    for (int i = 0; i < n; i++) {
        double mid = (last + first) / 2;
        if (collides(mid)) {
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
        double pos, vel;
        cin >> pos >> vel;
        dataSet.push_back({pos, vel});
        if (pos > len) {
            len = pos;
        }
    }
    sort(dataSet.begin(), dataSet.end());
    cout << dataSet[1][0] << ' ' << dataSet[1][1] << '\n';
    cout << setprecision(10) << binarySearch() << '\n';
}