#include <bits/stdc++.h>
using namespace std;

int T, N, W, L;
vector<int> occupied;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> W >> L;
        for (int i = 0; i < W; i++) {
            int pos;
            cin >> pos;
            occupied.push_back(pos);
        }
    }
}