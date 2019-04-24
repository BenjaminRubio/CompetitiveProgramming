#include <bits/stdc++.h>
using namespace std;

int C, N;
pair<int, int> cards[401];

int dp() {
    
}

int main() {
    cin >> C >> N;
    for (int i = 0; i < N * C; i++) {
        int c, n;
        cin >> c >> n;
        cards[i] = {c, n};       
    }
}