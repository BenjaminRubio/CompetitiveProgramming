#include <bits/stdc++.h>
using namespace std;

int W, D, A, K, num;
vector<vector<int>> coefficients;

double integrate(int f, double d) {
    double delta = double(W) / 10000.0;
    double result {0};
    for (int i = 0; i < 10000; i++) {
        double num = 0;
        double den = 0;
        double pot = 1;
        for (int j = 0; j < K + 1; j++) {
            num += coefficients[f * 2][j] * pot;
            den += coefficients[f * 2 + 1][j] * pot;
            pot *= (delta * double(i));
        }
        // cout << num << ' ' << den << ' ' << delta * d << '\n';
        if (delta * num / den + delta * d > 0) {
            result += delta * num / den + delta * d;
        }
    }
    return result;
}

bool minesA(double d) {
    // cout << integrate(0, d) << ' ' << integrate(1, d) << '\n'; 
    return integrate(0, d) - integrate(1, d) >= A;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> W >> D >> A >> K) {
        for (int i = 0; i < 4; i++) {
            vector<int> arr;
            for (int i = 0; i <= K; i++) {
                cin >> num;
                arr.push_back(num);
            }
            coefficients.push_back(arr);
        }
        double dmin = 0;
        double dmax = D;
        for (int i = 0; i < 100; i++) {
            double dmid = (dmin + dmax) / 2;
            if (minesA(dmid)) {
                dmax = dmid;
            } else {
                dmin = dmid;
            }
        }
        cout << setprecision(5) << (dmin + dmax) / 2 << '\n';
    }
}