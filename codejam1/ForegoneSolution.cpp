#include <bits/stdc++.h>
using namespace std;

int T, N, N1, N2;

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        N1 = 0;
        N2 = 0;
        cin >> N;
        int j = 1;
        while (N) {
            int d = N % 10;
            N /= 10;
            if (d == 4) {
                N1 += 2 * j;
                N2 += 2 * j;
            } else {
                N1 += d * j;
            }
            j *= 10;
        }
        cout << "Case #" << i << ": " << N1  << ' ' << N2 << '\n';
    }
}