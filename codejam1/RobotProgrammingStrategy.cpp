#include <bits/stdc++.h>
using namespace std;

int T, A;
vector<string> moves;
vector<vector<int>> masks;
vector<char> winner_moves(500, ' ');
vector<char> all_moves = {'R', 'P', 'S'};

int wins(char a, char b) {
    if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) {
        return 1;
    }
    if ((a == 'S' && b == 'R') || (a == 'R' && b == 'P') || (a == 'P' && b == 'S')) {
        return -1;
    }
    return 0;
}

int WinnerMoves(int i, int l) {
    if (i == A) {
        return 1;
    }
    string opponent_moves = moves[i];
    for (int j = 0; j < l; j++) {
        int w = wins(winner_moves[j % winner_moves.size()], opponent_moves[j % opponent_moves.size()]);
        if (w == 1) {
            return WinnerMoves(i + 1, l);
        } else if (w == -1) {
            return -1;
        }
    }
    if (WinnerMoves(i + 1, l) == -1) return -1;
    return 0;
}

int getWinnerMoves(int l, int m) {
    if (l == m) {
        return WinnerMoves(0, m);
    }
    int mask = 7;
    for (int i = 0; i < A; i++) {
        mask &= masks[i][l % masks[i].size()];
    }
    if (mask == 0) return -1;
    for (int i = 0; i < 3; i++) {
        if ((1 << i) & mask) {
            winner_moves[l] = all_moves[i];
            int next = getWinnerMoves(l + 1, m);
            if (next != -1) return next;
        }
    }
}

int main() {
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cin >> A;
        int m = 0;
        for (int i = 0; i < A; i++) {
            string move;
            cin >> move;
            m = max(m, int(move.size()));
            moves.push_back(move);
            vector<int> this_move;
            for (int j = 0; j < move.size(); j++) {
                for (int m = 0; m < 3; m++)
                    if (move[j] == all_moves[m]) this_move.push_back(7 ^ (1 << ((m + 1) % 3)));
            }
            masks.push_back(this_move);
        }
        int len = getWinnerMoves(0, m);
        if (len != -1) {
            cout << "Case #" << k << ": ";
            for (int i = 0; i < len; i++) cout << winner_moves[i];
            cout << '\n';
        }
        else cout << "Case #" << k << ": IMPOSSIBLE\n";
        moves.clear();
        masks.clear();
    }
}