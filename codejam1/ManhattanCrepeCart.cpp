#include <bits/stdc++.h>
using namespace std;

int T, P, Q, x, y;
char d;
pair<int, int> pos;
int xaxis[100001];
int yaxis[100001];

int main() {
    cin >> T;
    for (int k = 1; k <= T; k++) {
        memset(xaxis, 0, sizeof xaxis);
        memset(yaxis, 0, sizeof yaxis);
        cin >> P >> Q;
        for (int i = 0; i < P; i++) {
            cin >> x >> y >> d;
            if (d == 'N') {
                for (int j = y + 1; j <= Q; j++) {
                    yaxis[j]++;
                }
            }
            if (d == 'S') {
                for (int j = y - 1; j >= 0; j--) {
                    yaxis[j]++;
                }
            }
            if (d == 'E') {
                for (int j = x + 1; j <= Q; j++) {
                    xaxis[j]++;
                }
            }
            if (d == 'W') {
                for (int j = x - 1; j >= 0; j--) {
                    xaxis[j]++;
                }
            }
        }
        pair<int, int> cart_pos = {0, 0};
        int maxx = -1;
        int maxy = -1;
        for (int i = 0; i <= Q; i++) {
            if (xaxis[i] > maxx) {
                maxx = xaxis[i];
                cart_pos.first = i;
            }
            if (yaxis[i] > maxy) {
                maxy = yaxis[i];
                cart_pos.second = i;
            }
        }
        cout << "Case #" << k << ": " << cart_pos.first << ' ' << cart_pos.second << '\n';
    }
}