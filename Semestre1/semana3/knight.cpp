#include <bits/stdc++.h>
using namespace std;

int board[8][8] {0};
map<int, pair<int, int>> numsUsed;
pair<int, int> coord;

bool backTrack(int num) {
    if (num == 64) {
        return true;
    }
    numsUsed.emplace(num + 1, make_pair(-1, -1));
    if (numsUsed[num + 1] != make_pair(-1, -1)) {
        coord = numsUsed[num + 1];
        return backTrack(num + 1);
    }
    
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
            if (num != -1) {
                numsUsed[num] = make_pair(i, j);
            } else if (num == 1) {
                coord = make_pair(i, j);
            }
        }
    }
}