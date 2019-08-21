#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<double> lanterns;

// https://www.geeksforgeeks.org/bit-tricks-competitive-programming/
int log2(int x) 
{ 
    int res = 0; 
    while (x >>= 1) 
        res++; 
    return res; 
}

bool illuminated(double radius) {
    double last = 0;
    double m, M;
    for (int i = 0; i < N; i++) {
        m = lanterns[i] - radius;
        M = lanterns[i] + radius;
        if (m > last) {
            return false;
        }
        if (M > last) {
            last = M;
        }
    }
    if (M > L) {
        return true;
    }
    return false;
}

double binarySearch() {
    double first = 0;
    double last = L;
    int n = log2(L / 0.0000000001);
    for (int i = 0; i < n; i++) {
        double mid = (last + first) / 2;
        if (illuminated(mid)) {
            last = mid;
        } else {
            first = mid;
        }
    }
    return (first + last) / 2.0;   
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        lanterns.push_back(num);
    }
    sort(lanterns.begin(), lanterns.end());
    cout << setprecision(10) << binarySearch() << '\n';
}