#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    for (int k = 0; k < T; k++) {
        char a_, b_, c_, d_;
        int a, b, c, d;
        cin >> a_ >> b_ >> c_ >> d_;
        a = a_ - 'A' + 1;
        b = b_ - '0';
        c = c_ - 'A' + 1;
        d = d_ - '0';
        if ((a + b) % 2 != (c + d) % 2) {
            cout << "Impossible\n";
            continue;
        }
        if (a == c && b == d) {
            cout << 0 << ' ' << char(a + 'A' - 1) << ' ' << b << '\n';
            continue;
        }
        if ((a - b == c - d) || (a + b == c + d)) {
            cout << 1 << ' ' << char(a + 'A' - 1) << ' ' << b << ' ' << char(c + 'A' - 1) << ' ' << d << '\n';
            continue;
        }
        for (int i_ = 0; i_ < 64; i_++) {
            int i = i_ / 8 + 1;
            int j = i_ % 8 + 1;
            if (((a - b == i - j) || (a + b == i + j)) && ((i - j == c - d) || (i + j == c + d))) {
                cout << 2 << ' ' << char(a + 'A' - 1) << ' ' << b << ' ' << char(i + 'A' - 1) << ' ' << j << ' ';
                cout << char(c + 'A' - 1) << ' ' << d << '\n';
                break;
            }
        }
    }
}