#include <bits/stdc++.h>
using namespace std;

int x, a, n, c;

int binpow(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1)
            r = r * a;
        a = a * a;
        n >>= 1;
    }
    return r;
}

int main() {
    while (true) {
        cin >> x >> a >> n >> c;
        if (!x) break;
        int r1 = (x * binpow(a, n % (c - 1)));
        int r2 = binpow(a, (n + 1) % (c - 1)) - a;
        r2 = r2 / (a - 1);
        int r = (r1 - r2) % c;
        if (r > 0) cout << r << '\n';
        else cout << r + c << '\n';
    }
}